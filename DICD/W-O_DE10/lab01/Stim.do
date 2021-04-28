force clr 1 0ns, 0 50ns;
force clk 0 0ns, 1 {50ns} -repeat 100ns;
force ina 10#0 0ns, 10#1 30ns;
force inb 10#0 0ns, 10#1 30ns, 10#3 130ns, 10#4 230ns, 10#5 330ns, 10#6 430ns;

