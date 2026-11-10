#include <iostream>
using namespace std;

int main()
{
    int n, i;

    // 1. Ask for number of days (1 to 10)
    do
    {
        cout << "How many days of temperature to store (1 to 10)? ";
        cin >> n;
        if (n < 1 || n > 10)
            cout << "Invalid number. Try again." << endl;
    } while (n < 1 || n > 10);

    // 2. Create the array using new
    double *temp = new double[n];

    // 3. Read temperatures (-10 to 55 only)
    for (i = 0; i < n; i++)
    {
        do
        {
            cout << "Enter temperature for Day " << i + 1 << ": ";
            cin >> *(temp + i);
            if (*(temp + i) < -10 || *(temp + i) > 55)
                cout << "Temperature must be from -10 to 55. Try again." << endl;
        } while (*(temp + i) < -10 || *(temp + i) > 55);
    }

    // 4. Print each temperature with its address
    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Day " << i + 1 << ": " << *(temp + i)
             << " at address " << (temp + i) << endl;
    }

    // 5. Find hottest and coldest using a pointer that moves forward
    double *ptr = temp;
    double hottest = *ptr;
    double coldest = *ptr;

    for (i = 0; i < n; i++)
    {
        if (*ptr > hottest)
            hottest = *ptr;
        if (*ptr < coldest)
            coldest = *ptr;
        ptr++;
    }

    cout << "\nHottest temperature: " << hottest << endl;
    cout << "Coldest temperature: " << coldest << endl;

    // 6. Count days hotter than 40
    int count = 0;
    for (i = 0; i < n; i++)
    {
        if (*(temp + i) > 40)
            count++;
    }
    cout << "Days hotter than 40: " << count << endl;

    // 7. Free the memory
    delete[] temp;
    temp = NULL;

    // 8. Confirm memory is released
    cout << "\nMemory has been released." << endl;

    return 0;
}
