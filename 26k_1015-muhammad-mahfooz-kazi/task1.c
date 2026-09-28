#include <stdio.h>

int main()
{
    int vehicle, hours, member;
    double fee;

    printf("Enter vehicle type (1=Bike, 2=Car, 3=Truck): ");
    scanf("%d", &vehicle);

    printf("Enter hours parked: ");
    scanf("%d", &hours);

    printf("Enter membership status (1=Member, 0=Non-member): ");
    scanf("%d", &member);

    if (vehicle < 1 || vehicle > 3)
    {
        printf("Invalid vehicle.\n");
    }
    else
    {
        if (hours <= 0)
        {
            printf("Invalid duration.\n");
        }
        else
        {
            if (vehicle == 1)
            {
                fee = 20 * hours;
            }
            else if (vehicle == 2)
            {
                if (hours <= 2)
                    fee = 50;
                else
                    fee = 50 + 30 * (hours - 2);
            }
            else
            {
                if (hours <= 3)
                    fee = 100;
                else
                    fee = 100 + 50 * (hours - 3);
            }

            if (member == 1 && fee > 200)
            {
                fee = fee - (fee * 0.15);
            }

            printf("Final Fee: %.2f\n", fee);
        }
    }

    return 0;
}
