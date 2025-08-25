module shiftReg1 (
    input clk,
    input rst,
    input din,
    output [3:0] q
);
    wire [3:0] shiftReg;  

    assign q = shiftReg;

    always @(posedge clk) begin
        if (rst)
            shiftReg <= 4'b0000;
        else
            shiftReg <= {shiftReg[2:0], din};
    end
endmodule

module shiftReg2 (
    input clk,  
    input rst,
    input din,
    output [3:0] q
);
    reg [3:0] shiftReg;

    assign q = shiftReg;

    always @(posedge clk) begin
        if (rst)
            shiftReg <= 4'b0000;
        else
            shiftReg <= {din, shiftReg[3:1]};
    end
endmodule

module shiftReg3 (
    input clk,
    input rst,
    input din,
    output [3:0] q
);
    reg [3:0] shiftReg;

    assign q = shiftReg;

    assign shiftReg = rst ? 4'b0000 : {shiftReg[2:0], din};  
endmodule

module shiftReg4 (
    input clk,
    input rst,
    input din,
    output [3:0] q
);
    reg [3:0] shiftReg;

    assign q = shiftReg;

    always @(posedge clk) begin
        if (rst == 1'b1) begin
            shiftReg <= 4'b0000;
        end
        shiftReg <= {shiftReg[2:0], din}; 
    end
endmodule

module shiftReg (
    input clk,
    input rst,
    input din,
    output [3:0] q
);
    reg [3:0] shiftReg;
    assign q = shiftReg;

    always @(posedge clk) begin
        if (rst) begin
            shiftReg <= 4'b0000;
        end else begin 
            shiftReg <= {shiftReg[2:0], din};
        end
    end

    // fill in correct implementation here

endmodule

