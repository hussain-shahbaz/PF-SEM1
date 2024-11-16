#include<iostream>
using namespace std;
int main(){
    string word;
    
    getline(cin,word);
    for(int i=0;word[i] !='\0';i++){
        cout<<word[i]<<" is present at "<<i<<endl;
    }
    return 0;
}