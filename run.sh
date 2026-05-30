#!/usr/bin/env bash
set -euo pipefail

MODE="${1:-sc}"

if [[ "$PWD" == *" "* ]] && [[ -z "${RISCV_SAFE_PATH:-}" ]]; then
  SAFE_STAGE="/tmp/riscv_repo_stage"
  rm -rf "$SAFE_STAGE"
  mkdir -p "$SAFE_STAGE"
  rsync -a --delete --exclude obj_dir --exclude '*.vcd' ./ "$SAFE_STAGE"/
  pushd "$SAFE_STAGE" >/dev/null
  RISCV_SAFE_PATH=1 ./run.sh "$MODE"
  exit_code=$?
  popd >/dev/null
  mkdir -p waveforms
  rsync -a "$SAFE_STAGE"/waveforms/ ./waveforms/
  exit "$exit_code"
fi

case "$MODE" in
  sc)
    echo "Running single-cycle Verilator flow"
    make sc
    ;;
  trace_sc)
    echo "Running single-cycle Verilator trace demo"
    rm -rf /tmp/riscv_sc_obj
    make sc >/dev/null
    /tmp/riscv_sc_obj/Vcpu_top --trace-en --max-cycles=80
    ;;
  pipe)
    echo "Running 5-stage pipeline Verilator flow"
    make pipe
    ;;
  trace_pipe)
    echo "Running 5-stage pipeline Verilator trace demo"
    rm -rf /tmp/riscv_pipe_obj
    make pipe >/dev/null
    /tmp/riscv_pipe_obj/Vcpu_pipeline_top --trace-en --max-cycles=120
    ;;
  iverilog_sc)
    echo "Running single-cycle Icarus Verilog flow"
    make iverilog_sc
    ;;
  iverilog_pipe)
    echo "Running pipeline Icarus Verilog flow"
    make iverilog_pipe
    ;;
  lint)
    echo "Running Verilator lint"
    make lint
    ;;
  *)
    echo "Usage: ./run.sh [sc|trace_sc|pipe|trace_pipe|iverilog_sc|iverilog_pipe|lint]"
    exit 1
    ;;
esac