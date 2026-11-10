#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // 1. Three double variables
    double costPrice, sellPrice, quantity;

    // Variables to store the results
    double totalCost, totalSales, profit, profitPercent;

    // 2. Three pointers, one for each variable
    double *ptrCost = &costPrice;
    double *ptrSell = &sellPrice;
    double *ptrQty  = &quantity;

    // Pointers for the result variables
    double *ptrTotalCost    = &totalCost;
    double *ptrTotalSales   = &totalSales;
    double *ptrProfit       = &profit;
    double *ptrProfitPercent = &profitPercent;

    // Read all values using pointers only
    cout << "Enter cost price of one item: ";
    cin >> *ptrCost;
    cout << "Enter selling price of one item: ";
    cin >> *ptrSell;
    cout << "Enter quantity sold: ";
    cin >> *ptrQty;

    // 3. Calculate and store using pointers only
    *ptrTotalCost  = *ptrCost * *ptrQty;
    *ptrTotalSales = *ptrSell * *ptrQty;
    *ptrProfit     = *ptrTotalSales - *ptrTotalCost;

    cout << fixed << setprecision(2);
    cout << "\nTotal Cost  : Rs. " << *ptrTotalCost << endl;
    cout << "Total Sales : Rs. " << *ptrTotalSales << endl;

    // 4. Profit, Loss or No profit no loss
    if (*ptrProfit > 0)
        cout << "Result      : Profit of Rs. " << *ptrProfit << endl;
    else if (*ptrProfit < 0)
        cout << "Result      : Loss of Rs. " << -(*ptrProfit) << endl;
    else
        cout << "Result      : No profit no loss" << endl;

    // 5. Profit percentage using pointers
    if (*ptrTotalCost != 0)
        *ptrProfitPercent = (*ptrProfit / *ptrTotalCost) * 100;
    else
        *ptrProfitPercent = 0;

    if (*ptrProfitPercent >= 0)
        cout << "Profit percentage: " << *ptrProfitPercent << " %" << endl;
    else
        cout << "Loss percentage  : " << -(*ptrProfitPercent) << " %" << endl;

    // 6. Pointer to the larger of costPrice and sellPrice
    double *larger;
    if (*ptrCost >= *ptrSell)
        larger = ptrCost;
    else
        larger = ptrSell;

    if (*ptrCost == *ptrSell)
        cout << "\nCost price and selling price are equal: " << *larger << endl;
    else if (larger == ptrCost)
        cout << "\nLarger value is costPrice = " << *larger << endl;
    else
        cout << "\nLarger value is sellPrice = " << *larger << endl;

    // 7. Table of addresses of every variable and pointer
    cout << "\n------ ADDRESS TABLE ------\n";
    cout << left << setw(18) << "Name" << "Address" << endl;
    cout << "---------------------------------------\n";

    cout << setw(18) << "costPrice"     << &costPrice     << endl;
    cout << setw(18) << "sellPrice"     << &sellPrice     << endl;
    cout << setw(18) << "quantity"      << &quantity      << endl;
    cout << setw(18) << "totalCost"     << &totalCost     << endl;
    cout << setw(18) << "totalSales"    << &totalSales    << endl;
    cout << setw(18) << "profit"        << &profit        << endl;
    cout << setw(18) << "profitPercent" << &profitPercent << endl;

    cout << setw(18) << "ptrCost"        << &ptrCost        << endl;
    cout << setw(18) << "ptrSell"        << &ptrSell        << endl;
    cout << setw(18) << "ptrQty"         << &ptrQty         << endl;
    cout << setw(18) << "ptrTotalCost"   << &ptrTotalCost   << endl;
    cout << setw(18) << "ptrTotalSales"  << &ptrTotalSales  << endl;
    cout << setw(18) << "ptrProfit"      << &ptrProfit      << endl;
    cout << setw(18) << "ptrProfitPercent" << &ptrProfitPercent << endl;
    cout << setw(18) << "larger"         << &larger         << endl;

    return 0;
}
