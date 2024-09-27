#include<iostream>
using namespace std;
void Fuel(float distance);
main(){
    float distance;
    cout<<"Enter the distance you want ot travel : ";
    cin>>distance;
    Fuel(distance);
}
void Fuel(float distance){
    if(distance<10){
        cout<<"100";
    }
    else{
        cout<< 10*distance;
    }
}