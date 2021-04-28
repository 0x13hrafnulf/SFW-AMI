`timescale 1 ns/ 10 ps

module lab4part11(clk, R, S, D, Q);
input clk, R, S;
input[7:0] D;
output reg [7:0] Q;

always @ (posedge clk) begin 
	if (R) 
		 Q <= 8'b0;
	else
	begin
        	if(S) 
		  		Q <= D;
       	 	else
            	Q <= Q;
	end
end 


endmodule

