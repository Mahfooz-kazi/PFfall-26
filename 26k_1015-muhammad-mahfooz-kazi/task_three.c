#include <stdio.h>

int main()
{
    int age, oxygen, heartRate;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter oxygen level (SpO2 %%): ");
    scanf("%d", &oxygen);

    printf("Enter heart rate (bpm): ");
    scanf("%d", &heartRate);

    if (oxygen < 90)
    {
        printf("Critical: immediate attention\n");
    }
    else if (heartRate > 130 || heartRate < 40)
    {
        printf("Critical: cardiac alert\n");
    }
    else if (age >= 65 && oxygen < 95)
    {
        printf("High priority\n");
    }
    else if (age <= 5 && heartRate > 110)
    {
        printf("High priority\n");
    }
    else if (oxygen < 97)
    {
        printf("Medium priority\n");
    }
    else
    {
        printf("Low priority\n");
    }

    return 0;
}