#include<iostream>
using namespace std;
string something(string str){
    return "something " + str;
}
int main(){
    cout<<"Enter an argument: ";
    string arg;
    getline(cin,arg);
    cout<<something(arg);
    return 0;
}