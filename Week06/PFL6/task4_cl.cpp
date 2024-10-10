#include<iostream>
using namespace std;
int greatestNumber(int n1, int n2, int n3){
    if(n1>n2 && n1 > n3){
        return n1;
    }
    else if(n2 > n1 && n2 >  n3){
        return n2;
    }
    return n3;
}
int main(){
    int num1,num2,num3;
    cout<<"Enter the first number ; "<<endl;
    cin>>num1;
    cout<<"Enter the second number : "<<endl;
    cin>>num2;
    cout<<"Enter the third number : "<<endl;
    cin>>num3;
    cout<<"The greatest number is : "<<greatestNumber(num1,num2,num3);
    return 0;
}