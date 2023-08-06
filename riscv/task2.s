.data
A: .space 40          # allocate an array with space for 10 integers (40 bytes)

.text
main:
    addi s0, x0, 0        # initialize 0 to i
    addi a0, x0, 9        # set num to 9
    la s1, A              # pointer to the start of array A
    addi t1, s1, 40       # pointer to the end of array A
    jal ra, data_array    # data_array function calling
exit:
    addi a0, x0, 10       # exit
    ecall
compare:
    addi sp, sp, -8       # allocate stack space for saving registers
    sw ra, 0(sp)          # save the return address
    jal ra, subtract      # subtract function calling
    lw t0, 0(sp)          # load the result of the subtraction
    bge t0, x0, exit1     # if the result is >= 0, go to exit1
    sw x0, 8(sp)          # else, return 0
    j return
subtract:
    lw t2, 8(sp)          # load the value of i
    lw t3, 12(sp)         # load the value of num
    sub t3, t3, t2        # subtract i from num
    addi sp, sp, -4       # make space for the result on the stack
    sw t3, 0(sp)          # store the result on the stack
    jr ra                 # return to caller
return:
    lw ra, 4(sp)          # restore the return address
    addi sp, sp, 8        # deallocate the stack space
    jr ra                 # return to caller
exit1:
    addi t2, x0, 1
    sw t2, 8(sp)          # return 1
    j return
data_array:
    sw ra, 0(sp)          # save the return address
    addi sp, sp, -8       # allocate stack space
    sw a0, 4(sp)          # store num on the stack
for_loop:
    sw s0, 0(sp)          # store i on the stack
    jal ra, compare       # call compare function
    lw t3, 0(sp)          # load the result of compare function
    addi sp, sp, 4        # deallocate stack space for i
    sw t3, 0(s1)          # store the result in the array
    addi s0,s0, 1         # increment i
    addi s1, s1, 4        # move the array pointer to next integer
    blt s1, t1, for_loop  # if end not reached continue loop
    addi sp, sp, 8        # deallocate stack space for num and return address
    lw ra, 0(sp)          # restore the return address
    jr ra                 # return to caller
