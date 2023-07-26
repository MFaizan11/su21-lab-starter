// "Copyright [2023] Muhammad Faizan"
#include <stdio.h>


int odd_occuring(int array[], int number) {
    int odd = 0;
    for (int i = 0; i < number; i++) {
        odd = odd ^ array[i];
    }
    return odd;
}

int main() {
    int arr[] = {12, 12, 14, 90, 14, 14, 14};
    int num = sizeof(arr)/sizeof(arr[0]);
    int result = odd_occuring(arr, num);

    printf("The array of numbers is: ");

    for (int i = 0; i < num; i++) {
      printf("%d ", arr[i]);
    }

    printf("\nThe odd occuring number is: %d\n", result);

    return 0;
}
