#include<iostream>
using namespace std;
void printName(string name){
    cout<<name;
}
main(){
    string name;
    cout<<"enter your name";
    cin>>name;
    while(true){
        printName(name);
    }
}