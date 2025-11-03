section .data
    shifted_disk db "Shifted disk "
    from_str db " from "
    to_str db " to "
    a_rod db 'A'
    b_rod db 'B'
    c_rod db 'C'
    newline db 10
    shifted_len equ 13
    from_len equ 6
    to_len equ 4
    buffer db 100 dup(0) ; Output buffer for result string

section .bss
    input_buf resb 20  ; Reserve 20 bytes for input
    num resq 1         ; 64-bit integer

section .text
    global printNum
    global hanoi
    global _start 
    global printFromAndTo

printNum:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to print an arbitary number stored in rax
    push rax
    push rcx
    push rdx
    push rsi
    push rdi

    mov r9, 99
    mov rsi, 0
    mov rdi, 1
.looploop:
    cmp rax, rsi
    jle .outout
    mov rcx, 10
    xor rdx, rdx
    div rcx
    add dl, '0'
    mov [buffer+r9], dl
    sub r9, rdi
    jmp .looploop

.outout:
    mov rax, 1
    mov rdi, 1
    mov rsi, buffer
    add rsi, r9
    add rsi, rdi
    mov rdx, 99
    sub rdx, r9
    syscall

    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rax

    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

printFromAndTo:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to print " from " *rax " to " *rdi
    mov rsi, rax
    push rax
    push rcx

    push rdi
    push rsi
    mov rdi, 1
    mov rsi, from_str
    mov rdx, from_len
    mov rax, 1
    syscall

    pop rsi

    mov  rdi, 1
    mov  rdx, 1
    mov  rax, 1
    syscall

    mov rdi, 1
    mov rsi, to_str
    mov rdx, to_len
    mov rax, 1
    syscall

    pop rdi

    mov  rsi, rdi
    mov  rdi, 1
    mov  rdx, 1
    mov  rax, 1
    syscall

    pop rcx
    pop rax

    ret
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
hanoi:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; C code for function
;;;; void hanoi(int n, char from, char to, char aux) {
;;;;     if (n == 1) {
;;;;         printf("Shifted disk 1 from %c to %c\n", from, to);
;;;;         return;
;;;;     }
;;;;     hanoi(n - 1, from, aux, to);
;;;;     printf("Shifted disk %d from %c to %c\n", n, from, to);
;;;;     hanoi(n - 1, aux, to, from);
;;;; }

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    push rbp
    mov  rbp, rsp
    push rbx
    push r12

    mov r10, [rbp+16]
    mov rbx, [rbp+24]
    mov r12, [rbp+32]
    mov rax, [rbp+40] 

    mov r8, 1
    cmp rax, r8
    jne .goboi

    push rax

    mov rdi, 1
    mov rsi, shifted_disk
    mov rdx, shifted_len
    mov rax, 1
    syscall

    mov  rax, 1
    call printNum

    mov rsi, r10
    mov rdi, rbx

    push rax
    mov rax, rsi
    call printFromAndTo
    pop rax

    push rax
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    mov rax, 1
    syscall
    pop rax

    pop rax

    jmp .retoo

.goboi:
    sub rax, r8

    push rax
    push rbx
    push r12
    push r10

    call hanoi

    pop r10
    pop r12
    pop rbx
    pop rax

    add rax, r8

    push rax

    mov rdi, 1
    mov rsi, shifted_disk
    mov rdx, shifted_len
    mov rax, 1
    syscall

    pop rax

    sub  rsp, 8
    call printNum
    add  rsp, 8

    mov rsi, r10
    mov rdi, rbx
    
    push rax
    mov rax, rsi
    call printFromAndTo
    pop rax

    push rax
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    mov rax, 1
    syscall
    pop rax

    sub rax, r8

    push rax
    push r10
    push rbx
    push r12

    call hanoi
    
    pop r12
    pop rbx
    pop r10
    pop rax

.retoo:
    pop  r12
    pop  rbx
    pop  rbp
    ret

_start:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to take in number as input, then call hanoi(num, 'A','B','C')
    mov rax, 0
    mov rdi, 0
    mov rsi, input_buf
    mov rdx, 20
    syscall
    mov rsi, input_buf  ; rsi points to buffer
    xor rax, rax        ; accumulator = 0
.convert1:
    movzx rcx, byte [rsi] ; load byte
    cmp rcx, 10           ; check for newline
    je .done1
    sub rcx, '0'          ; convert ASCII to digit
    imul rax, rax, 10
    add rax, rcx
    inc rsi
    jmp .convert1
.done1:
    push rax
    mov  rax, c_rod
    push rax
    mov  rax, b_rod
    push rax
    mov  rax, a_rod
    push rax
    call hanoi
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    mov     rax, 60         ; syscall: exit
    xor     rdi, rdi        ; status 0
    syscall
