module part6 (SW, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5);
	input [9:0] SW;
	output [0:6] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5;
	reg[17:0] D;
	wire [2:0] Q;

	always @(D) begin
	D = 18'b000_000_000_000_000_000;
	end
	
	
	mux (SW[9:7], D, Q);
	
	char_7seg0 H0 (Q, HEX5);
	char_7seg1 H1 (Q, HEX4);
	char_7seg2 H2 (Q, HEX3);
	char_7seg3 H3 (Q, HEX2);
	char_7seg4 H4 (Q, HEX1);
	char_7seg5 H5 (Q, HEX0);
	
endmodule

module mux (A, D, Q);
	
	input [2:0] A;
	input [17:0] D;
	output [2:0] Q;
	
	assign Q = (D[17:15] & (~A[2] & ~A[1] & ~A[0])) | (D[14:12] & (~A[2] & ~A[1] & A[0])) | (D[11:9] & (~A[2] & A[1] & ~A[0])) | (D[8:6] & (~A[2] & A[1] & A[0])) | (D[5:3] & (A[2] & ~A[1] & ~A[0])) | (D[2:0] & (A[2] & ~A[1] & A[0]))
	
	
endmodule

module char_7seg0 (Res, Display);
	
	input [2:0] Res;
	output [0:6] Display;
	
	assign C2 = Res[2];
	assign C1 = Res[1];
	assign C0 = Res[0];

	
	assign Display[0] = C2 | C1;
	assign Display[1] = C2^C1^C0;
	assign Display[2] = ~(C1 | ~C0);
	assign Display[3] = ~(~C1 | C0);
	assign Display[4] = ~(~C1 | C0);
	assign Display[5] = ~C0;
	assign Display[6] = C1;
	
endmodule

module char_7seg1 (Res, Display);
	
	input [2:0] Res;
	output [0:6] Display;
	
	assign C1 = Res[1];
	assign C0 = Res[0];
	
	assign Display[0] = C0;
	assign Display[1] = ~(C1 | C0);
	assign Display[2] = ~(C1 | C0);
	assign Display[3] = ~(C1 | ~C0);
	assign Display[4] = ~(C1 | ~C0);
	assign Display[5] = C0;
	assign Display[6] = C1^C0;
	
endmodule

module char_7seg2 (Res, Display);
	
	input [2:0] Res;
	output [0:6] Display;
	
	assign C1 = Res[1];
	assign C0 = Res[0];
	
	assign Display[0] = ~C0;
	assign Display[1] = C1 & C0;
	assign Display[2] = C1 & C0;
	assign Display[3] = ~(C1 | C0);
	assign Display[4] = ~(C1 | C0);
	assign Display[5] = ~C0;
	assign Display[6] = ~C1;
	
endmodule

module char_7seg3 (Res, Display);
	
	input [2:0] Res;
	output [0:6] Display;
	
	assign C1 = Res[1];
	assign C0 = Res[0];
	
	assign Display[0] = C0;
	assign Display[1] = C1 & ~C0;
	assign Display[2] = C1 & ~C0;
	assign Display[3] = C1 & C0;
	assign Display[4] = C1 & C0;
	assign Display[5] = C0;
	assign Display[6] = C1 ^~ C0;
	
endmodule

module char_7seg4 (Res, Display);
	
	input [2:0] Res;
	output [0:6] Display;
	
	assign C1 = Res[1];
	assign C0 = Res[0];
	
	assign Display[0] = C0;
	assign Display[1] = C1 & ~C0;
	assign Display[2] = C1 & ~C0;
	assign Display[3] = C1 & C0;
	assign Display[4] = C1 & C0;
	assign Display[5] = C0;
	assign Display[6] = C1 ^~ C0;
	
endmodule

module char_7seg5 (Res, Display);
	
	input [2:0] Res;
	output [0:6] Display;
	
	assign C1 = Res[1];
	assign C0 = Res[0];
	
	assign Display[0] = C0;
	assign Display[1] = C1 & ~C0;
	assign Display[2] = C1 & ~C0;
	assign Display[3] = C1 & C0;
	assign Display[4] = C1 & C0;
	assign Display[5] = C0;
	assign Display[6] = C1 ^~ C0;
	
endmodule