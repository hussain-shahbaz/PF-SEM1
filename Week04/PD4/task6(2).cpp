#include<iostream>
using namespace std;
void longestTime(int hours, int minutes){
    if((hours*60 > minutes)){
        cout<<hours;
    }
    else{
        cout<<minutes;
    }
}
main(){
    cout<<"enter the time in hours";
    int hours;
    cin>>hours;
    cout<<"enter the time in minutes";
    int minutes;
    cin>>minutes;
    longestTime(hours, minutes);
    
}