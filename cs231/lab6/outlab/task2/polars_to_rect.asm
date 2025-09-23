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

polar_complx:
    polar_complx_name db 'c'
    polar_complx_pad db 7 dup(0)
    polar_complx_mag dq 10.0
    polar_complx_ang dq 0.0001

fmt db "%s => %f %f", 10, 0
label_polar2rect db "Testing polars to rectangular",0
label_exp db "Testing exp",0
label_sin db "Testing sin",0
label_cos db "Testing cos",0

;;;;;;;;;;;;;
six dq 6.0
two dq 2.0
one dq 1.0
temp dq 0.0
onetwe dq 120.0
fiveofouro dq 5040.0
twefour dq 24.0
seventwe dq 720.0
;;;; Fill other constants needed 
;;;;;;;;;;;;;

temp_cmplx:
    temp_name db 'r'
    temp_pad  db 7 dup(0)
    temp_real dq 0.0
    temp_img  dq 0.0

section .text
    default rel
    extern print_cmplx,print_float
    global main

main:
    push rbp
    
    ; --- Test: Polar to Rectangular ---
    lea rdi, [polar_complx]         ; pointer to input polar struct
    lea rsi, [temp_cmplx]     ; pointer to output rect struct
    
    call polars_to_rect

    lea rdi, [label_polar2rect]
    lea rsi, [temp_cmplx]
    call print_cmplx          ; should show converted rectangular form

    ; --- Test: exp ---
    movups xmm0, [two]
    mov rdi, 0x6

    call exp

    movups [temp],xmm0 
    lea rdi, [label_exp]
    lea rsi , [temp]
    call print_float

    ; --- Test: sin ---
    movups xmm0, [two]

    call sin

    movups [temp],xmm0 
    lea rdi, [label_sin]
    lea rsi , [temp]
    call print_float

    ; --- Test: cos ---
    movups xmm0, [two]
    call cos

    movups [temp],xmm0 
    lea rdi, [label_cos]
    lea rsi , [temp]
    call print_float

    mov     rax, 60         ; syscall: exit
    xor     rdi, rdi        ; status 0
    syscall


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; FILL FUNCTIONS BELOW ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; -----------------------------------
polars_to_rect:
    movsd    xmm2, qword [rdi+8] ;xmm2 is mag
    movsd    xmm1, qword [rdi+16] ;xmm1 is theta
    movsd xmm3, xmm2 ;xmm3 is mag

    movsd xmm0, xmm1
    call cos
    mulsd xmm3, xmm0

    movsd xmm0, xmm1
    call sin
    mulsd xmm2, xmm0

    movsd    qword [rsi+16], xmm2
    movsd    qword [rsi+8], xmm3
    ret

exp:
    movsd xmm2, [one] ;xmm0 has base, xmm2 has temp
    mov rsi, 0 ;rsi has i, rdi has power
.exp_loop:
    cmp rsi, rdi
    jge .out_exp
    mulsd xmm2, xmm0
    inc rsi
    jmp .exp_loop
.out_exp:
    movsd xmm0, xmm2
    ret
;-------------------------------------------------
sin:
    movsd xmm1, xmm0 ;xmm1 has theta
    movsd xmm2, xmm0 ;xmm2 has sum

    mov rdi, 3
    call exp
    divsd xmm0, [six]
    subsd xmm2, xmm0

    movsd xmm0, xmm1
    mov rdi, 5
    call exp
    divsd xmm0, [onetwe]
    addsd xmm2, xmm0

    movsd xmm0, xmm1
    mov rdi, 7
    call exp
    divsd xmm0, [fiveofouro]
    subsd xmm2, xmm0

    movsd xmm0, xmm2
    ret

cos:
    movsd xmm1, xmm0 ;xmm1 has theta
    movsd xmm2, [one] ;xmm2 has sum

    mov rdi, 2
    call exp
    divsd xmm0, [two]
    subsd xmm2, xmm0

    movsd xmm0, xmm1
    mov rdi, 4
    call exp
    divsd xmm0, [twefour]
    addsd xmm2, xmm0

    movsd xmm0, xmm1
    mov rdi, 6
    call exp
    divsd xmm0, [seventwe]
    subsd xmm2, xmm0

    movsd xmm0, xmm2
    ret
;-------------------------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; CODE ENDS HERE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

section .note.GNU-stack noalloc noexec nowrite progbits