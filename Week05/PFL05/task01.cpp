#include<iostream>
using namespace std;
void sum(int , int );
main(){
    int n1,n2;
    cout<<"Enter your first number : "<<endl;
    cin>>n1;
    cout<<"Enter your second number : "<<endl;
    cin>>n2;
    sum(n1,n2);
}
void sum(int n1,int n2){
    cout<<"The sum of the two numbers is "<< n1+n2;
}