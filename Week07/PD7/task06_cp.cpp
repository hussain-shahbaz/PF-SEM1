#include<iostream>
using namespace std;
bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int primoral(int n){
    int prod=1;
    int i=2;
    int count=1;
    while(count<=n){
        if(isPrime(i)){
            prod*=i;
            count++;
        }
        i++;
    }
    return prod;
}

int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    cout<<primoral(n);
    return 0;
}