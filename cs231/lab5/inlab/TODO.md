# Week 2
The goal of this week is to learn constructs such as conditional statements in the in-lab, and loops and functions in the out-lab
## Task 1
### Register Classification
- Registers are of two types - caller saved and callee saved
- By convention, when function `func_caller` internally calls function `func_callee`, `func_caller` is supposed to save all the caller saved registers before the call and restore them after the call, while `func_callee` is supposed to save the callee saved registers before executing function and restore them after executing
- For programmers, it means that you can freely use callee saved registers before and after syscalls and remain confident that their values will be unchanged
- For customized functions, caller and callee saved registers is a matter of convention
- See the registers modified in `caller-callee.asm`
- Here is every single callee saved register: **rbx, r12, r13, r14, r15**
### How to save registers?
- Modify `call-function.asm` so that the value inside `rax` register in `caller_function` after it calls `callee_function` holds the return value, while every other register value is unsaved
- You can use `push` instruction to push registers onto stack and `pop` instruction to pop registers from stack
## Task 2
### Conditional Statements
- Take a number as input from the user, if it gives remainder 5 with 7, output `fizz`, if it is even, output `buzz`, if it is both, output `fizzbuzz`, if it is neither, output nothing
- You have been given code for converting string to number for input
- You have also been given sample code for how to take remainder in asm
