nasm -f elf64 ../task1/print_cmplx.asm -o ./print_cmplx.o
objcopy --redefine-sym main=print_main print_cmplx.o
nasm -f elf64 basic_cmplx_arith.asm -o basic_cmplx_arith.o
gcc print_cmplx.o basic_cmplx_arith.o -o basic_cmplx_arith -no-pie
rm *.o