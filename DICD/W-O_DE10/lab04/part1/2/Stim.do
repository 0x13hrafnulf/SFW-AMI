force R 1 0ns, 0 50ns;
force S 0 0ns, 1 {100ns} -repeat 200ns;
force clk 1 0ns, 0 {50ns} -repeat 100ns;
force D 10#1 0ns, 10#2 30ns, 10#2 130ns, 10#4 230ns, 10#8 330ns, 10#16 430ns;
