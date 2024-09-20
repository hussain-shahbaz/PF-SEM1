#include<iostream>
using namespace std;
main(){
    float imp, player_count;
    cout<<"enter the number of imposters : ";
    cin>>imp;
    cout<<"enter the number of players : ";
    cin>>player_count;

    float chances = (imp/player_count)*100;
    cout<<"The chances for being an imposter is : "<<chances<<"%";
}