`timescale 1 ns/ 10 ps

module lab3part16(D, Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, S0, S1, S2, EN);

input S0, S1, S2;
output Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7;
input EN;
input D;


assign Q0 = EN&~S2&~S0&~S1 ? D : 0;
assign Q1 =  EN&~S2&S0&~S1 ? D : 0;
assign Q2 =  EN&~S2&~S0&S1 ? D : 0;
assign Q3 =   EN&~S2&S0&S1 ? D : 0;
assign Q4 =  EN&S2&~S0&~S1 ? D : 0;
assign Q5 =   EN&S2&S0&~S1 ? D : 0;
assign Q6 =   EN&S2&~S0&S1 ? D : 0;
assign Q7 =    EN&S2&S0&S1 ? D : 0;




endmodule
