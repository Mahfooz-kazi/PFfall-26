#include <iostream>
using namespace std;

int main()
{
    int seats[10][4] = {0}; // 0 = available, 1 = reserved
    int n;

    cout << "How many seats to reserve? ";
    cin >> n;

    int count = 0;
    while (count < n)
    {
        int row, seat;
        cout << "Enter row (1-10) and seat (1-4): ";
        cin >> row >> seat;

        if (row < 1 || row > 10 || seat < 1 || seat > 4)
        {
            cout << "Invalid row or seat" << endl;
        }
        else if (seats[row - 1][seat - 1] == 1)
        {
            cout << "Seat already booked" << endl;
        }
        else
        {
            seats[row - 1][seat - 1] = 1;
            count++;
        }
    }

    // Display seating arrangement
    cout << "\nSeating Arrangement" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 4; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }

    // Count fully booked rows
    int fullRows = 0;
    for (int i = 0; i < 10; i++)
    {
        bool full = true;
        for (int j = 0; j < 4; j++)
        {
            if (seats[i][j] == 0)
            {
                full = false;
            }
        }
        if (full)
        {
            fullRows++;
        }
    }

    cout << "\nTotal fully booked rows: " << fullRows << endl;
    return 0;
}