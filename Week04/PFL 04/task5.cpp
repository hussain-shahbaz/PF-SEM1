#include<iostream>
using namespace std;
void Vote(int age);
main(){
    int age;
    cout<<"enter your age";
    cin>>age;
    Vote(age);
}
void Vote(int age){
    if(age>=18){
        cout<<"You are eigible to vote";
    }
    else{
        cout<<"sorry, vote after "<< 18-age <<" year(s), thankyou.";
    }
}
