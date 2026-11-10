#include <stdio.h>

/* 1. Print title and routes */
void printMenu()
{
    printf("\n===== BUS TICKET BOOKING =====\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur    - Rs. 2200\n");
    printf("3. Karachi to Multan    - Rs. 3500\n");
}

/* 2. Ask for route number and give it to main */
int getRouteNumber()
{
    int route;
    do
    {
        printf("Enter route number (1 to 3): ");
        scanf("%d", &route);
        if (route < 1 || route > 3)
            printf("Invalid route number. Try again.\n");
    } while (route < 1 || route > 3);
    return route;
}

/* 3. Ask for number of seats and give it to main */
int getSeats()
{
    int seats;
    do
    {
        printf("Enter number of seats (1 to 6): ");
        scanf("%d", &seats);
        if (seats < 1 || seats > 6)
            printf("Invalid number of seats. Try again.\n");
    } while (seats < 1 || seats > 6);
    return seats;
}

/* Helper: ask for seat type (E or B) and give it to main */
char getSeatType()
{
    char type;
    do
    {
        printf("Enter seat type (E = Economy, B = Business): ");
        scanf(" %c", &type);
        if (type == 'e') type = 'E';
        if (type == 'b') type = 'B';
        if (type != 'E' && type != 'B')
            printf("Invalid seat type. Try again.\n");
    } while (type != 'E' && type != 'B');
    return type;
}

/* 4. Find fare of one seat from route number */
float findSeatFare(int route)
{
    float fare;
    switch (route)
    {
        case 1: fare = 800;  break;
        case 2: fare = 2200; break;
        case 3: fare = 3500; break;
        default: fare = 0;
    }
    return fare;
}

/* 5. Find total fare from seat fare and number of seats */
float findTotalFare(float seatFare, int seats)
{
    float total;
    total = seatFare * seats;
    return total;
}

/* 6. Add seat type charge (Business = extra 30%) */
float addSeatTypeCharge(float total, char type)
{
    float newTotal;
    if (type == 'B')
        newTotal = total + total * 30 / 100;
    else
        newTotal = total;
    return newTotal;
}

/* Helper: get route name from route number */
const char* getRouteName(int route)
{
    switch (route)
    {
        case 1: return "Karachi to Hyderabad";
        case 2: return "Karachi to Sukkur";
        case 3: return "Karachi to Multan";
        default: return "Unknown";
    }
}

/* Helper: get seat type name from character */
const char* getSeatTypeName(char type)
{
    if (type == 'B')
        return "Business";
    else
        return "Economy";
}

/* 7. Print ticket */
void printTicket(const char *routeName, int seats, const char *seatType, float finalFare)
{
    printf("\n------ BUS TICKET ------\n");
    printf("Route      : %s\n", routeName);
    printf("Seats      : %d\n", seats);
    printf("Seat Type  : %s\n", seatType);
    printf("Final Fare : Rs. %.2f\n", finalFare);
    printf("------------------------\n");
}

int main()
{
    int i, route, seats;
    char type;
    float seatFare, total, finalFare;
    float totalEarnings = 0;

    for (i = 1; i <= 2; i++)
    {
        printf("\n*** Passenger %d of 2 ***", i);
        printMenu();

        route = getRouteNumber();
        seats = getSeats();
        type = getSeatType();

        seatFare = findSeatFare(route);
        total = findTotalFare(seatFare, seats);
        finalFare = addSeatTypeCharge(total, type);

        printTicket(getRouteName(route), seats, getSeatTypeName(type), finalFare);

        totalEarnings = totalEarnings + finalFare;
    }

    printf("\nTotal earnings of the bus company: Rs. %.2f\n", totalEarnings);

    return 0;
}
