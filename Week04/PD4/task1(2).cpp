#include<iostream>
using namespace std;
void isEqual(int num1, int num2){
    if(num1==num2){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
main(){
    int num1,num2;
    cout<<"Enter first number"<<endl;
    cin>>num1;
    cout<<"Enter second number"<<endl;
    cin>>num2;
    isEqual(num1,num2);
}