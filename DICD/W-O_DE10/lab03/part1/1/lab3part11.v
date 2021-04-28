`timescale 1 ns/ 10 ps

module lab3part11(Q, D0, D1, D2, D3, S0, S1);

input S0, S1;
input[7:0] D0, D1, D2, D3;
output[7:0] Q;

assign Q = S1 ? (S0 ? D3 : D2) : (S0 ? D1 : D0);
		
endmodule
