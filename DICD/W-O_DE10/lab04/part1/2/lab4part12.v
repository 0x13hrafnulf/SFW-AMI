`timescale 1 ns/ 10 ps

module lab4part12(clk, R, S, D, O);
input clk, R, S;
input[15:0] D;
reg[15:0] Q;
output reg O;

always @ (posedge clk) begin 
	if (R) 
		 Q <= 15'b0;
	else
	begin
		if(S)
		begin
			O <= Q[0];
			Q <= Q >> 1;
		end
		else
        	Q <= D;
	end
end 

endmodule

