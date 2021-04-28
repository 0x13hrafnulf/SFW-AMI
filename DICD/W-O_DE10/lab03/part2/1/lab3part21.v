`timescale 1 ns/ 10 ps

module lab3part21(Q, D0, D1, D2, D3, D4, D5, D6, D7, D8, D9);

input D0, D1, D2, D3, D4, D5, D6, D7, D8, D9;
output[3:0] Q;

assign Q[0] =  D1 + D3 + D5 + D7 + D9;
assign Q[1] =  D2 + D3 + D6 + D7;	
assign Q[2] =  D4 + D5 + D6 + D7;
assign Q[3] =  D8 + D9;
endmodule

