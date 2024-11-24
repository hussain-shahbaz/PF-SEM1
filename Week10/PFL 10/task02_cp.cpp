#include<iostream>
using namespace std;
int countLetters(string words[],int n, char ch){
    int count = 0;
    for(int i=0;i<n;i++){
        string word = words[i];
        for(int j=0;word[j] != '\0';j++){
            if(word[j] == ch) count++;
        }
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter number of words: ";
    cin>>n;
    string words[n];
    for(int i=0;i<n;i++){
        cout<<"Enter word "<<i+1<<" ";
        cin>>words[i];
    }
    char ch;
    cout<<"enter the character you want to count: ";
    cin>>ch;
    cout<<"The letter "<<ch<<" has appeared "<<countLetters(words,n,ch)<<" times";;
    return 0;
}