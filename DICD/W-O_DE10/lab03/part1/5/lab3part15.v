`timescale 1 ns/ 10 ps

module lab3part15(D, Q0, Q1, Q2, Q3, Q4, S0, S1, S2);

input S0, S1, S2;
output[3:0] Q0, Q1, Q2, Q3, Q4;
input[3:0] D;


assign Q0 = ~S2&~S0&~S1 ? D : 0;
assign Q1 =  ~S2&S0&~S1 ? D : 0;
assign Q2 =  ~S2&~S0&S1 ? D : 0;
assign Q3 =   ~S2&S0&S1 ? D : 0;
assign Q4 =          S2 ? D : 0;

endmodule
