// "Copyright [2023] Muhammad Faizan"
#include <stdio.h>

#define CSR_VAL 0x8000abcd00001234UL
#define ADDRESS 0x5300f000U

unsigned long int my_csr = CSR_VAL;

int main(void)
{
  // make the first bit of my_csr equal to 1
  my_csr |= 1UL << 0;

  // make the third bit (bit 2) equal to 0
  my_csr &= ~(1UL << 2);

  // make bits 8 to 15 equal to 0xee
  my_csr = (my_csr & ~(0xffUL << 8)) | (0xeeUL << 8);

  // extract bits 12 to 27 
  unsigned long int bit12_27 = (ADDRESS >> 12) & 0xffffU;
  my_csr = (my_csr & ~(0xffffUL << 16)) | (bit12_27 << 16);

  printf("%lx \n", my_csr);

  return 0;
}
