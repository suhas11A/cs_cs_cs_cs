module Encrypt(
    input [63:0]  plaintext  ,
    input [63:0]  secretKey  ,
    output [63:0] ciphertext 
);
    wire [63:0] state [0:10];
    wire [63:0] key [0:10];
    assign key[0] = secretKey;
    AddRoundKey s (plaintext, key[0], state[0]);
    genvar i;
    generate
        for (i = 0; i < 10; i = i + 1) begin
            NextKey keygen (key[i], key[i+1]);
            Round r (state[i], key[i+1], state[i+1]);
        end
    endgenerate
    assign ciphertext = state[10];
endmodule

module Round(
    input  [63:0] currentState ,
    input  [63:0] roundKey     ,
    output [63:0] nextState    
);  
    wire [63:0] s0;
    wire [63:0] s1;
    genvar i;
    generate
        for (i = 0; i < 16; i = i + 1) begin
            SBox s(currentState[4*i+3 : 4*i], s0[4*i+3 : 4*i]);
        end
    endgenerate
    ShiftRows ss(s0, s1);
    AddRoundKey sss(s1, roundKey, nextState);

endmodule

module SBox(
    input [3:0]in ,
    output [3:0]out
);
    assign out[3] = (~in[3] & ~in[2] & ~in[1] & in[0]) | (~in[3] & in[2] & ~in[0]) | (in[2] & in[1] & in[0]) | (in[2] & in[3] & in[0]) | (in[3] & ~in[2] & in[1] & in[0]) | (in[3] & ~in[2] & ~in[1] & ~in[0]);
    assign out[2] = (~in[3] & ~in[1] & ~in[0]) | (~in[2] & in[1] & in[0]) | (~in[3] & in[2] & ~in[0]) | (in[2] & in[3] & ~in[1]) | (in[3] & ~in[2] & in[1]);
    assign out[1] = (~in[3] & ~in[2] & ~in[1]) | (in[3] & ~in[2] & ~in[0]) | (~in[3] & in[2] & in[1] & ~in[0]) | (~in[1] & in[0]);
    assign out[0] = (in[2] & ~in[1] & ~in[0]) | (~in[3] & ~in[1] & in[0]) | (in[3] & in[2] & in[1]) | (in[3] & in[1] & ~in[0]) | (in[2] & in[1] & ~in[0]);
endmodule



module NextKey(
    input  [63:0] currentKey,
    output [63:0] nextKey
);
    assign nextKey[63:0] = {currentKey[59:0], currentKey[63:60]};

endmodule

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

module AddRoundKey(
    input  [63:0] currentState ,
    input  [63:0] roundKey     ,
    output [63:0] nextState    
);
    assign nextState[63:0] = roundKey[63:0]^currentState[63:0];

endmodule
