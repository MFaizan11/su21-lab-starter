.data
b:  .space 12       # Allocate space for array b[3]

.text
main:
    addi s1, x0, 7    # a = 7
    addi s0, x0, 0    # i = 0
    la s2, b          # &b
    addi x29, x0, 2   # Store the loop limit (3) in x29
loop:
    blt x29, s0, exit     # If i > 3 then continue loop
    mul t0, s0, s1        # Calculate a * i
    add t0, s1, t0        # Calculate a + (i * a)
    sw t0, 0(s2)          # b[i] = a + (i * a)
    
    add a1, t0, x0        # store t0 to a1
    addi a0, x0, 1        # print the values 7, 14, 21
    ecall
    #addi a0, x0, 7
    
    addi s0, s0, 1        # Increment i
    addi s2, s2, 4        # Increment &b by 4 bytes (to the next int)
    j loop                # Jump to label 'exit'
exit:
    addi a0, x0, 10
    ecall
    # j exit

