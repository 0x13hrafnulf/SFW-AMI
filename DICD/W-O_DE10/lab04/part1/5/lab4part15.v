`timescale 1 ns/ 10 ps

module lab4part15(clk, RST,R, W, In, Out, full, empty);
input clk, R, W, RST;
input[7:0] In;
output reg[7:0] Out;
output full, empty;
reg[7:0] FIFO[0:7];
reg[3:0] read_c = 0, write_c = 0;
reg[3:0] count = 0;

assign empty = (count == 0) ? 1 : 0;
assign full = (count == 8) ? 1 : 0;

always @ (posedge clk) begin 
	if(RST)
	begin
		read_c = 0; 
		write_c = 0;
		count = 0;
	end
	else if(R && count != 0)
	begin
		Out <= FIFO[read_c];
		read_c = read_c + 1;
		count = count - 1;
	end
	else if(W && count < 8)	
	begin
		FIFO[write_c] <= In;
		write_c = write_c + 1;
		count = count + 1;
	end
	else;
	if(write_c == 8)
		write_c = 0;
	if(read_c == 8)
		read_c = 0;	
end 

endmodule

