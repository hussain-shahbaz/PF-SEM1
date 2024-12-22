#include<iostream>
using namespace std;
main(){
    int area, w, h;
    cout<<"Enter the square metres you want to paint: ";
    cin>>area;
    cout<<"Width(in metres): ";
    cin>>w;
    cout<<"Lenght(in metres): ";
    cin>>h;


    int paint= area/(w*h);
    cout<<"Number of walls you can paint: "<<paint;
}