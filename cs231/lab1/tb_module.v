`timescale 1ns / 1ps

module subtractor_tb;

    reg  [1:0] a;
    reg  [1:0] b;
    wire [1:0] sub;

    // Instantiate the subtractor module
    subtractor uut (
        .a(a),
        .b(b),
        .sub(sub)
    );

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0,subtractor_tb);
        $display("Time\t a\t b\t sub");
        $monitor("%0dns\t %b\t %b\t %b", $time, a, b, sub);

        // Test all 2-bit input combinations
        a = 2'b00; b = 2'b00; #10;

        a = 2'b01; b = 2'b00; #10;
        a = 2'b01; b = 2'b01; #10;

        a = 2'b10; b = 2'b00; #10;
        a = 2'b10; b = 2'b01; #10;
        a = 2'b10; b = 2'b10; #10;

        a = 2'b11; b = 2'b00; #10;
        a = 2'b11; b = 2'b01; #10;
        a = 2'b11; b = 2'b10; #10;
        a = 2'b11; b = 2'b11; #10;

        $finish;
    end
endmodule
