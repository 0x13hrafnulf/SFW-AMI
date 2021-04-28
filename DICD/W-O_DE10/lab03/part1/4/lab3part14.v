`timescale 1 ns/ 10 ps

module lab3part14(D, Q0, Q1, Q2, Q3, S0, S1);

input S0, S1;
output[7:0] Q0, Q1, Q2, Q3;
input[7:0] D;

assign Q0 = ~S0&~S1 ? D : 0;
assign Q1 =  S0&~S1 ? D : 0;
assign Q2 =  ~S0&S1 ? D : 0;
assign Q3 =   S0&S1 ? D : 0;
		
endmodule
