
module lab2part1(f1, f2, f3, f4, f5, f6, x, y, z, w);

input x, y, z, w;
output f1, f2, f3, f4, f5, f6;

assign f1 = (x & ~y) | (z & y);
assign f2 = (x & y) | (~x & z & ~y);
assign f3 = ((x | ~y) & z) | (~x & ~z & y);
assign f4 = (x & z) | (z & ~y) | (~x & ~z & y);
assign f5 = (x | ~y | ~z) & (z | ~x) & (y | z);
assign f6 = ~(~(~(x & ~y) & z) | ~(~x | y | ~z) | ~(x | w));

		
endmodule
