`timescale 1 ns/ 10 ps

module lab3part25(Q, D0, D1, D2, D3);

input D0, D1, D2, D3;
output[9:0] Q;

assign Q[0] =  ~D3 * ~D2 * ~D1 * ~D0;
assign Q[1] =  ~D3 * ~D2 * ~D1 * D0;	
assign Q[2] =  ~D3 * ~D2 * D1 * ~D0;
assign Q[3] =  ~D3 * ~D2 * D1 * D0;
assign Q[4] =  ~D3 * D2 * ~D1 * ~D0;
assign Q[5] =  ~D3 * D2 * ~D1 * D0;	
assign Q[6] =  ~D3 * D2 * D1 * ~D0;
assign Q[7] =  ~D3 * D2 * D1 * D0;
assign Q[8] =  D3 * ~D2 * ~D1 * ~D0;
assign Q[9] =  D3 * ~D2 * ~D1 * D0;	
endmodule

