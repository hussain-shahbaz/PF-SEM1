#include<iostream>
using namespace std;
main(){
    while(true){
        int num1, num2;
        char operation;
        cout<<"Enter first number";
        cin>>num1;
        cout<<"Enter seond number";
        cin>>num2;
        cout<<"Enter the operation you want to do \n '+' for addition\n '-' for subtraction\n '*' for multiplication\n '/' for division \n '%' for modulus"<<endl;
        cin>>operation;
        if(operation == '+'){
            cout<<"the sum is : "<<num1+num2<<endl;
        }
        else if(operation == '-'){
            cout<<"the difference is : "<<num1-num2<<endl;
        }
        else if(operation == '*'){
            cout<<"the product is : "<<num1*num2<<endl;
        }
        else if(operation == '/'){
            cout<<"the division  is : "<<num1/num2<<endl;
        }
        else if(operation == '%'){
            cout<<"the remainder  is : "<<num1%num2<<endl;
        }
        else{
            cout<<"Please enter a valid operator";
        }
    }

}
