#include<iostream>
using namespace std;
long long cubeSumTillOne(long long n){
    long long sum=0;
    while(n!=0){
        sum += n*n*n;
        n -=1;
    }
}
long long cubeSumTillOne2(long long n){
    return (n*(n+1)/2)*(n*(n+1)/2);
}
long long pileCubes(long long n){
    for(long long i=1;i<n;i++){
        if(cubeSumTillOne2(i) == n) return i;
    }
    return -1;
}
int main(){
    cout<<pileCubes(4183059834009);
    return 0;
}