// Copyright [2023] Muhammad Faizan
#include <stdio.h>

int mystrlen(char* str) {
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }

    return count;
}

int main() {
    char str[] = "Muhammad Faizan";
    int bytes = mystrlen(str);

    printf("The number of bytes in the string are: %d\n", bytes);

    return 0;
}
