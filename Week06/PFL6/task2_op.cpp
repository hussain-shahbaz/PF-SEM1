#include<iostream>
using namespace std;
bool parityCheck(int n){
    int digSum = 0;
    int original = n;
    while(n!=0){
       digSum = digSum + n%10;
        n/=10;
    }
    if((digSum%2 ^ original%2)){
        return 0;
    } 
    return 1;


}
int main(){
    int n;
    cout<<"Enter the number you want ot check";
    cin>>n;
    cout<<parityCheck(n);
    return 0;
}