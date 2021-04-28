`timescale 1 ns/ 10 ps

module lab4part24(clk, RST, G);
input clk, RST;
output [2:0] G;
reg[2:0] Q;


always @ (posedge clk) begin
	if(RST)
		Q <= 3'b0;
	else
		Q <= Q + 1;	
end 
assign G = {Q[2], Q[2]^Q[1], Q[1]^Q[0]};

endmodule

