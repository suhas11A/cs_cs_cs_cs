.data
CONTROL: .word32 0x10000
DATA:    .word32 0x10008

prompt:  .asciiz "Enter n to compute Fibonacci(n): "
result_msg: .asciiz "Fibonacci number: "
nl:      .asciiz "\n"

        .text
        ; Load MMIO register addresses
        lwu   $t9, CONTROL($zero)   ; $t9 = CONTROL address
        lwu   $t8, DATA($zero)      ; $t8 = DATA address

        ; Read unroll factor
        daddi $v0, $zero, 8         ; 8 = read integer
        sd    $v0, 0($t9)
        ld    $s5, 0($t8)           ; $s5 = factor

        ; Print prompt
        daddi $v0, $zero, 4         ; 4 = print string
        daddi $a0, $zero, prompt
        sd    $a0, 0($t8)           
        sd    $v0, 0($t9)

        ; Read n 
        daddi $v0, $zero, 8         ; 8 = read integer
        sd    $v0, 0($t9)
        ld    $s0, 0($t8)           ; $s0 = n

        ; Compute Fibonacci(n) 
        ; F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)

        dadd $s5, $s5, $s5
        daddi $s5, $s5, 1
        
        daddi $s1, $zero, 0         ; prev = 0
        daddi $s2, $zero, 1         ; curr = 1
        daddi $s3, $zero, 0         ; i = 0

        daddi $t0, $zero, 1
        daddi $t1, $zero, 3
        daddi $t2, $zero, 5
        daddi $t3, $zero, 7

        dsub $s0, $s0, $s5

        beq $s5, $t0, fib_loop0
        beq $s5, $t1, fib_loop1
        beq $s5, $t2, fib_loop2
        beq $s5, $t3, fib_loop3


fib_loop0:
        slt $t6, $s0, $s3
        beq   $t6, $t0, fib_done
        
        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next
        daddi $s3, $s3, 1           ; i++
        j     fib_loop0




fib_loop1:
        slt $t6, $s0, $s3
        beq   $t6, $t0, fib_done
        
        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        daddi $s3, $s3, 3           ; i++
        j     fib_loop1





fib_loop2:
        slt $t6, $s0, $s3
        beq   $t6, $t0, fib_done
        
        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        daddi $s3, $s3, 5           ; i++
        j     fib_loop2







fib_loop3:
        slt $t6, $s0, $s3
        beq   $t6, $t0, fib_done
        
        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next

        daddi $s3, $s3, 7           ; i++
        j     fib_loop3


fib_done:

        dadd $s0, $s0, $s5

fib_loop:
        beq   $s3, $s0, fib_doneactually    ; if i == n, done
        
        dadd  $s4, $s1, $s2         ; next = prev + curr
        dadd  $s1, $zero, $s2       ; prev = curr
        dadd  $s2, $zero, $s4       ; curr = next
        daddi $s3, $s3, 1           ; i++
        j     fib_loop

fib_doneactually:




        ; Result in $s1 

        ; Print result message
        daddi $v0, $zero, 4
        daddi $a0, $zero, result_msg
        sd    $a0, 0($t8)
        sd    $v0, 0($t9)

        ; Print result
        daddi $v0, $zero, 2         ; 2 = print integer
        sd    $s1, 0($t8)
        sd    $v0, 0($t9)

        ; Print newline
        daddi $v0, $zero, 4
        daddi $a0, $zero, nl
        sd    $a0, 0($t8)
        sd    $v0, 0($t9)

        halt