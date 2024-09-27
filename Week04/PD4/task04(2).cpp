#include<iostream>
using namespace std;
void checkSpeed(int speed){
    if(speed>100){
        cout<<"You will be challenged";
    }
    
    if(speed<=100){
        cout<<"You are safe";
    }
}
main(){
    int speed;
    cout<<"enter the speed of your vehicle(we read it)";
    cin>>speed;
    checkSpeed(speed);
}