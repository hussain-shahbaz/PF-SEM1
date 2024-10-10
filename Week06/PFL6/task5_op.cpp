#include<iostream>
using namespace std;
float discount(string month, string day, float bill){
    if(day == "Sunday"){
        if(month == "October") return bill*.9;
        else return bill*.95;
    }
    return bill;
}
int main(){
    string day, month;
    float bill;
    cout<<"Enter the day : ";
    cin>>day;
    cout<<"Enter the month : ";
    cin>>month;
    cout<<"Enter the total bill";
    cin>>bill;
    cout<<"Your total payable is : Rs."<<discount(month, day, bill); 
    return 0;
}