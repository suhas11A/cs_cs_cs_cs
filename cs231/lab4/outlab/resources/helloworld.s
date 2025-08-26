section .data
	helloworld db "Hello World!",10
	msglen equ 13

section .text
	global _start

_start:
	mov rax, 1 ; write syscall
	mov rdi, 1 ; stdout
	mov rsi, helloworld ; print "Hello World!\n" to screen
	mov rdx, msglen ; print 13 characters
	syscall ; make the syscall

	mov rax, 60 ; exit syscall
	mov rdi, 0 ; exitcode 0
	syscall ; make exit syscall