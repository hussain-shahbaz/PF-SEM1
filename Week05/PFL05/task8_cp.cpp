#include<iostream>
using namespace std;
string OddishOrEvenish(int n);
main(){
    cout<<"Enter a five digit number";
    int number;
    cin>>number;
    cout<<OddishOrEvenish(number);
}
string OddishOrEvenish(int n){
    int last_digit;
    int sum=0;
    while(n!=0){
        last_digit = n%10;
        sum += last_digit;
        n = n/10;
    }
    if(sum%2==0){
        return "Evenish";
    }
    else{
        return "Oddish";
    }
}