module part4 (SW, HEX0);
	input [9:0] SW;
	output [0:6] HEX0;

	assign C1 = SW[1];
	assign C0 = SW[0];

	assign HEX0[0] = ~C0;
	assign HEX0[1] = ~(C1 | ~C0);
	assign HEX0[2] = ~(C1 | ~C0);
	assign HEX0[3] = ~(~C1 | C0);
	assign HEX0[4] = ~(~C1 | C0);
	assign HEX0[5] = ~C0;
	assign HEX0[6] = C1;
	
endmodule