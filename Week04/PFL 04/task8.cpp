#include<iostream>

using namespace std;
void discount(string day, float amount);
main(){
    int amount;
    string day;
    cout<<"What is the day today";
    cin>>day;
    cout<<"Your total bill";
    cin>>amount;
    discount(day, amount);
}
void discount(string day, float amount){
    if(day == "sunday" || day == "Sunday" || day == "SUNDAY"){
        cout<<"Your total bill after dicount is : "<< amount* 0.9;
    }
    else{
        cout<<"Your total bill is : "<<amount;
    }
}