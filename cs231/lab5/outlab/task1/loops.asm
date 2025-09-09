section .data
    buffer  db 20 dup(0)     ; Output buffer for result string

section .bss
    input_buf resb 20  ; Reserve 20 bytes for input
    num     resq 1     ; 64-bit integer

section .text
    global _start ; essentially just means start here


_start:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; START OF YOUR CODE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Take in number as input from user
    ; You can do this using read(0, input_buffer, size) syscall, syscall number for read is 0
    ; Make sure your input buffer is stored in rsi :)
    mov rax, 0
    mov rdi, 0
    mov rsi, input_buf
    mov rdx, 20
    syscall
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; END OF YOUR CODE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; The below code simply converts input string to a number, don't worry about it
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
    ; Now RAX contains the number entered

    ; Implement following C code:
    ; int a = 0; \\a=r8\\
    ; int b = 1; \\b=r9\\
    ; for (int i=0; i < n; i++) { \\i=r10\\
    ;     int c = a + b; \\c=r11\\
    ;     a = b;
    ;     b = c;
    ; }
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; START OF YOUR CODE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    mov r8, 0
    mov r9, 1
    mov r10, 0
    mov rdi, 1
.loop:
    cmp r10, rax
    jge .out
    mov r11, r8
    add r11, r9
    mov r8, r9
    mov r9, r11
    add r10, rdi
    jmp .loop
.out:

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; END OF YOUR CODE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Print the result
    ; C code is:
    ; i = 19 \\i=r8\\
    ; while (a > 0) { \\a=rax\\
    ;   buff[i] = a % 10 + '0'; Note you must access only the lower 8 bits of your register storing a here :) for example, for rdx, lower 8 bits are stored in dl
    ;   a /= 10;
    ;   i--;
    ; }
    ; write(1, buff + i + 1, 19 - i); 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; START OF YOUR CODE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    mov rax, r8
    mov r8, 19
    mov rsi, 0
    mov rdi, 1
.looploop:
    cmp rax, rsi
    jle .outout
    mov rcx, 10
    xor rdx, rdx
    div rcx
    add dl, '0'
    mov [buffer+r8], dl
    sub r8, rdi
    jmp .looploop

.outout:
    mov rax, 1
    mov rdi, 1
    mov rsi, buffer
    add rsi, r8 
    add rsi, rdi
    mov rdx, 19
    sub rdx, r8
    syscall
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; END OF YOUR CODE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    mov rax, 60              ; syscall: exit
    xor rdi, rdi             ; exit code 0
    syscall
