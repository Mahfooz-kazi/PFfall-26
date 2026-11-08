#include <stdio.h>

/* 1. Print title and list of packs */
void printMenu()
{
    printf("\n===== PREPAID RECHARGE =====\n");
    printf("1. Rs. 100\n");
    printf("2. Rs. 200\n");
    printf("3. Rs. 500\n");
    printf("4. Rs. 1000\n");
}

/* 2. Ask for pack number and give it to main */
int getPackNumber()
{
    int pack;
    do
    {
        printf("Enter pack number (1 to 4): ");
        scanf("%d", &pack);
        if (pack < 1 || pack > 4)
            printf("Invalid pack number. Try again.\n");
    } while (pack < 1 || pack > 4);
    return pack;
}

/* 3. Ask for mobile number (11 digits) and give it to main */
long long getMobileNumber()
{
    long long mobile;
    do
    {
        printf("Enter mobile number (11 digits): ");
        scanf("%lld", &mobile);
        if (mobile < 10000000000LL || mobile > 99999999999LL)
            printf("Mobile number must be 11 digits. Try again.\n");
    } while (mobile < 10000000000LL || mobile > 99999999999LL);
    return mobile;
}

/* 4. Find pack amount from pack number using switch */
float findAmount(int pack)
{
    float amount;
    switch (pack)
    {
        case 1: amount = 100;  break;
        case 2: amount = 200;  break;
        case 3: amount = 500;  break;
        case 4: amount = 1000; break;
        default: amount = 0;
    }
    return amount;
}

/* 5. Add 15% tax and find the new amount */
float addTax(float amount)
{
    float newAmount;
    newAmount = amount + amount * 15 / 100;
    return newAmount;
}

/* 6. Find bonus: 10% if amount is 500 or more, otherwise 0 */
float findBonus(float amount)
{
    float bonus;
    if (amount >= 500)
        bonus = amount * 10 / 100;
    else
        bonus = 0;
    return bonus;
}

/* 7. Print recharge slip */
void printSlip(long long mobile, float amount, float tax, float totalBalance)
{
    printf("\n------ RECHARGE SLIP ------\n");
    printf("Mobile Number : %lld\n", mobile);
    printf("Pack Amount   : Rs. %.2f\n", amount);
    printf("Tax (15%%)     : Rs. %.2f\n", tax);
    printf("Total Balance : Rs. %.2f\n", totalBalance);
    printf("---------------------------\n");
}

int main()
{
    int i, pack;
    long long mobile;
    float amount, amountWithTax, tax, bonus, totalBalance;
    float totalSpent = 0;

    for (i = 1; i <= 3; i++)
    {
        printf("\n*** Recharge %d of 3 ***", i);
        printMenu();

        pack = getPackNumber();
        mobile = getMobileNumber();

        amount = findAmount(pack);
        amountWithTax = addTax(amount);
        tax = amountWithTax - amount;
        bonus = findBonus(amount);
        totalBalance = amount + bonus;

        printSlip(mobile, amount, tax, totalBalance);

        totalSpent = totalSpent + amountWithTax;
    }

    printf("\nTotal money spent in 3 recharges: Rs. %.2f\n", totalSpent);

    return 0;
}
