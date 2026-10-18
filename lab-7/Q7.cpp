#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int N = 5;

    // 1. Triangular pattern of digits
    cout << "Triangular Pattern:" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    // 2. Reversed pattern
    cout << "\nReversed Pattern:" << endl;
    for (int i = N; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    // 3. Modified: triangular multiplication values (i x j)
    cout << "\nMultiplication Pattern:" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }

    // 4. Modified and reversed
    cout << "\nReversed Multiplication Pattern:" << endl;
    for (int i = N; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }

    return 0;
}