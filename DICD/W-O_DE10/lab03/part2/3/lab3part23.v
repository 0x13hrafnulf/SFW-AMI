`timescale 1 ns/ 10 ps

module lab3part23(Q, D4, D3, D2, D1, D0, DN1, DN2, DN3, DN4, DN5);

input D4, D3, D2, D1, D0, DN1, DN2, DN3, DN4, DN5;
output[3:0] Q;

assign Q[0] = D3 + D1 + DN1 + DN3 + DN5;
assign Q[1] = D3 + D2 + +DN1 + DN2 + DN5;	
assign Q[2] = D4 + DN1 + DN2 + DN3 + DN4 ;
assign Q[3] = DN1 + DN2 + DN3 + DN4 + DN5;
endmodule

