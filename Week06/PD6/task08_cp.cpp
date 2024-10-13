#include <iostream>
#include <cmath>
using namespace std;
int calculateVolleyBallGames(string yearType, int holidays, int hometownWeekends){
    float h =  0.67*hometownWeekends + holidays;
    float p = 0.75*(48-hometownWeekends);
    if(yearType == "normal"){
        return floor(h+p);
    }
    else if(yearType == "leap") return floor((floor(h)+floor(p))*1.15);
}
int main()
{
    string year;
    int holidays,weekends;
    cout<<"Enter the type of year : ";
    cin>>year;
    cout<<"Enter the number of holidays : ";
    cin>>holidays;
    cout<<"Enter the numbre of WeekEnds : ";
    cin>>weekends;
    cout<<calculateVolleyBallGames(year,holidays,weekends);
    return 0;
}