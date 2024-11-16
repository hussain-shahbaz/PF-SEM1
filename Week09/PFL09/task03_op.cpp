#include<iostream>
using namespace std;
int main(){
    string word;
    cout<<"Enter a word: ";
    cin>>word;
    int asci;
    char character; 
    for(int i=0; word[i] != '\0';i++){
        if(word[i] == 'z') cout<<'a';
        else{
            asci = word[i] + 1;
            character = asci;
            cout<<character;
        }
    }
    return 0;
}