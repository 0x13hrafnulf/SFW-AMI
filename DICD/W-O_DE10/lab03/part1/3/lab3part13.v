`timescale 1 ns/ 10 ps

module lab3part13(Q, D0, D1, D2, D3, D4, D5, D6, D7, S0, S1, S2, EN);

input S0, S1, S2;
input D0, D1, D2, D3, D4, D5, D6, D7;
input EN;
output Q;

assign Q = EN & ((D0&~S0&~S1&~S2) | (D1&S0&~S1&~S2) | (D2&~S0&S1&~S2) | (D3&S0&S1&~S2) 
         | (D4&~S0&~S1&S2) | (D5&S0&~S1&S2) | (D6&~S0&S1&S2) | (D7&S0&S1&S2));


endmodule
