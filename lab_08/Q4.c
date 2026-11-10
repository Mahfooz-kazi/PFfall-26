#include <stdio.h>

/* 1. Print title and fare rules */
void printRules()
{
    printf("\n===== CITY TAXI SERVICE =====\n");
    printf("Base fare           : Rs. 150\n");
    printf("First 10 km         : Rs. 60 per km\n");
    printf("After 10 km         : Rs. 45 per km\n");
    printf("Waiting             : first 5 min free, then Rs. 10 per min\n");
    printf("Night (10 PM-6 AM)  : 25%% extra\n");
}

/* 2. Ask for distance and give it to main */
float getDistance()
{
    float distance;
    do
    {
        printf("Enter distance in km (more than 0, up to 200): ");
        scanf("%f", &distance);
        if (distance <= 0 || distance > 200)
            printf("Invalid distance. Try again.\n");
    } while (distance <= 0 || distance > 200);
    return distance;
}

/* 3. Ask for waiting time and give it to main */
int getWaitingTime()
{
    int waiting;
    do
    {
        printf("Enter waiting time in minutes (0 to 120): ");
        scanf("%d", &waiting);
        if (waiting < 0 || waiting > 120)
            printf("Invalid waiting time. Try again.\n");
    } while (waiting < 0 || waiting > 120);
    return waiting;
}

/* Helper: ask for hour of the trip and give it to main */
int getHour()
{
    int hour;
    do
    {
        printf("Enter hour of the trip (0 to 23): ");
        scanf("%d", &hour);
        if (hour < 0 || hour > 23)
            printf("Invalid hour. Try again.\n");
    } while (hour < 0 || hour > 23);
    return hour;
}

/* 4. Find distance charge (base fare included) */
float findDistanceCharge(float distance)
{
    float charge;
    if (distance <= 10)
        charge = 150 + distance * 60;
    else
        charge = 150 + 10 * 60 + (distance - 10) * 45;
    return charge;
}

/* 5. Find waiting charge (first 5 minutes free) */
float findWaitingCharge(int waiting)
{
    float charge;
    if (waiting > 5)
        charge = (waiting - 5) * 10;
    else
        charge = 0;
    return charge;
}

/* 6. Add night charge (25% if hour is 22 or later, or before 6) */
float addNightCharge(float fare, int hour)
{
    float newFare;
    if (hour >= 22 || hour < 6)
        newFare = fare + fare * 25 / 100;
    else
        newFare = fare;
    return newFare;
}

/* 7. Print trip receipt */
void printReceipt(float distance, int waiting, float finalFare)
{
    printf("\n------ TRIP RECEIPT ------\n");
    printf("Distance     : %.2f km\n", distance);
    printf("Waiting Time : %d min\n", waiting);
    printf("Final Fare   : Rs. %.2f\n", finalFare);
    printf("--------------------------\n");
}

int main()
{
    int i, waiting, hour;
    float distance, distanceCharge, waitingCharge, fare, finalFare;
    float totalEarnings = 0;
    float highestFare = 0;

    for (i = 1; i <= 3; i++)
    {
        printf("\n*** Trip %d of 3 ***", i);
        printRules();

        distance = getDistance();
        waiting = getWaitingTime();
        hour = getHour();

        distanceCharge = findDistanceCharge(distance);
        waitingCharge = findWaitingCharge(waiting);
        fare = distanceCharge + waitingCharge;
        finalFare = addNightCharge(fare, hour);

        printReceipt(distance, waiting, finalFare);

        totalEarnings = totalEarnings + finalFare;

        if (finalFare > highestFare)
            highestFare = finalFare;
    }

    printf("\nTotal earnings of the day: Rs. %.2f\n", totalEarnings);
    printf("Highest fare of the day  : Rs. %.2f\n", highestFare);

    return 0;
}
