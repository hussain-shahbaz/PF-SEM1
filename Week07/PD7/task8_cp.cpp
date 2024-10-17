#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << fixed;
    cout << setprecision(2);
    int count, ton, total = 0;
    float miniBus = 0, truck = 0, train = 0;
    float price = 0;
    cout << "Enter the count of cargo for transportation: ";
    cin >> count;
    for (int i = 1; i <= count; i++)
    {
        cout << "Enter the tonnage of Cargo: ";
        cin >> ton;
        total += ton;
        if (ton <= 3)
        {
            miniBus += ton;
            price += 200 * ton;
        }
        else if (ton > 3 && ton <= 11)
        {
            truck += ton;
            price += 175 * ton;
        }
        else
        {
            train += ton;
            price += 120 * ton;
        }
    }
    cout << "Average Price: $" << price / total << endl;
    cout << "Percentage of the cargo by minibus: %" << (miniBus / total) * 100 << endl;
    cout << "Percentage of the cargo by truck: %" << (truck / total) * 100 << endl;
    cout << "Percentage of the cargo by train: %" << (train / total) * 100 << endl;
    return 0;
}