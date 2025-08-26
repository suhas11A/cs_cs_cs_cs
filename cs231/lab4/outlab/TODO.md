# Week 1
Asm Lab Week 1 consists of 3 tasks
## Task 1
- Learn the very basics of x86 assembly
- Load two numbers into registers, add them and store their result in the rax register
- Look at (and maybe mess around with) the code for writing to stdout using a syscall, try to understand what is happening
- Compile using `bash compile.sh` from within the `task1` directory and run using `./add-nums`
## Task 2
### Understanding syscalls using gdb
- Compile the `run-gdb.asm` script using `bash compile.sh` from within the `task2` directory and run it using `gdb ./run-gdb`
- Use `break _start` first so the code doesn't immediately run
- Run the code using `run`
- Use `si` to run the code line by line so you may see the effects of each line of code
- Use `info registers` to see the values held in the registers
- Note down the registers modified when line number 14 of `run-gdb.asm` is executed, their old and new values in `mod-regs.txt`
