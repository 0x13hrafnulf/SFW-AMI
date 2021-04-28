force CS 0 0ns, 1 100ns, 0 200ns, 1 400ns,0 500ns, 1 700ns, 0 800ns, 1 1000ns, 0 1100ns, 1 1300ns, 0 1400ns, 1 1430ns, 0 1550ns, 1 1600ns, 0 1900ns, 1 2030ns, 0 2130ns;
force WR 0 0ns, 1 100ns, 0 200ns, 1 400ns,0 500ns, 1 700ns, 0 800ns, 1 1000ns, 0 1100ns, 1 1300ns,0 1400ns, 1 1600ns, 0 1700ns;
force clk 1 0ns, 0 {50ns} -repeat 100ns;
force In 10#1 100ns, 10#2 400ns, 10#3 700ns, 10#4 1000ns, 10#5 1300ns, 10#6 1600ns;
force address_in 10#1 100ns, 10#5 400ns, 10#8 700ns, 10#10 1000ns, 10#3 1300ns, 10#2 1600ns;
force address_out 10#5 1430ns, 10#8 1600ns, 10#1 1730ns, 10#1 1900ns, 10#3 2030ns, 10#2 2130ns, 10#10 2530ns; 