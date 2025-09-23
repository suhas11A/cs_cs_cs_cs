section .data

complex1:
    complex1_name db 'a'
    complex1_pad  db 7 dup(0)  
    complex1_real dq 1.0
    complex1_img  dq 2.5

complex2:
    complex2_name db 'b'
    complex2_pad  db 7 dup(0)  
    complex2_real dq 3.5
    complex2_img  dq 4.0

one dq 1.0
label_add db "Testing Addition",0

temp_cmplx:
    temp_name db 'r'
    temp_pad  db 7 dup(0)
    temp_real dq 0.0
    temp_img  dq 0.0

section .text
    default rel
    extern print_cmplx
    global main,add_cmplx

main:
    push rbp

    ; --- Test: Addition ---
    lea rdi, [complex2]
    lea rsi, [complex1]
    lea rdx, [temp_cmplx]
    call add_cmplx
    lea rdi, [label_add]
    lea rsi, [temp_cmplx]
    call print_cmplx  ; Expect 4.5 6.5
    pop rbp

    mov     rax, 60         ; syscall: exit
    xor     rdi, rdi        ; status 0
    syscall

add_cmplx:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to input three addresses of complex numbers subtract the complexes at the first two addresses and 
; write the result into the thrid address (source1,source2,destination) => write (source1 + source2) into destination
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    push rbp
    movq    xmm0, qword [rdi+8]
    movq    xmm2, qword [rsi+8]
    movq    xmm1, [rdi+16]
    movq    xmm3, [rsi+16]
    addsd xmm0, xmm2
    addsd xmm1, xmm3
    movq    qword [rdx+16], xmm1
    movq    qword [rdx+8], xmm0
    pop rbp
    ret
