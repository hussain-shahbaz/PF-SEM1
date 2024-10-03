#include<iostream>
using namespace std;
void isSymmetrical(int);
void Symmetry(int n);
main(){
    int number;
    cout<<"Enter a three digitnumber : ";
    cin>>number;
    // isSymmetrical(number);
    Symmetry(number);
}
void isSymmetrical(int n){
    /// This function is restricted for 3 digit number only
    int first_digit, last_digit;
    last_digit = n%10;
    first_digit = (n/100);
    if(first_digit == last_digit){
        cout<<"the number is symmetrical";
    }
    else{
    cout<<"the number is not symmetrical";
    }
}
void Symmetry(int n){
    /// however this function is more general and usable for a number with n digits
    int reverse = 0;
    int original_number = n;
    int last_digit;
    while(n!=0){
        last_digit = n%10;
        reverse = reverse*10 + last_digit;
        n =n/10;
    }
    // cout<<reverse;
    if(reverse == original_number){
        cout<<"The number is symmetrical";
    }
    else{
        cout<<"THe number is not symmetrical";
    }
}