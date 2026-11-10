#include <iostream>
using namespace std;

// Display all stock
void displayStock(int *p, int n)
{
    if (n == 0)
    {
        cout << "No items in stock." << endl;
        return;
    }
    for (int i = 0; i < n; i++)
        cout << "Item " << i + 1 << ": " << *(p + i) << endl;
}

// Print total stock and item with lowest stock
void showSummary(int *p, int n)
{
    if (n == 0)
    {
        cout << "Total stock: 0 (no items)" << endl;
        return;
    }

    int total = 0;
    int lowPos = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + *(p + i);
        if (*(p + i) < *(p + lowPos))
            lowPos = i;
    }

    cout << "Total stock: " << total << endl;
    cout << "Lowest stock: Item " << lowPos + 1
         << " with " << *(p + lowPos) << endl;
}

// Update stock of one item
void updateStock(int *p, int n)
{
    int pos, value;

    if (n == 0)
    {
        cout << "No items to update." << endl;
        return;
    }

    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n)
    {
        cout << "Invalid position." << endl;
        return;
    }

    cout << "Enter new stock value: ";
    cin >> value;

    if (value < 0)
    {
        cout << "Stock cannot be negative." << endl;
        return;
    }

    *(p + pos - 1) = value;
    cout << "Stock updated." << endl;
}

// Insert a new item (array becomes one bigger)
void insertItem(int *&p, int &n)
{
    int pos, value, i;

    cout << "Enter position for new item (1 to " << n + 1 << "): ";
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    cout << "Enter stock of new item: ";
    cin >> value;

    if (value < 0)
    {
        cout << "Stock cannot be negative." << endl;
        return;
    }

    int index = pos - 1;
    int *newArr = new int[n + 1];

    // copy values before the new position
    for (i = 0; i < index; i++)
        *(newArr + i) = *(p + i);

    // add the new value
    *(newArr + index) = value;

    // copy values after the new position
    for (i = index; i < n; i++)
        *(newArr + i + 1) = *(p + i);

    delete[] p;
    p = newArr;
    n++;

    cout << "Item inserted." << endl;
}

// Delete an item (array becomes one smaller)
void deleteItem(int *&p, int &n)
{
    int pos, i, j;

    if (n == 0)
    {
        cout << "No items to delete." << endl;
        return;
    }

    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n)
    {
        cout << "Invalid position." << endl;
        return;
    }

    int index = pos - 1;
    int *newArr = new int[n - 1];

    // copy all values except the deleted one
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (i != index)
        {
            *(newArr + j) = *(p + i);
            j++;
        }
    }

    delete[] p;
    p = newArr;
    n--;

    cout << "Item deleted." << endl;
}

// Sort ascending using bubble sort with pointers
void sortStock(int *p, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*(p + j) > *(p + j + 1))
            {
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
    cout << "Stock sorted in ascending order." << endl;
}

int main()
{
    int n, i, choice;

    // 1. Ask for starting size (3 to 8)
    do
    {
        cout << "Enter starting number of items (3 to 8): ";
        cin >> n;
        if (n < 3 || n > 8)
            cout << "Invalid size. Try again." << endl;
    } while (n < 3 || n > 8);

    int *stock = new int[n];

    // Read starting stock
    for (i = 0; i < n; i++)
    {
        do
        {
            cout << "Enter stock of item " << i + 1 << ": ";
            cin >> *(stock + i);
            if (*(stock + i) < 0)
                cout << "Stock cannot be negative. Try again." << endl;
        } while (*(stock + i) < 0);
    }

    // 2. Menu
    do
    {
        cout << "\n===== GROCERY STOCK MENU =====" << endl;
        cout << "1. Display stock" << endl;
        cout << "2. Update stock of one item" << endl;
        cout << "3. Insert a new item" << endl;
        cout << "4. Delete an item" << endl;
        cout << "5. Sort stock" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayStock(stock, n);
                break;
            case 2:
                updateStock(stock, n);
                showSummary(stock, n);
                break;
            case 3:
                insertItem(stock, n);
                showSummary(stock, n);
                break;
            case 4:
                deleteItem(stock, n);
                showSummary(stock, n);
                break;
            case 5:
                sortStock(stock, n);
                showSummary(stock, n);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    // 8. Free the memory
    delete[] stock;
    stock = NULL;
    cout << "Memory has been released." << endl;

    return 0;
}
