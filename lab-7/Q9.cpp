#include <iostream>
using namespace std;

int main()
{
    const int DAILY_WAGE = 500;
    const int BONUS = 2000;

    int departments;
    int grandTotal = 0;

    cout << "Enter number of departments: ";
    cin >> departments;

    for (int d = 1; d <= departments; d++)
    {
        int employees;
        int departmentTotal = 0;

        cout << "\nEnter number of employees in Department " << d << ": ";
        cin >> employees;

        for (int e = 1; e <= employees; e++)
        {
            int days;
            cout << "Enter days worked by Employee " << e << ": ";
            cin >> days;

            int salary = days * DAILY_WAGE;
            if (days > 25)
            {
                salary += BONUS;
            }

            cout << "Department " << d << ", Employee " << e
                 << ": Days Worked = " << days
                 << ", Salary = Rs. " << salary << endl;

            departmentTotal += salary;
        }

        cout << endl;
        cout << "Total salary paid in Department " << d
             << " = Rs. " << departmentTotal << endl;

        grandTotal += departmentTotal;
    }

    cout << "\nTotal salary paid across all departments = Rs. "
         << grandTotal << endl;

    return 0;
}