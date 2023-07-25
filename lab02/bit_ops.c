// Copyright [2023] Muhammad Faizan
#include <stdio.h>
#include "bit_ops.h"

// Returns the Nth bit of X. Assumes 0 <= N <= 31.
unsigned get_bit(unsigned x, unsigned n) {
    // Shift bits of x to the right by n places and mask the least significant bit to get the nth bit
    return (x >> n) & 1U;
}

// Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1
void set_bit(unsigned *x, unsigned n, unsigned v) {
    if (v) {
        // If v is 1, we set the nth bit by bitwise OR operation with the mask where only the nth bit is 1
        *x |= 1U << n;
    } else {
        // If v is 0, we unset the nth bit by bitwise AND operation with the mask where all bits except nth bit are 1
        *x &= ~(1U << n);
    }
}

// Flips the Nth bit in X. Assumes 0 <= N <= 31.
void flip_bit(unsigned *x, unsigned n) {
    // Flip the nth bit by using bitwise XOR operation with a mask where only the nth bit is 1
    *x ^= 1U << n;
}
