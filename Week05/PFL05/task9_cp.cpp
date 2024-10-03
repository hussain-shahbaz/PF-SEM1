#include<iostream>
using namespace std;
void timeTravel(int,int);
main(){
    int hours, minutes;
    cout<<"make sure to enter time in 24 hours format"<<endl;
    cout<<"Enter the hours : "; 
    cin>>hours;
    cout<<"Enter the minutes : "; 
    cin>>minutes;
    timeTravel(hours,minutes);
}
void timeTravel(int hours, int minutes){
    if(minutes>44){
        minutes = minutes-45;
        hours = hours+1;
        if(hours>=24){
            hours = 0;
        }
        cout<<hours << " : " << minutes;
    }
    else{
        cout<<hours<<" : "<< minutes+15;
    }
}