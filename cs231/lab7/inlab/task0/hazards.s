.data

val1:   .word 5
val2:   .word 10
result: .word 0

.text
        lwu r2, val1(r0)       
        lwu r3, val2(r0)       

        ; RAW Hazard: r4 depends on r2 (early use)
        dadd r4, r2, r3        
        dadd r5, r4, r3        

        ; Strctural hazard: dmul takes more cycles than a traditional add, so when dmul moves to the next stage, there would be some instruction which also want to use the MEM stage resources
        
        dmul r2, r5, r2   

        dadd r6, r3, r5        
        dadd r6, r3, r5
        dadd r6, r3, r5
        dadd r6, r3, r5
        dadd r6, r3, r5
        dadd r6, r3, r5


        ; WAW Hazard  
        dmul r2, r5, r3
        dadd r2, r5, r3

        ; Branch stall

        daddi r7, r0, 20
        bne r2, r7, branch_label
        daddi r8, r0, 50
        daddi r8, r0, 75
        daddi r8, r0, 90

branch_label:
        daddi r8, r0, 100

end:
        sw r4, result(r0)
        halt
