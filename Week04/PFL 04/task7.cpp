#include<iostream>
using namespace std;
void evenORodd(int n);
main(){
    int N;
    cout<<"Enter a number ";
    cin>>N;
    evenORodd(N);
}
void evenORodd(int n){
    if(n%2==0){
        cout<<"the number is even";
    }
    else{
        cout<<"the number is odd";
    }
}