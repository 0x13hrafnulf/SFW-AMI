force R 1 0ns, 0 50ns;
force S 0 0ns, 1 {100ns} -repeat 200ns;
force clk 1 0ns, 0 {50ns} -repeat 100ns;
force Size 10#1 0ns, 10#2 200ns, 10#3 330ns, 10#4 430ns, 10#8 630ns, 10#15 630ns;
force D 10#1 0ns, 10#3 400ns, 10#7 800ns, 10#15 1200ns, 10#31 1600ns, 10#63 2000ns;