#include<iostream>
using namespace std;
main(){
    float holidays;
    cout<<"enter the number of holidays : "<<endl;
    cin>>holidays;
    float working_days = 365 - holidays;
    float total_play = working_days*63 + holidays*127;
    float normal_play = 30000;
    int ttl_minutes = normal_play - total_play;
    int hours = ttl_minutes/60;
    int minutes = ttl_minutes - hours*60;
    if(normal_play - total_play<0){
        cout<<"Tom will run away";
        cout<<(-1)*hours<<" and "<<(-1)*minutes<<" overplayed"<<endl;
    }
    if(normal_play - total_play>=0){
        cout<<"Tom sleeps well";
        cout<<hours<<" and "<<minutes<<" left for play"<<endl;
    }

}