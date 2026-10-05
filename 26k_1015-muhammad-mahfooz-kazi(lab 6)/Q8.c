#include <stdio.h>

int main()
{
    int seats[15] = {1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1};
    int i;
    int booked = 0, empty = 0;
    int first = -1, last = -1;
    int count = 0;

    // Count booked and empty seats
    for (i = 0; i < 15; i++)
    {
        if (seats[i] == 1)
            booked++;
        else
            empty++;
    }

    printf("Booked seats: %d\n", booked);
    printf("Empty seats: %d\n", empty);

    // Find first available seat
    for (i = 0; i < 15; i++)
    {
        if (seats[i] == 0)
        {
            first = i + 1;
            break;
        }
    }

    printf("First available seat: %d\n", first);

    // Find last available seat
    for (i = 14; i >= 0; i--)
    {
        if (seats[i] == 0)
        {
            last = i + 1;
            break;
        }
    }

    printf("Last available seat: %d\n", last);

    // Book first 3 available seats
    for (i = 0; i < 15; i++)
    {
        if (seats[i] == 0 && count < 3)
        {
            seats[i] = 1;
            count++;
        }
    }

    // Print final seating chart
    printf("Final seating chart:\n");

    for (i = 0; i < 15; i++)
    {
        printf("Seat %d = %d\n", i + 1, seats[i]);
    }

    return 0;
}