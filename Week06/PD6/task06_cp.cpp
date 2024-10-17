#include <iostream>
using namespace std;
string calculateHotelPrices(string month, int numberOfStays)
{
    float studio, apartment;
    if (month == "may" || month == "october")
    {
        if (numberOfStays > 7 && numberOfStays<=14)
            studio = 50 * numberOfStays * 0.95;
        else if (numberOfStays > 14)
        {
            studio = 50 * numberOfStays * .70;
            apartment = 65 * numberOfStays * .90;
        }
        else
        {
            studio = 50.00 * numberOfStays;
            apartment = 65.00 * numberOfStays;
        }
    }
    else if (month == "june" || month == "september")
    {
        if (numberOfStays > 14)
        {
            studio = 75.20 * numberOfStays * .80;
            apartment = 68.70 * numberOfStays * .90;
        }
        else
        {
            studio = 75.20 * numberOfStays;
            apartment = 68.70 * numberOfStays;
        }
    }
    else if (month == "july" || month == "august")
    {
        studio = 76.00 * numberOfStays;
        if (numberOfStays > 14)
            apartment = 77.00 * .90 * numberOfStays;
        else
            apartment = 77.00 * numberOfStays;
    }
    string statement = "Studio : $" + to_string(studio) + "\nApartment : $" + to_string(apartment);
    return statement;
}
int main()
{
    int stays;
    string month;
    cout << "Enter the month(May,Jun,July,August,September,October)";
    cin >> month;
    cout << "Enter the number of stays : ";
    cin >> stays;
    cout << calculateHotelPrices(month, stays);
    return 0;
}