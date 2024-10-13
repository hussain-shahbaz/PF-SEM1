#include<iostream>
using namespace std;
string findZodiacSign(int date, string month){
    if((month == "march"  && (date >= 21 && date <= 31)) || (month == "april" && (date>=1 && date<=19)))  return "Aries";
    else if((month=="april" && (date>=20 && date <=31)) || (month=="may" && (date>=1 && date<=20))) return "Taurus";
    else if((month=="may" && (date>=21 && date <=31)) || (month=="june" && (date>=1 && date<=20))) return "Gemini";
    else if((month=="june" && (date>=21 && date <=31)) || (month=="july" && (date>=1 && date<=22))) return "Cancer";
    else if((month=="july" && (date>=23 && date <=31)) || (month=="august" && (date>=1 && date<=22))) return "Leo";
    else if((month=="august" && (date>=23 && date <=31)) || (month=="september" && (date>=1 && date<=22))) return "Virgo";
    else if((month=="september" && (date>=23 && date <=31)) || (month=="october" && (date>=1 && date<=23))) return "Libra";
    else if((month=="october" && (date>=21 && date <=31)) || (month=="november" && (date>=1 && date<=21))) return "Scorpio";
    else if((month=="november" && (date>=22 && date <=31)) || (month=="december" && (date>=1 && date<=22))) return "sagittarious";
    else if((month=="december" && (date>=22 && date <=31)) || (month=="january" && (date>=1 && date<=19))) return "capicorn";
    else if((month=="january" && (date>=20 && date <=31)) || (month=="february" && (date>=1 && date<=18))) return "Aquarius";
    else if((month=="february" && (date>=19 && date <=31)) || (month=="march" && (date>=1 && date<=20))) return "Piscus";


}
int main(){
    int day;
    string month;
    cout<<"ENter the month you were born : ";
    cin>>month;
    cout<<"ENter the date of birth";
    cin>>day;
    cout<<"YOu are "<<findZodiacSign(day, month);
    return 0;
}