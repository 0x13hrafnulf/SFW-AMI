force R 1 0ns, 0 50ns;
force S 0 0ns, 1 {100ns} -repeat 200ns;
force clk 1 0ns, 0 {50ns} -repeat 100ns;
force ser_input 1 100ns, 0 300ns, 1 500ns, 0 700ns, 1 900ns, 1 1100ns, 0 1300ns, 1 1500ns;