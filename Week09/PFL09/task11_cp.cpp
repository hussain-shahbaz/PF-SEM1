#include<iostream>
using namespace std;
string removeCharAtIndex(string str,int indexToRemove){
    int size = str.size();
    for(int i=indexToRemove;i<=size-2;i++){
        str[i] = str[i+1];
    }
    str = str.substr(0,size-1);
    return str;
}
string removeVowels(string str){
    char vowels[5] = {'a','e','i','o','u'};
    for(int i=0;i<str.size();i++){
        for(int k=0;k<5;k++){
            if(str[i] == vowels[k]){
                str = removeCharAtIndex(str,i);
                i--;
                break;
            }
        }
    }
    return str;
}
int main(){
    cout<<"Enter a string: ";
    string str;
    getline(cin,str);
    cout<<"string with vowels removed: "<<removeVowels(str);
    return 0;
}