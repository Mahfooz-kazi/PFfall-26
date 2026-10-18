#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 3;
    int data[SIZE][SIZE];
    int key[SIZE][SIZE];
    int encrypted[SIZE][SIZE];

    // 1. Input the Data Matrix
    cout << "Enter the Data Matrix values (3x3):" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Data[" << i << "][" << j << "]: ";
            cin >> data[i][j];
        }
    }

    // 2. Input the Key Matrix
    cout << "\nEnter the Key Matrix values (3x3):" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Key[" << i << "][" << j << "]: ";
            cin >> key[i][j];
        }
    }

    // 3. Apply the encryption rule
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            encrypted[i][j] = (data[i][j] * key[i][j]) + (i + j);
        }
    }

    // 4. Display the Encrypted Matrix
    cout << "\nEncrypted Matrix:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << encrypted[i][j] << "\t";
        }
        cout << endl;
    }

    // 5. Find the maximum encrypted value and its position
    int maxValue = encrypted[0][0];
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (encrypted[i][j] > maxValue)
            {
                maxValue = encrypted[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // 6. Display the final result
    cout << "\nMaximum Encrypted Value: " << maxValue << endl;
    cout << "Position (row, column): (" << maxRow << ", " << maxCol << ")" << endl;

    return 0;
}