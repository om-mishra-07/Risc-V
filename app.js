const LOG_PATHS = {
  sc: "../demo_logs/single_cycle_trace.log",
  pipe: "../demo_logs/pipeline_trace.log",
};

const state = {
  rowLimit: 120,
  sc: null,
  pipe: null,
};

const refreshBtn = document.getElementById("refresh-btn");
const statusEl = document.getElementById("status");
const rowLimitInput = document.getElementById("row-limit");
const rowLimitValue = document.getElementById("row-limit-value");

rowLimitInput.addEventListener("input", () => {
  state.rowLimit = Number(rowLimitInput.value);
  rowLimitValue.textContent = String(state.rowLimit);
  if (state.sc && state.pipe) {
    renderAll();
  }
});

refreshBtn.addEventListener("click", loadLogs);

function parseNumber(value) {
  return Number.parseInt(value, 10);
}

function parseHex(value) {
  return Number.parseInt(value, 16);
}

function parseSc(text) {
  const lines = text.split(/\r?\n/);
  const trace = [];
  let pass = null;

  const traceRegex = /^\[SC-TRACE\] pc=(0x[0-9a-f]+) instr=(0x[0-9a-f]+) rd=x(\d+) wb=(0x[0-9a-f]+) branch=(\d) target=(0x[0-9a-f]+) z=(\d) n=(\d) ov=(\d)$/i;
  const passRegex = /^\[PASS\].*x11=(\d+) mem\[0x100\]=(\d+) cycles=(\d+)/i;

  for (const rawLine of lines) {
    const line = rawLine.trim();
    const tm = line.match(traceRegex);
    if (tm) {
      trace.push({
        pcHex: tm[1],
        pc: parseHex(tm[1]),
        instrHex: tm[2],
        rd: `x${tm[3]}`,
        wbHex: tm[4],
        wb: parseHex(tm[4]),
        branch: tm[5] === "1",
        targetHex: tm[6],
        z: tm[7] === "1",
        n: tm[8] === "1",
        ov: tm[9] === "1",
      });
      continue;
    }

    const pm = line.match(passRegex);
    if (pm) {
      pass = {
        x11: parseNumber(pm[1]),
        mem100: parseNumber(pm[2]),
        cycles: parseNumber(pm[3]),
      };
    }
  }

  return { mode: "single-cycle", trace, pass };
}

function parsePipe(text) {
  const lines = text.split(/\r?\n/);
  const trace = [];
  let pass = null;

  const traceRegex = /^\[PIPE-TRACE\] pc=(0x[0-9a-f]+) rd=x(\d+) wb=(0x[0-9a-f]+) stall=(\d) flush=(\d) z=(\d) n=(\d) ov=(\d)$/i;
  const passRegex = /^\[PASS\].*x11=(\d+) mem\[0x100\]=(\d+) cycles=(\d+) stalls=(\d+) flushes=(\d+)/i;

  for (const rawLine of lines) {
    const line = rawLine.trim();
    const tm = line.match(traceRegex);
    if (tm) {
      trace.push({
        pcHex: tm[1],
        pc: parseHex(tm[1]),
        rd: `x${tm[2]}`,
        wbHex: tm[3],
        wb: parseHex(tm[3]),
        stall: tm[4] === "1",
        flush: tm[5] === "1",
        z: tm[6] === "1",
        n: tm[7] === "1",
        ov: tm[8] === "1",
      });
      continue;
    }

    const pm = line.match(passRegex);
    if (pm) {
      pass = {
        x11: parseNumber(pm[1]),
        mem100: parseNumber(pm[2]),
        cycles: parseNumber(pm[3]),
        stalls: parseNumber(pm[4]),
        flushes: parseNumber(pm[5]),
      };
    }
  }

  return { mode: "pipeline", trace, pass };
}

async function fetchLog(path) {
  const response = await fetch(path, { cache: "no-store" });
  if (!response.ok) {
    throw new Error(`Failed to fetch ${path}: HTTP ${response.status}`);
  }
  return response.text();
}

async function loadLogs() {
  setStatus("Loading logs...");

  try {
    const [scText, pipeText] = await Promise.all([
      fetchLog(LOG_PATHS.sc),
      fetchLog(LOG_PATHS.pipe),
    ]);

    state.sc = parseSc(scText);
    state.pipe = parsePipe(pipeText);

    if (!state.sc.trace.length || !state.pipe.trace.length) {
      throw new Error("Trace lines were not found in one or more log files.");
    }

    renderAll();
    setStatus(
      `Loaded ${state.sc.trace.length} SC rows and ${state.pipe.trace.length} pipeline rows.`
    );
  } catch (error) {
    console.error(error);
    setStatus(
      "Could not load logs. Run ./demo.sh first, then serve from riscv root (python3 -m http.server)."
    );
  }
}

function setStatus(message) {
  statusEl.textContent = message;
}

function ratio(part, whole) {
  if (!whole) {
    return "0.00";
  }
  return (part / whole).toFixed(2);
}

function safeDiv(numerator, denominator) {
  if (!denominator) {
    return "n/a";
  }
  return (numerator / denominator).toFixed(2);
}

function classifyOpcode(instrHex) {
  if (!instrHex) {
    return "other";
  }

  const instr = parseHex(instrHex);
  const opcode = instr & 0x7f;

  if (opcode === 0x03 || opcode === 0x23) {
    return "load/store";
  }

  if (opcode === 0x63 || opcode === 0x6f || opcode === 0x67) {
    return "branch/jump";
  }

  if (opcode === 0x33 || opcode === 0x13 || opcode === 0x17 || opcode === 0x37) {
    return "alu";
  }

  return "other";
}

function renderKpis() {
  const kpis = [];
  const sc = state.sc;
  const pipe = state.pipe;

  const scBranches = sc.trace.filter((r) => r.branch).length;
  const pipeFlushes = pipe.trace.filter((r) => r.flush).length;
  const pipeStalls = pipe.trace.filter((r) => r.stall).length;
  const scRetired = sc.trace.length;
  const pipeRetired = pipe.trace.length;
  const scCycles = sc.pass?.cycles ?? 0;
  const pipeCycles = pipe.pass?.cycles ?? 0;

  kpis.push({ label: "SC cycles", value: sc.pass?.cycles ?? "n/a" });
  kpis.push({ label: "PIPE cycles", value: pipe.pass?.cycles ?? "n/a" });
  kpis.push({ label: "Cycle delta", value: pipeCycles - scCycles });
  kpis.push({ label: "SC CPI", value: safeDiv(scCycles, scRetired) });
  kpis.push({ label: "PIPE CPI", value: safeDiv(pipeCycles, pipeRetired) });
  kpis.push({ label: "SC IPC", value: safeDiv(scRetired, scCycles) });
  kpis.push({ label: "PIPE IPC", value: safeDiv(pipeRetired, pipeCycles) });
  kpis.push({ label: "SC taken branch rate", value: ratio(scBranches, sc.trace.length) });
  kpis.push({ label: "PIPE flush rate", value: ratio(pipeFlushes, pipe.trace.length) });
  kpis.push({ label: "PIPE stall rate", value: ratio(pipeStalls, pipe.trace.length) });
  kpis.push({ label: "Result x11", value: pipe.pass?.x11 ?? sc.pass?.x11 ?? "n/a" });
  kpis.push({ label: "Result mem[0x100]", value: pipe.pass?.mem100 ?? sc.pass?.mem100 ?? "n/a" });

  const root = document.getElementById("kpis");
  root.innerHTML = "";

  for (const metric of kpis) {
    const card = document.createElement("div");
    card.className = "kpi";
    card.innerHTML = `<h3>${metric.label}</h3><p>${metric.value}</p>`;
    root.appendChild(card);
  }
}

function renderPcChart() {
  const maxPoints = Math.min(state.rowLimit, state.sc.trace.length, state.pipe.trace.length);
  const scPoints = state.sc.trace.slice(0, maxPoints);
  const pipePoints = state.pipe.trace.slice(0, maxPoints);

  const allPc = [...scPoints.map((x) => x.pc), ...pipePoints.map((x) => x.pc)];
  const minPc = Math.min(...allPc);
  const maxPc = Math.max(...allPc);
  const width = 760;
  const height = 200;
  const pad = 24;

  const xScale = (index) => pad + (index / Math.max(1, maxPoints - 1)) * (width - pad * 2);
  const yScale = (pc) => {
    if (maxPc === minPc) {
      return height / 2;
    }
    return height - pad - ((pc - minPc) / (maxPc - minPc)) * (height - pad * 2);
  };

  const scPath = scPoints
    .map((p, i) => `${i === 0 ? "M" : "L"}${xScale(i)},${yScale(p.pc)}`)
    .join(" ");
  const pipePath = pipePoints
    .map((p, i) => `${i === 0 ? "M" : "L"}${xScale(i)},${yScale(p.pc)}`)
    .join(" ");

  const svg = `
    <svg viewBox="0 0 ${width} ${height}" class="pc-line" role="img" aria-label="Program counter timeline">
      <text x="${pad}" y="14" class="axis-label">PC progression (orange=SC, teal=PIPE)</text>
      <path d="${scPath}" class="pc-path" opacity="0.85"></path>
      <path d="${pipePath}" class="pc-path" stroke="var(--accent)" opacity="0.9"></path>
    </svg>`;

  document.getElementById("pc-chart").innerHTML = svg;
}

function aggregateRegisters(rows) {
  const map = new Map();
  for (const row of rows) {
    if (row.rd === "x0") {
      continue;
    }
    map.set(row.rd, (map.get(row.rd) ?? 0) + 1);
  }
  return Array.from(map.entries())
    .map(([register, count]) => ({ register, count }))
    .sort((a, b) => b.count - a.count)
    .slice(0, 10);
}

function renderRegisterBars() {
  const rows = [
    ...state.sc.trace.slice(0, state.rowLimit),
    ...state.pipe.trace.slice(0, state.rowLimit),
  ];
  const leaderboard = aggregateRegisters(rows);
  const max = leaderboard.length ? leaderboard[0].count : 1;

  const root = document.getElementById("register-bars");
  root.innerHTML = "";

  for (const row of leaderboard) {
    const line = document.createElement("div");
    line.className = "bar-row";
    const widthPct = (row.count / max) * 100;
    line.innerHTML = `
      <span>${row.register}</span>
      <span><span class="bar-fill" style="display:block;width:${widthPct}%"></span></span>
      <span>${row.count}</span>
    `;
    root.appendChild(line);
  }
}

function aggregateInstructionMix(rows, instructionResolver) {
  const counters = {
    alu: 0,
    "load/store": 0,
    "branch/jump": 0,
    other: 0,
  };

  for (const row of rows) {
    const instrHex = instructionResolver(row);
    const category = classifyOpcode(instrHex);
    counters[category] += 1;
  }

  return Object.entries(counters)
    .map(([category, count]) => ({ category, count }))
    .sort((a, b) => b.count - a.count);
}

function renderMixBars(rootId, items) {
  const max = items.length ? Math.max(...items.map((x) => x.count)) : 1;
  const root = document.getElementById(rootId);
  root.innerHTML = "";

  const labelMap = {
    alu: "ALU",
    "load/store": "Load/Store",
    "branch/jump": "Branch/Jump",
    other: "Other",
  };

  for (const item of items) {
    const widthPct = max ? (item.count / max) * 100 : 0;
    const displayLabel = labelMap[item.category] ?? item.category;
    const fillStyle = item.count === 0 ? "width:0%" : `width:${widthPct}%`;
    const row = document.createElement("div");
    row.className = "mix-row";
    row.innerHTML = `
      <span class="mix-label">${displayLabel}</span>
      <span class="bar-track"><span class="bar-fill bar-fill--mix" style="display:block;${fillStyle}"></span></span>
      <span class="${item.count === 0 ? "bar-zero" : ""}">${item.count}</span>
    `;
    root.appendChild(row);
  }
}

function renderInstructionMix() {
  const scRows = state.sc.trace.slice(0, state.rowLimit);
  const pipeRows = state.pipe.trace.slice(0, state.rowLimit);

  const instrByPc = new Map();
  for (const row of state.sc.trace) {
    if (!instrByPc.has(row.pcHex)) {
      instrByPc.set(row.pcHex, row.instrHex);
    }
  }

  const scMix = aggregateInstructionMix(scRows, (row) => row.instrHex);
  const pipeMix = aggregateInstructionMix(pipeRows, (row) => instrByPc.get(row.pcHex));

  renderMixBars("sc-mix", scMix);
  renderMixBars("pipe-mix", pipeMix);
}

function renderTable(rootId, rows, columns) {
  const root = document.getElementById(rootId);
  root.innerHTML = "";

  for (const [idx, row] of rows.slice(-state.rowLimit).entries()) {
    const tr = document.createElement("tr");
    const cells = [String(idx + 1), ...columns.map((col) => col(row))];
    tr.innerHTML = cells
      .map((cell) => {
        if (cell === "yes") {
          return '<td class="badge-yes">yes</td>';
        }
        if (cell === "no") {
          return '<td class="badge-no">no</td>';
        }
        return `<td>${cell}</td>`;
      })
      .join("");
    root.appendChild(tr);
  }
}

function renderTraceTables() {
  renderTable("sc-trace", state.sc.trace, [
    (r) => r.pcHex,
    (r) => r.rd,
    (r) => r.wbHex,
    (r) => (r.branch ? "yes" : "no"),
  ]);

  renderTable("pipe-trace", state.pipe.trace, [
    (r) => r.pcHex,
    (r) => r.rd,
    (r) => r.wbHex,
    (r) => (r.stall ? "yes" : "no"),
    (r) => (r.flush ? "yes" : "no"),
  ]);
}

function renderAll() {
  renderKpis();
  renderPcChart();
  renderRegisterBars();
  renderInstructionMix();
  renderTraceTables();
}

loadLogs();
