#include<iostream>
using namespace std;
bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int countPrimes(int n){
    int count=0;
    for(int i=2;i<=n;i++){
        if(isPrime(i)) count++;
    }
    return count;
}
int main(){
    int n;
    cout<<"ENter an integer: ";
    cin>>n;
    cout<<countPrimes(n);
    return 0;
}