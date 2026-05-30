set dumpfile [lindex $argv 0]
gtkwave::loadFile $dumpfile
gtkwave::addSignalsFromList {cpu_tb.dut.current_pc cpu_tb.dut.current_instruction cpu_tb.dut.debug_reg_data cpu_tb.dut.cycle_count}