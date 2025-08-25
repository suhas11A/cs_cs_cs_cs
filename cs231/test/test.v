`timescale 1ns/1ps

module test;
    reg a,b;
    wire out;
    and_gate and1(.out(out),.in1(a),.in2(b));

    initial begin
        $dumpfile("and_gate_dump.vcd");
        $dumpvars(0,test);
        $monitor("At time %t: a = %b, b = %b, y = %b", $time, a, b, out);
        a = 0; b = 0; #10;
        a = 0; b = 1; #10;
        a = 1; b = 0; #10;
        a = 1; b = 1; #10;
        $finish;
    end
endmodule