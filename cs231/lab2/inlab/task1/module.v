module tFlipFlop (
    input clk,
    input t,
    output reg q
);
    always @(posedge clk) begin
	// this code is executed line by line every time
	// the value of 'clk' changes from 0 to 1
	if (t) begin
	    q = !q;
	end
    end
    // Register logic must be written in an always block
    // This block is triggered on the rising edge of the clock
endmodule

module buffer (
    input d,
    output wire q
);
    assign q = d;
    // Combinational logic can be written using assign statements
    // The output changes immediately with the input

endmodule
