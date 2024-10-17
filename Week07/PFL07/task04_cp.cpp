#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int getFrequency(int n, int digit){
    int count = 0;
    string str = to_string(n);
    for(int i=0;i<str.size();i++){
        if((str[i] - '0') == digit) count++;
    }
    return count;
} 
int getDigit(int n){
    int count=0;
    while(n!=0){
        n/=10;
        count++;
    }
    return count;
}
int getFrequency2(int n,int digit){
    int count = 0;
    int ith_digit;
    for(int i=0;i<getDigit(n);i++){
        ith_digit = n - floor((n/10))*10;
        if(n==0) break;
        else if(ith_digit == digit) count++;
        n/=10;
        
    }
    return count;

}
int getFrequency3(int n, int digit){
    int count = 0;
    while(n!=0){
        if(n%10 == digit) count ++;
        n/=10;
    }
    return count;
}
int main(){
    int n,digit;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Enter a digit to check: ";
    cin>>digit;
    cout<<"Frequency : "<<getFrequency(n,digit) << " and " << getFrequency2(n,digit) << " and " << getFrequency3(n, digit);
    return 0;
}