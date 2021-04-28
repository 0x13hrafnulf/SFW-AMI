module part3 (SW, LEDR);
	input [9:0] SW;
	output [9:0] LEDR;
	
	input [1:0] D0;
	input [1:0] D1;
	input [1:0] D2;
	input [1:0] D3;
	
	assign LEDR[9] = SW[9];
	assign LEDR[8] = SW[8];
	
	assign LEDR[4] = 0;
	assign LEDR[5] = 0;
	assign LEDR[6] = 0;
	assign LEDR[7] = 0;
	
	assign D0[1:0] = SW[1:0];
	assign D1[1:0] = SW[3:2];
	assign D2[1:0] = SW[5:4];
	assign D3[1:0] = SW[7:6];
	
	assign R0 = (~SW[9] & D0) | (SW[9] & D1);
	assign R1 = (~SW[9] & D2) | (SW[9] & D3);
	
	assign LEDR[1:0] = (~SW[8] & R0) | (SW[8] & R1);
	
endmodule