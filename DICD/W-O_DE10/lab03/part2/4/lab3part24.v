`timescale 1 ns/ 10 ps

module lab3part24(Q, D0, D1, D2, D3);

input D0, D1, D2, D3;
output[15:0] Q;

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
assign Q[10] = D3 * ~D2 * D1 * ~D0;
assign Q[11] = D3 * ~D2 * D1 * D0;
assign Q[12] = D3 * D2 * ~D1 * ~D0;
assign Q[13] = D3 * D2 * ~D1 * D0;	
assign Q[14] = D3 * D2 * D1 * ~D0;
assign Q[15] = D3 * D2 * D1 * D0;
endmodule

