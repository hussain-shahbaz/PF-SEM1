#include<iostream>
using namespace std;
bool greaterNumber(int n1, int n2){
    if(n1>n2) return 1;
    return 0;
}
int main(){
    int n1,n2;
    cout<<"Enter the first number : ";
    cin>>n1;
    cout<<"Enter the second number : ";
    cin>>n2;
    cout<<greaterNumber(n1,n2);
    return 0;
}