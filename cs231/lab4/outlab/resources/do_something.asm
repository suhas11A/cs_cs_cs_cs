section .data
    msg db "Finished computing z!", 10 
    len equ 23

section .text  
    global _start

_start:
    ; rsp
    sub rsp, 24 ; rsp = rsp - 24
    ; x = <something> *(rsp) = <something>
    ; y = <something> *(rsp + 8) = <something>
    ; z = <something> *(rsp + 16) = <something>
    mov rax, 50 ; rax = 50
    mov [rsp], rax ; *(rsp) = rax
    mov rax, 35 ; rax = 35
    mov [rsp + 8], rax ; *(rsp + 8) = rax
    mov rax, [rsp] ; rax = *(rsp) -> rax = x
    mov rbx, [rsp + 8] ; rbx = *(rsp + 8) -> rbx = y
    add rax, rbx ; rax = rax + rbx -> rax = (x + y)
    sub rax, 30 ; rax = rax - 30 -> rax = (x + y) - 30
    mov [rsp + 16], rax ; *(rsp + 16) = rax -> z = rax
    mov rax, [rsp + 16] ; rax = *(rsp + 16) -> rax = z
    mov rbx, [rsp] ; rbx = *(rsp) -> rbx = x
    imul rax, rbx ; rax = rax * rbx -> rax = (z * x)
    add rax, 5 ; rax = rax + 5 -> rax = (z * x) + 5
    mov [rsp + 16], rax ; *(rsp + 16) = rax -> z = rax

    ; write (1, str, len)
    mov rax, 1 ; rax -> 1 => write
    mov rdi, 1 ; says we want to write to stdout
    mov rsi, msg
    mov rdx, len
    syscall

    mov rax, 60 ; rax -> 60 => exit
    mov rdi, 0 ; exitcode = 0
    syscall