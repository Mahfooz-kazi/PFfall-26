#include <stdio.h>

int main()
{
    int time, motion, light, room, cooking;

    printf("Enter time (0-23): ");
    scanf("%d", &time);

    printf("Enter motion detected (1=Yes, 0=No): ");
    scanf("%d", &motion);

    printf("Enter light level (0-100): ");
    scanf("%d", &light);

    printf("\nSelect Room:\n");
    printf("1. Living Room\n");
    printf("2. Bedroom\n");
    printf("3. Kitchen\n");
    printf("Enter room: ");
    scanf("%d", &room);

    if (room == 1)
    {
        if (motion == 0)
        {
            printf("Mode: Away\n");
            printf("Action: All OFF\n");
        }
        else if (time >= 6 && time < 18)
        {
            printf("Mode: Day\n");
            printf("Action: Lights ON\n");
        }
        else if (time >= 18 && time < 23)
        {
            printf("Mode: Evening\n");
            printf("Action: Dim lights\n");
        }
        else
        {
            printf("Mode: Night\n");
            printf("Action: Lights OFF\n");
        }
    }
    else if (room == 2)
    {
        if (motion == 0)
        {
            printf("Mode: Away\n");
            printf("Action: All OFF\n");
        }
        else if (time >= 6 && time < 18)
        {
            printf("Mode: Day\n");
            printf("Action: Lights ON\n");
        }
        else if (time >= 18 && time < 23)
        {
            printf("Mode: Evening\n");
            printf("Action: Dim lights\n");
        }
        else
        {
            printf("Mode: Night\n");
            printf("Action: Lights OFF\n");
        }
    }
    else if (room == 3)
    {
        printf("Are you cooking? (1=Yes, 0=No): ");
        scanf("%d", &cooking);

        if (cooking == 1)
        {
            printf("Exhaust fan: ON\n");
        }

        if (motion == 0)
        {
            printf("Mode: Away\n");
            printf("Action: All OFF\n");
        }
        else if (time >= 6 && time < 18)
        {
            printf("Mode: Day\n");
            printf("Action: Lights ON\n");
        }
        else if (time >= 18 && time < 23)
        {
            printf("Mode: Evening\n");
            printf("Action: Dim lights\n");
        }
        else
        {
            printf("Mode: Night\n");
            printf("Action: Lights OFF\n");
        }
    }
    else
    {
        printf("Invalid room.\n");
    }

    return 0;
}