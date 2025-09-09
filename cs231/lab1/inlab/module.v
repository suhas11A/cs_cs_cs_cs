module subtractor (
    input[1:0] a, // a[0] has lower bit, a[1] has upper bit
    input[1:0] b, // b[0] has lower bit, b[1] has upper bit
    output[1:0] sub // sub[0] has lower bit, sub[1] has upper bit
);
	assign sub[1] = (a[1] & a[0] & ~b[1]) | (a[1] & ~a[0] & ~b[1] & ~b[0]);
	assign sub[0] = a[0] ^ b[0];
    // Fill in the logic for the 2 bit subtractor
    // Use gate level syntax, don't directly do sub = a - b
endmodule
