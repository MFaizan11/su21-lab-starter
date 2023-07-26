// "Copyright [2023] Muhammad Faizan"
#include <stdio.h>

// Define the Student structure
struct student {
    char name[20];
    int ID;
    int age;
};

int main() {
    struct student s1;
    // struct student s2;

    // Enter the student detail
    printf("Enter name: ");
    scanf("%s", s1.name);
    printf("Enter ID: ");
    scanf("%d", &s1.ID);
    printf("Enter age: ");
    scanf("%d", &s1.age);

    // It will print the student detail
    printf("\nStudent detail:\n");
    printf("Name: %s\n", s1.name);
    printf("ID: %d\n", s1.ID);
    printf("Age: %d\n", s1.age);

    return 0;
}
