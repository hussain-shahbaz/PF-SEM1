#include<iostream>
using namespace std;
void Reverse(string input){
    if(input == "true"){
        cout<<false;
    }
    if(input == "false"){
        cout<<"True";
    }
}
main(){
    cout<<"enter the input"<<endl;
    string input;
    cin>>input;
    Reverse(input);
}