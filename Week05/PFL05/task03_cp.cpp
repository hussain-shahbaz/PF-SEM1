#include<iostream>
using namespace std;
void calculateTax(char, float);
main(){
    char vehicleCode;
    float price;
    cout<<"Enter the vehicle code (M,E,S,V,T)";
    cin>>vehicleCode;
    cout<<"Enter the price of your vehicle in $";
    cin>>price;
    calculateTax(vehicleCode, price);
}
void calculateTax(char vehicleCode, float price){
    float taxRate;
    if(vehicleCode == 'M') taxRate = .06;
    else if(vehicleCode == 'E') taxRate = .08;
    else if(vehicleCode == 'S') taxRate = .1;
    else if(vehicleCode == 'V') taxRate = .12;
    else if(vehicleCode == 'T') taxRate = .15;
    else cout<<"Enter a valid vehicle Type";
    cout<<"The final price of your vehicle is $"<<(taxRate+1)*price;
}