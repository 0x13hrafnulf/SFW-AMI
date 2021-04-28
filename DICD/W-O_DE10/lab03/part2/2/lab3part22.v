`timescale 1 ns/ 10 ps

module lab3part22(Q, D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15);

input D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15;
output[3:0] Q;

assign Q[0] =  D1 + D3 + D5 + D7 + D9 + D11 + D13 + D15;
assign Q[1] =  D2 + D3 + D6 + D7 + D10 + D11 + D14 + D15;	
assign Q[2] =  D4 + D5 + D6 + D7 + D12 + D13 + D14 + D15 ;
assign Q[3] =  D8 + D9 + D10 + D11 + D12 + D13 + D14 + D15;
endmodule

