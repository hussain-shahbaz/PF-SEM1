#include<iostream>
using namespace std;
main(){
    cout<<"Enter the acceleration (m/s^2): ";
    int a;
    cin>>a;
    cout<<"Enter the initial velocity (m/s): ";
    int vi;
    cin>>vi;
    cout<<"Enter the time (s): ";
    int t;
    cin>>t;
    int vf = vi + a*t;

    cout<<"Final velocity in m/s is : "<<vf;
}