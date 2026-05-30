# RV32M MUL smoke test
# Computes 5*11 => x11 = 55, stores to mem[0x100], then signals done via x31.

  addi x1, x0, 5
  addi x2, x0, 11
  mul  x11, x1, x2     # 55
  addi x6, x0, 256
  sw   x11, 0(x6)

  addi x31, x0, 1
