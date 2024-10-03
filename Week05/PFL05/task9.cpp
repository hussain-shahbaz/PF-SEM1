#include<iostream>
using namespace std;
void checkAlphabet(char);
main(){
    cout<<"Enter an alphabet(A/a)";
    char character;
    cin>>character;
    checkAlphabet(character);
}
void checkAlphabet(char character){
    if(character == 'a'){
        cout<<"You have entered Small a";
    }
    if(character == 'A'){
        cout<<"You have entered Capital A";
    }
}