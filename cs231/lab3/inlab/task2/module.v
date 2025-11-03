module ShiftRows(
    input  [63:0] currentState ,
    output [63:0] nextState    
);
    assign nextState[63:52] = currentState[59:48];
    assign nextState[51:48] = currentState[63:60];
    assign nextState[47:40] = currentState[39:32];
    assign nextState[39:32] = currentState[47:40];
    assign nextState[31:28] = currentState[19:16];
    assign nextState[27:16] = currentState[31:20];
    assign nextState[15:00] = currentState[15:00];

endmodule