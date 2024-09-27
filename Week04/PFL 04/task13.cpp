#include<iostream>
using namespace std;
void Discount(string day, float amount);
main()
{
    cout << "enter the day today";
    string day;
    cin >> day;
    int amount;
    cout << "enter the total bill";
    cin >> amount;
    Discount(day, amount);
}
void Discount(string day, float amount)
{

    if (day == "sunday" || day == "Sunday" || day == "SUNDAY")
    {
        cout << "Your total bill after dicount is : " << amount * 0.9;
    }
    else
    {
        cout << "Your total bill is : " << amount * 0.95;
    }
}