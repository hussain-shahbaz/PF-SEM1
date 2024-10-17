#include<iostream>
using namespace std;
int getDigits(int n){
    int count=0;
    while(n!=0){
        n/=10;
        count++;
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Total digits are: "<<getDigits(n);
    return 0;
}