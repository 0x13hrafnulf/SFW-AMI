`timescale 1 ns/ 10 ps

module lab4part23(clk, RST, Q);
input clk, RST;
output reg[3:0] Q;


always @ (posedge clk) begin
	if(RST)
		Q <= 4'b0;
	else
	begin
		Q <= {Q[2:0], ~Q[3]};
	end
end 

endmodule

