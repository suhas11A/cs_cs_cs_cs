//tb.v
`timescale 1ns/1ns

module tb;
    reg a, b;
    wire y;

    // Instantiate and_gate

    // way 1:
    and_gate uut1 (
        .in1(a),
        .in2(b),
        .out(y)
    );

    // way 2:
    // and_gate uut2 (a, b, y);

    initial begin
        $monitor("At time %0t: a = %b, b = %b, y = %b", $time, a, b, y);
    end

    initial begin
        // Dump waveform to file
        $dumpfile("wave.vcd");
        $dumpvars(0, tb);

        // Test all input combinations

        a = 0; b = 0; #10;
        // $display("Value of output = %b", y);

        a = 0; b = 1; #10;
        // $display("Value of output = %b", y);

        a = 1; b = 0; #10;
        // $display("Value of output = %b", y);

        a = 1; b = 1; #10;
        // $display("Value of output = %b", y);

        $finish;
    end

endmodule