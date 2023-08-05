.text
.globl main

main:
    addi a0, x0, 2    # set num to 5
    jal ra, dataArray # call dataArray function

dataArray:
    addi sp, sp, -44  # allocate stack space for the array and saved registers
    sw ra, 40(sp)     # save the return address
    sw s0, 36(sp)     # save s0
    addi s0, x0, 0    # i = 0
    addi s1, sp, 0    # base of the array
loop:
    addi s4, x0, 10
    bge s0, s4, exit  # if i >= 10, then exit loop
    add a2, s0, x0    # set second argument of compare to i
    add a1, a0, x0    # set first argument of compare to num
    jal ra, compare   # call compare

    sw a0, 0(s1)      # store the result of compare in array[i]

    # Print the value
    mv a1, a0         # move the value to a1
    addi a0, x0, 1    # set a7 to 1 (syscall for print integer)
    ecall             # print integer syscall

    addi s0, s0, 1    # increment i
    addi s1, s1, 4    # move to the next position in the array
    j loop            # jump back to the start of loop

exit:
    lw ra, 40(sp)     # restore the return address
    lw s0, 36(sp)     # restore s0
    addi sp, sp, 44   # deallocate stack space
    jr ra             # return from dataArray

compare:
    add a2, a1, x0    # copy the first argument to a2
    add a1, a0, x0    # copy the second argument to a1
    jal ra, sub       # call sub
    blt a0, x0, else  # if result of sub < 0, jump to else
    addi a0, x0, 1    # return 1
    jr ra             # return from compare
else:
    addi a0, x0, 0    # return 0
    jr ra             # return from compare

sub:
    sub a0, a0, a1    # return a - b
    jr ra             # return from sub
