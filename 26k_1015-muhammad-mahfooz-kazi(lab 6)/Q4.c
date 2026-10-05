#include <stdio.h>

int main()
{
    int marks[15];
    int i;
    int sum = 0;
    int count100 = 0;

    for (i = 0; i < 15; i++)
    {
        printf("Enter mark for student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    /* Add bonus and cap at 100 */
    for (i = 0; i < 15; i++)
    {
        if (marks[i] + 5 > 100)
            marks[i] = 100;
        else
            marks[i] = marks[i] + 5;
    }

    int highest = marks[0];
    int lowest = marks[0];

    /* Calculate sum, count 100s, find highest and lowest */
    for (i = 0; i < 15; i++)
    {
        sum += marks[i];

        if (marks[i] == 100)
            count100++;

        if (marks[i] > highest)
            highest = marks[i];

        if (marks[i] < lowest)
            lowest = marks[i];
    }

    double average = (double)sum / 15;

    printf("\n--- Marks after bonus ---\n");
    for (i = 0; i < 15; i++)
    {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }

    printf("\nNew class average : %.2f\n", average);
    printf("Students with 100 : %d\n", count100);
    printf("Highest mark      : %d\n", highest);
    printf("Lowest mark       : %d\n", lowest);
    printf("Range             : %d\n", highest - lowest);

    return 0;
}