#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
LOG_DIR="$ROOT_DIR/demo_logs"

mkdir -p "$LOG_DIR"

SC_LOG="$LOG_DIR/single_cycle_trace.log"
PIPE_LOG="$LOG_DIR/pipeline_trace.log"

echo "== Single-Cycle Demo =="
(cd "$ROOT_DIR" && ./run.sh trace_sc) 2>&1 | tee "$SC_LOG" >/dev/null
grep -E '^\[SC-TRACE\]|^\[PASS\]' "$SC_LOG" | sed -n '1,8p;$p'
echo
echo "== Pipeline Demo =="
(cd "$ROOT_DIR" && ./run.sh trace_pipe) 2>&1 | tee "$PIPE_LOG" >/dev/null
grep -E '^\[PIPE-TRACE\]|^\[PASS\]' "$PIPE_LOG" | sed -n '1,10p;$p'
echo
echo "Full logs saved under: $LOG_DIR"
echo "Waveforms available in: $ROOT_DIR/waveforms"