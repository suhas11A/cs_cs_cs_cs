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

label_add db "Testing Addition",0
label_sub db "Testing subtraction",0
label_mul db "Testing Multiplication", 0
label_recip db "Testing Reciprocal", 0

temp_cmplx:
    temp_name db 'r'
    temp_pad  db 7 dup(0)
    temp_real dq 0.0
    temp_img  dq 0.0

section .text
    default rel
    extern print_cmplx
    global main

main:
    push rbp

    ; --- Test: Addition ---
    lea rdi, [complex2]
    lea rsi, [complex1]
    lea rdx, [temp_cmplx]
    call add_cmplx
    lea rdi, [label_add]
    lea rsi, [temp_cmplx]
    call print_cmplx  ; Expect 2.5 1.5

    ; --- Test: Subtraction ---
    lea rdi, [complex2]
    lea rsi, [complex1]
    lea rdx, [temp_cmplx]
    call sub_cmplx
    lea rdi, [label_sub]
    lea rsi, [temp_cmplx]
    call print_cmplx  ; Expect 2.5 1.5

    ; --- Test: Multiplication ---
    lea rdi, [complex2]
    lea rsi, [complex1]
    lea rdx, [temp_cmplx]
    call mul_cmplx
    lea rdi, [label_mul]
    lea rsi, [temp_cmplx]
    call print_cmplx  ; Expect -6.500000 12.750000

    ; --- Test: Reciprocal ---
    lea rdi, [complex1]
    lea rsi, [temp_cmplx]
    call recip_cmplx
    lea rdi, [label_recip]
    lea rsi, [temp_cmplx]
    call print_cmplx  ; Reciprocal of (1 + 2.5i) = (0.137931 -0.344828i)

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

sub_cmplx:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to input three addresses of complex numbers subtract the complexes at the first two addresses and 
; write the result into the thrid address (source1,source2,destination) => write (source1 - source2) into destination
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    push rbp
    movq    xmm0, qword [rdi+8]
    movq    xmm2, qword [rsi+8]
    movq    xmm1, [rdi+16]
    movq    xmm3, [rsi+16]
    subsd xmm0, xmm2
    subsd xmm1, xmm3
    movq    qword [rdx+16], xmm1
    movq    qword [rdx+8], xmm0
    pop rbp
    ret

mul_cmplx:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to input three addresses of complex numbers multiply the complexes at the first two addresses and 
; write the result into the thrid address
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    push rbp
    movq    xmm0, qword [rdi+8]
    movq    xmm2, qword [rsi+8]
    movq    xmm1, [rdi+16]
    movq    xmm3, [rsi+16]
    movsd xmm4, xmm0
    mulsd xmm4, xmm2 ;4 has real*real
    movsd xmm5, xmm3
    mulsd xmm5, xmm1 ;5 has img*img
    mulsd xmm0, xmm3 ;0 has real*img
    mulsd xmm2, xmm1 ;2 has real*img
    subsd xmm4, xmm5
    addsd xmm0, xmm2
    movq    qword [rdx+16], xmm0
    movq    qword [rdx+8], xmm4
    pop rbp
    ret
recip_cmplx:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to input two addresses of complex numbers find reciprocal of the complex at the first address and 
; write the result into the second address (source1,destination) => write (1/source1) into destination
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    push rbp
    movq    xmm0, qword [rdi+8]
    movq    xmm1, qword [rdi+16]
    movsd xmm2, xmm0
    movsd xmm3, xmm1
    mulsd xmm2, xmm2
    mulsd xmm3, xmm3
    addsd xmm2, xmm3
    divsd xmm0, xmm2
    divsd xmm1, xmm2
    subsd xmm3, xmm3
    subsd xmm3, xmm1
    movq    qword [rsi+16], xmm3
    movq    qword [rsi+8], xmm0
    pop rbp
    ret