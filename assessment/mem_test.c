// Copyright [2023] Muhammad Faizan
#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

typedef struct {
  unsigned long long double_word[NO_WORDS];  // NOLINT
} arr_t __attribute__((aligned(SIZE_WORDS)));

arr_t store_byte_data[8] = {{0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000}};

arr_t store_byte_expected_data[8] = {  // double_word0         double_word1
    {0x00000000000000EF, 0x0000000000000000},
    {0x000000000000BE00, 0x0000000000000000},
    {0x0000000000AD0000, 0x0000000000000000},
    {0x00000000DE000000, 0x0000000000000000},
    {0x000000EF00000000, 0x0000000000000000},
    {0x0000BE0000000000, 0x0000000000000000},
    {0x00AD000000000000, 0x0000000000000000},
    {0xDE00000000000000, 0x0000000000000000}};

arr_t store_half_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000},
                                 {0x0000000000000000, 0x0000000000000000}};

arr_t store_half_word_expected_data[8] = {
    {0x000000000000BEEF, 0x0000000000000000},
    {0x0000000000ADBE00, 0x0000000000000000},
    {0x00000000DEAD0000, 0x0000000000000000},
    {0x000000EFDE000000, 0x0000000000000000},
    {0x0000BEEF00000000, 0x0000000000000000},
    {0x00ADBE0000000000, 0x0000000000000000},
    {0xDEAD000000000000, 0x0000000000000000},
    {0xDE00000000000000, 0x00000000000000EF}};

arr_t store_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000},
                            {0x0000000000000000, 0x0000000000000000}};

arr_t store_word_expected_data[8] = {{0x00000000DEADBEEF, 0x0000000000000000},
                                     {0x000000DEADBEEF00, 0x0000000000000000},
                                     {0x0000DEADBEEF0000, 0x0000000000000000},
                                     {0x00DEADBEEF000000, 0x0000000000000000},
                                     {0xF00DC0DE00000000, 0x0000000000000000},
                                     {0x0DC0DE0000000000, 0x00000000000000F0},
                                     {0xC0DE000000000000, 0x000000000000F00D},
                                     {0xDE00000000000000, 0x0000000000F00DC0}};

arr_t store_double_word_data[8] = {{0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000},
                                   {0x0000000000000000, 0x0000000000000000}};

arr_t store_double_word_expected_data[8] = {
    {0xDEADBEEFF00DC0DE, 0x0000000000000000},
    {0xADBEEFF00DC0DE00, 0x00000000000000DE},
    {0xBEEFF00DC0DE0000, 0x000000000000DEAD},
    {0xEFF00DC0DE000000, 0x0000000000DEADBE},
    {0xF00DC0DE00000000, 0x00000000DEADBEEF},
    {0x0DC0DE0000000000, 0x000000DEADBEEFF0},
    {0xC0DE000000000000, 0x0000DEADBEEFF00D},
    {0xDE00000000000000, 0x00DEADBEEFF00DC0}};

int store_byte_test() {
  // EF, BE, AD, DE, EF, BE, AD, DE
  long int array[] = {0xEF, 0xBE, 0xAD, 0xDE,   // NOLINT
                      0xEF, 0xBE, 0xAD, 0xDE};  // NOLINT
  int count = 0, index = 0, left_shift = 0;
  for (size_t i = 0; i < 8; i++) {
    store_byte_data[i].double_word[0] =
        store_byte_data[i].double_word[0] | ((array[index]) << left_shift);
    left_shift += 8;
    index++;
    if (store_byte_data[i].double_word[0] ==
        store_byte_expected_data[i].double_word[0]) {
      count += 1;
    } else {
      count = 0;
    }
  }
  if (count == 8) {
    printf("Test 1: Store byte test passed\n");
  } else {
    printf("Test 1: Store byte test failed\n");
  }
}  // store_byte_test

int store_half_word_test() {
  // BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
  long int array[] = {0xBEEF, 0xADBE, 0xDEAD, 0xEFDE};  // NOLINT
  int count = 0, index = 0, left_shift = 0;
  for (size_t i = 0; i < 8; i++) {
    store_half_word_data[i].double_word[0] =
        store_half_word_data[i].double_word[0] | ((array[index]) << left_shift);
    if (i == 7) {
      store_half_word_data[i].double_word[1] =
          store_half_word_data[i].double_word[1] | ((long)(0xEF));  // NOLINT
    }
    left_shift += 8;
    if (i == 3) {
      index = 0;
      continue;
    }
    index++;
    if ((store_half_word_data[i].double_word[0] ==
         store_half_word_expected_data[i].double_word[0]) &&
        (store_half_word_data[i].double_word[1] ==
         store_half_word_expected_data[i].double_word[1])) {
      count += 1;
    } else {
      count = 0;
    }
  }
  if (count == 7) {
    printf("Test 2: Store half word test passed\n");
  } else {
    printf("Test 2: Store half word test failed\n");
  }
}  // store_half_word_test

int store_word_test() {
  // DEADBEEF, F00DC0DE
  long int array[] = {0xDEADBEEF, 0xF00DC0DE};  // NOLINT
  int count = 0, index = 0, left_shift = 0;
  for (size_t i = 0; i < 8; i++) {
    store_word_data[i].double_word[0] =
        store_word_data[i].double_word[0] | ((array[index]) << left_shift);
    left_shift += 8;
    if (i == 3) {
      index = 1;
      continue;
    }
    if (i == 5) {
      store_word_data[i].double_word[1] =
          store_word_data[i].double_word[1] | ((long)(0xF0));  // NOLINT
    } else if (i == 6) {
      store_word_data[i].double_word[1] =
          store_word_data[i].double_word[1] | ((long)(0xF00D));  // NOLINT
    } else if (i == 7) {
      store_word_data[i].double_word[1] =
          store_word_data[i].double_word[1] | ((long)(0xF00DC0));  // NOLINT
    }
    if ((store_word_data[i].double_word[0] ==
         store_word_expected_data[i].double_word[0]) &&
        (store_word_data[i].double_word[1] ==
         store_word_expected_data[i].double_word[1])) {
      count += 1;
    } else {
      count = 0;
    }
  }
  if (count == 7) {
    printf("Test 3: Store word test passed\n");
  } else {
    printf("Test 3: Store word test failed\n");
  }
}  // store_word_test

int store_double_word_test() {
  // DEADBEEFF00DC0DE
  long int array[] = {0xDEADBEEFF00DC0DE};  // NOLINT
  int count = 0, left_shift = 0;
  for (size_t i = 0; i < 8; i++) {
    store_double_word_data[i].double_word[0] =
        store_double_word_data[i].double_word[0] | ((array[0]) << left_shift);
    left_shift += 8;
    // if (i == 3) {
    //  continue;
    //  }
    if (i == 1) {
      store_double_word_data[i].double_word[1] =
          store_double_word_data[i].double_word[1] | ((long)(0xDE));  // NOLINT
    } else if (i == 2) {
      store_double_word_data[i].double_word[1] =
          store_double_word_data[i].double_word[1] | ((long)(0xDEAD));  // NOLINT
    } else if (i == 3) {
      store_double_word_data[i].double_word[1] =
          store_double_word_data[i].double_word[1] | ((long)(0xDEADBE));  // NOLINT
    } else if (i == 4) {
      store_double_word_data[i].double_word[1] =
          store_double_word_data[i].double_word[1] | ((long)(0xDEADBEEF));  // NOLINT
    } else if (i == 5) {
      store_double_word_data[i].double_word[1] =
          store_double_word_data[i].double_word[1] | ((long)(0xDEADBEEFF0));  // NOLINT
    } else if (i == 6) {
      store_double_word_data[i].double_word[1] =
          store_double_word_data[i].double_word[1] |
          ((long)(0xDEADBEEFF00D));  // NOLINT
    } else if (i == 7) {
      store_double_word_data[i].double_word[1] =
          store_double_word_data[i].double_word[1] |
          ((long)(0xDEADBEEFF00DC0));  // NOLINT
    }
    // printf("New: %llx\n", store_double_word_data[i].double_word[0]);
    // printf("New: %llx\n", store_double_word_data[i].double_word[1]);
    if ((store_double_word_data[i].double_word[0] ==
         store_double_word_expected_data[i].double_word[0]) &&
        (store_double_word_data[i].double_word[1] ==
         store_double_word_expected_data[i].double_word[1])) {
      count += 1;
    } else {
      count = 0;
    }
  }
  if (count == 8) {
    printf("Test 4: Store double word test passed\n");
  } else {
    printf("Test 4: Store double word test failed\n");
  }
}  // store_double_word_test

int main() {
  store_byte_test();
  store_half_word_test();
  store_word_test();
  store_double_word_test();
  return 0;
}
