#include<iostream>
using namespace std;
string caculateCost(float budget, string category, int people){
    float VIP = 499.99;
    float normal = 249.99;
    float ticketPrice;
    float transportationCost;
    if(category == "VIP") ticketPrice = people*VIP;
    else if(category == "normal") ticketPrice = people*normal;
    
    if(people<=4) transportationCost = .75*budget;
    else if(people<=10) transportationCost = .60*budget;
    else if(people<=24) transportationCost = .50*budget;
    else if(people<=49) transportationCost = .40*budget;
    else if(people>49) transportationCost = .25*budget;
    float ttlCost = transportationCost + ticketPrice;
    float remaining = budget-ttlCost;
    if(remaining>0) return "Yes You have " + to_string(remaining) + " leva left";
    else return "No You don't have enough money, You need " + to_string(-1*remaining)+ " more leva";
}
int main(){
    float budget;
    int people;
    string category;
    cout<<"Enter Your budget"<<endl;
    cin>>budget;
    cout<<"Enter the category"<<endl;
    cin>>category;
    cout<<"Enter the number of people in the group"<<endl;
    cin>>people;
    cout<<caculateCost(budget, category, people);
    return 0;
}