#include<iostream>
using namespace std;
int GCD(int a, int b){
    int gcd=1;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0) gcd = i;
    }
    return gcd; 
}
int LCM(int a, int b, int gcd){
    gcd = GCD(a,b);
    return (a*b)/gcd;
}
int GCD2(int a, int b){ // using euclid's algorithm
    int rem;
    while(b!=0){
        rem = a%b;
        a=b;
        b = rem;
    }
    return a;
}
int main(){
    int a,b;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    cout<<"GCD: "<<GCD(a,b)<<endl;
    cout<<"LCM: "<<LCM(a,b, GCD(a,b))<<endl;
    cout<<"GCD2: "<<GCD2(a,b);
    return 0;
}