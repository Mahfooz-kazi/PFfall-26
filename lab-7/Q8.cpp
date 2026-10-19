#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int n = 5;

    // ---------- Pattern Set 1: right-aligned triangles ----------
    for (int i = 1; i <= n; i++)
    {
        string stars = "", nums = "", letters = "";

        // same leading spaces for all three, so they are right-aligned
        for (int s = 1; s <= 2 * (n - i); s++)
        {
            stars += " ";
            nums += " ";
            letters += " ";
        }

        for (int j = 1; j <= i; j++)
        {
            stars += "* ";
            nums += to_string(j) + " ";
            letters += char('A' + j - 1);
            letters += " ";
        }

        cout << left << setw(12) << stars << "| "
             << setw(12) << nums << "| "
             << letters << endl;
    }

    cout << endl;

    // ---------- Pattern Set 2: centered pyramids ----------
    for (int i = 1; i <= n; i++)
    {
        string stars = "", nums = "", letters = "";
        int count = 2 * i - 1;

        for (int s = 1; s <= 2 * (n - i); s++)
        {
            stars += " ";
            nums += " ";
            letters += " ";
        }

        for (int j = 1; j <= count; j++)
        {
            stars += "* ";
            nums += to_string(j) + " ";
            letters += char('A' + j - 1);
            letters += " ";
        }

        cout << left << setw(20) << stars << "| "
             << setw(20) << nums << "| "
             << letters << endl;
    }

    return 0;
}
