#include<iostream>
using namespace std;
float calculateAmount(char service, char time, int minutes){
    float amount;
    if(service == 'r'){
        if(minutes <= 50){
            return 10.00;
        }
        else if(minutes > 50){
            return 10.00 + ((minutes - 50) * 0.20);
        }
    }
    else if(service == 'p'){
        if(minutes <=75){
            return 25.00;
        }
        else if(minutes>75){
            if(time == 'd') return (25 + (minutes - 75)*0.10);
            else if(time == 'n') return (25 + (minutes - 100)*0.05);
        }
    }
    else{
        return -1;
    }
}
int main(){
    char service, time;
    int minutes;
    cout<<"Enter the service code (R/n for regular, p/P for premium) : ";
    cin>>service;
    cout<<"Enter the time zone of the call (D/d for day, N/n for night) : ";
    cin>>time;
    cout<<"Enter the numbr of minutes used : ";
    cin>>minutes;
    if(service == 'p') cout<<"Service type : Premium";
    else cout<<"Service type : regular";
    cout<<"Total minutes used : "<<minutes << " used";
    cout<<"Amount Due : $"<<calculateAmount(service, time , minutes);
    return 0;
}