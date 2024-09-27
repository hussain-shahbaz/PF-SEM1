#include<iostream>
using namespace std;
void passORfail(int marks);
main(){
    int marks;
    cout<<"enter your marks";
    cin >> marks;
    passORfail(marks);
}
void passORfail(int marks){
    if(marks>=50){
        cout<<"PASS!";
    }
    else{
        cout<<"fail";
    }
}