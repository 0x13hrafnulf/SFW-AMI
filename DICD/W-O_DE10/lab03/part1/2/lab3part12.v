`timescale 1 ns/ 10 ps

module lab3part12(Q1, D0, D1, D2, D3, D4, S0, S1, S2);

input S0, S1, S2;
input[3:0] D0, D1, D2, D3, D4;
wire[3:0] Q0;
output[3:0] Q1;

assign Q0 = S1 ? (S0 ? D3 : D2) : (S0 ? D1 : D0);
assign Q1 = S2 ? D4 : Q0;

endmodule
