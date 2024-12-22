#include<iostream>
using namespace std;
main(){
    int age,move;
    cout<<"Enter the person's age : ";
    cin>>age;
    cout<<"Enter the number of times they've moved : ";
    cin>>move;

    int avg= age/(move+1);
    cout<<"Average number of t=years lived in the same house : "<<avg;
}