#include<iostream>
using namespace std;
main()
{
int Q;
cout<<"Enter the charge (Q) in Coulumbs..";
cin>>Q;
int t;
cout<<"Enter the charge (t) in Seconds..";
cin>>t;

cout<<"The current in amperes (I) is "<<Q/t<<" Amperes";
}