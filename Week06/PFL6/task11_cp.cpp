#include<iostream>
using namespace std;
string checkSpeed(float speed){
    if(speed<= 10) return "Slow";
    else if(speed>10 && speed<=50) return "Average";
    else if(speed>50 && speed<=150) return "Fast";
    else if(speed>150 && speed<=1000) return "Ulta Fast";
    else return "Extremely Fast";
}
int main(){
    int speed;
    cout<<"Enter your speed : ";
    cin>>speed;
    cout<<"Your speed is "<<checkSpeed(speed);
    return 0;
}