#include<iostream>
using namespace std;
bool check(string str,char letter){
    for(int i=0; i!= '/0';i++){
        if(str[i] == letter) return true;           
    }
    return false;
}
int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    char letter;
    cout<<"Enter a letter: ";
    cin>>letter;
    if(check(str,letter)) cout<<"Letter is present in string";
    else cout<<"not present!";
    return 0;
}