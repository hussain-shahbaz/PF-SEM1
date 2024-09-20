#include<iostream>
using namespace std;
main(){
    int num;
    cout<<"Enter a 4 digit number : ";
    cin>>num;
    int i1 = num%10;
    num /= 10;
    int i2 = num%10;
    num /= 10;
    int i3 = num%10;
    num /= 10;
    int i4 = num%10;
    num /= 10;
    int sum = i1+i2+i3+i4;

    cout<<"Sum of individual digits : "<<sum;
}