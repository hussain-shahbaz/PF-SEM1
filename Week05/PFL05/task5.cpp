#include<iostream>
#include<cmath>
using namespace std;
main(){
    float base, exponent;
    cout<<"Enter the base number";
    cin>>base;
    cout<<"Enter the exponent";
    cin>>exponent;
    cout<<"The greater number is "<< pow(base, exponent);
}