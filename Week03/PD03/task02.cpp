#include<iostream>
using namespace std;
main(){
    int fps,minutes;
    cout<<"Enter minutes : ";
    cin>>minutes;
    cout<<"Frames per second : ";
    cin>>fps;

    int f= fps*minutes*60;
    cout<<"number of frames : "<<f;
}