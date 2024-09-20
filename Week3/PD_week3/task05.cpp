#include<iostream>
using namespace std;
main(){
    string name;
    int weight;
    cout<<"Enter your name : ";
    cin>>name;
    cout<<"Enter the weight you want to lose : ";
    cin>>weight;

    int days= weight * 15;
    cout<<name<<" will lose "<<weight<<" kgs in "<<days<<" days adhering strictly to the doctors instructions";
}