#include <stdio.h>

int main() {
    char name[50], department[50], university[50];
    int age;
    long long studentID;

    printf("Enter your Name: ");
    scanf("%49s", name);

    printf("Enter your Age: ");
    scanf("%d", &age);

    printf("Enter your Department: ");
    scanf("%49s", department);

    printf("Enter your Student ID (numeric part): ");
    scanf("%lld", &studentID);

    printf("Enter your University Name: ");
    scanf("%49s", university);

    printf("\n--- Student Details ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Department: %s\n", department);
    printf("Student ID: %lld\n", studentID);
    printf("University Name: %s\n", university);

    return 0;
}
