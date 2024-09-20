#include<iostream>
using namespace std;
main(){
    int n;
    cout<<"Enter the sides of the polygon : ";
    cin>>n;
    int angles = (n-2)*180;
    cout<<"The sum of angles is "<<angles<<" degrees";
}