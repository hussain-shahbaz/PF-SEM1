#include<iostream>
using namespace std;
void Discount(string country, int price){
    if(country == "Pakistan"){
        cout<<"your final price is :"<<price*0.95<<endl;
    }
    if(country == "India"){
        cout<<"your final price is :"<<price*0.95<<endl;
    }
    if(country == "Ireland"){
        cout<<"your final price is :"<<price*0.80<<endl;
    }
    if(country == "England"){
        cout<<"your final price is :"<<price*0.70<<endl;
    }
    if(country == "Canada"){
        cout<<"your final price is :"<<price*0.55<<endl;
    }
}
main(){
    cout<<"enter your country's name : "<<endl;
    string country;
    cin>>country;
    cout<<"enter your ticket price : $"<<endl;
    int price;
    cin>>price;
    Discount(country,price);

}