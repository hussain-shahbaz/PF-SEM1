#include<iostream>
using namespace std;
void possibleBonus(int a,int b){
    if((a-b)<=6){
        cout<<"true";
    }
    else{
        cout<<"false"<<endl;
    }
}
main(){
    cout<<"Enter your position : ";
    int a;
    cin>>a;
    cout<<"Enter your friend's position : ";
    int b;
    cin>>b;
    possibleBonus(a,b);
}