#include <stdio.h>

/* 1. Print hospital name and room charges */
void printMenu()
{
    printf("\n===== CITY HOSPITAL =====\n");
    printf("Room Charges:\n");
    printf("1. General Ward  - Rs. 1500/day\n");
    printf("2. Semi-Private  - Rs. 3500/day\n");
    printf("3. Private       - Rs. 6000/day\n");
}

/* 2. Ask for room type and give it to main */
int getRoomType()
{
    int room;
    do
    {
        printf("Enter room type (1, 2 or 3): ");
        scanf("%d", &room);
        if (room < 1 || room > 3)
            printf("Invalid room type. Try again.\n");
    } while (room < 1 || room > 3);
    return room;
}

/* 3. Ask for number of days and give it to main */
int getDays()
{
    int days;
    do
    {
        printf("Enter number of days stayed (1 to 30): ");
        scanf("%d", &days);
        if (days < 1 || days > 30)
            printf("Invalid days. Try again.\n");
    } while (days < 1 || days > 30);
    return days;
}

/* 4. Find room charges from room type and days */
float findRoomCharges(int room, int days)
{
    float rate;
    switch (room)
    {
        case 1: rate = 1500; break;
        case 2: rate = 3500; break;
        case 3: rate = 6000; break;
        default: rate = 0;
    }
    return rate * days;
}

/* 5. Add 5% service charge on medicine bill */
float findMedicineCharge(float medicine)
{
    float newMedicine;
    newMedicine = medicine + medicine * 5 / 100;
    return newMedicine;
}

/* 6. Give 8% discount if stay is 7 days or more, find final amount */
float findFinalAmount(float total, int days)
{
    float finalAmount;
    if (days >= 7)
        finalAmount = total - total * 8 / 100;
    else
        finalAmount = total;
    return finalAmount;
}

/* Helper: get room name from room number */
const char* getRoomName(int room)
{
    switch (room)
    {
        case 1: return "General Ward";
        case 2: return "Semi-Private";
        case 3: return "Private";
        default: return "Unknown";
    }
}

/* 7. Print final bill */
void printBill(const char *roomName, int days, float roomCharges,
               float medicineCharges, float finalAmount)
{
    printf("\n------ FINAL BILL ------\n");
    printf("Room Type         : %s\n", roomName);
    printf("Days Stayed       : %d\n", days);
    printf("Room Charges      : Rs. %.2f\n", roomCharges);
    printf("Medicine Charges  : Rs. %.2f\n", medicineCharges);
    printf("Final Amount      : Rs. %.2f\n", finalAmount);
    printf("------------------------\n");
}

int main()
{
    int room, days;
    float medicine, roomCharges, medicineCharges, total, finalAmount;
    char senior;

    printMenu();

    room = getRoomType();
    days = getDays();

    printf("Enter medicine bill: Rs. ");
    scanf("%f", &medicine);

    roomCharges = findRoomCharges(room, days);
    medicineCharges = findMedicineCharge(medicine);
    total = roomCharges + medicineCharges;
    finalAmount = findFinalAmount(total, days);

    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);

    if (senior == 'y' || senior == 'Y')
    {
        finalAmount = finalAmount - 1000;
        if (finalAmount < 0)
            finalAmount = 0;
    }

    printBill(getRoomName(room), days, roomCharges, medicineCharges, finalAmount);

    return 0;
}
