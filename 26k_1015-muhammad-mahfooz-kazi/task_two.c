#include <stdio.h>

int main()
{
    int marks, attendance;
    double income;

    printf("Enter marks: ");
    scanf("%d", &marks);

    printf("Enter attendance percentage: ");
    scanf("%d", &attendance);

    printf("Enter annual family income: ");
    scanf("%lf", &income);

    if (marks < 50)
    {
        printf("Not eligible: marks too low\n");
    }
    else if (attendance < 75)
    {
        printf("Not eligible: attendance too low\n");
    }
    else if (income > 800000)
    {
        printf("Not eligible: income too high\n");
    }
    else
    {
        if (marks >= 90 && attendance >= 90)
        {
            printf("Full scholarship\n");
        }
        else if (marks >= 75 && attendance >= 85)
        {
            printf("Half scholarship\n");
        }
        else
        {
            printf("Quarter scholarship\n");
        }
    }

    return 0;
}