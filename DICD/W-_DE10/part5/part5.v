module part5 (SW, HEX0, HEX1, HEX2, HEX3);
	input [9:0] SW;
	output [0:6] HEX0;
	output [0:6] HEX1;
	output [0:6] HEX2;
	output [0:6] HEX3;

	wire [1:0] Q;

	mux (SW[9:8], SW[7:6], SW[5:4], SW[3:2], SW[1:0], Q);
	
	char_7seg0 H0 (Q, HEX3);
	char_7seg1 H1 (Q, HEX2);
	char_7seg2 H2 (Q, HEX1);
	char_7seg3 H3 (Q, HEX0);
	
endmodule

module mux (A, D0, D1, D2, D3, Q);
	
	input [1:0] A, D0, D1, D2, D3;
	output [1:0] Q;
	
//	assign R0 = (~A[0] & (D0[0]&D0[1])) | (A[0] & (D1[0]&D1[1]));
//	assign R1 = (~A[0] & (D2[0]&D2[1])) | (A[0] & (D3[0]&D3[1]));
//	
//	assign Q[0] = (~A[1] & R0) | (A[1] & R1);
//	assign Q[1] = (~A[1] & R0) | (A[1] & R1);
	
	assign Q = (D0 & (~A[1] & ~A[0])) | (D1 & (~A[1] & A[0])) | (D2 & (A[1] & ~A[0])) | (D3 & (A[1] & A[0]));
	
	
endmodule

module char_7seg0 (Res, Display);
	
	input [1:0] Res;
	output [0:6] Display;
	
	assign C1 = Res[1];
	assign C0 = Res[0];
	
	assign Display[0] = ~C0;
	assign Display[1] = ~(C1 | ~C0);
	assign Display[2] = ~(C1 | ~C0);
	assign Display[3] = ~(~C1 | C0);
	assign Display[4] = ~(~C1 | C0);
	assign Display[5] = ~C0;
	assign Display[6] = C1;
	
endmodule

module char_7seg1 (Res, Display);
	
	input [1:0] Res;
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
	
	input [1:0] Res;
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
	
	input [1:0] Res;
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