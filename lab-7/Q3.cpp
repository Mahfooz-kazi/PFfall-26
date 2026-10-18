#include <iostream>
using namespace std;

int main()
{
    int sales[4][5];
    double salesmanTotal[4] = {0};
    double productTotal[5] = {0};

    // 1. Input sales data
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Salesman " << i + 1 << ", Product " << j + 1 << " sales (Rs.): ";
            cin >> sales[i][j];
        }
    }

    // 2 & 3. Calculate totals
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            salesmanTotal[i] += sales[i][j]; // row total
            productTotal[j] += sales[i][j];  // column total
        }
    }

    // Display total per salesman
    cout << "\nTotal Sales per Salesman" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Salesman " << i + 1 << ": Rs. " << salesmanTotal[i] << endl;
    }

    // Display total per product
    cout << "\nTotal Sales per Product" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << "Product " << j + 1 << ": Rs. " << productTotal[j] << endl;
    }

    // 4. Find the product with highest revenue
    int best = 0;
    for (int j = 1; j < 5; j++)
    {
        if (productTotal[j] > productTotal[best])
        {
            best = j;
        }
    }
    cout << "\nMost expensive (highest revenue) product: Product " << best + 1
         << " (Rs. " << productTotal[best] << ")" << endl;

    // 5. Apply bonus
    double finalAmount[4];
    cout << "\nFinal Amount After Bonus" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (salesmanTotal[i] > 10000)
        {
            finalAmount[i] = salesmanTotal[i] + salesmanTotal[i] * 0.10;
            cout << "Salesman " << i + 1 << ": Rs. " << finalAmount[i]
                 << " (Bonus applied)" << endl;
        }
        else
        {
            finalAmount[i] = salesmanTotal[i];
            cout << "Salesman " << i + 1 << ": Rs. " << finalAmount[i]
                 << " (No bonus)" << endl;
        }
    }

    return 0;
}