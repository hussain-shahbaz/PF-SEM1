#include<iostream>
#include<fstream>
using namespace std;
void getMissingAlphabets(string fileName){
    char alphabets[26];
    for(int i=0;i<26;i++) alphabets[i] = 'a' +i;
    
    for(int i=0;i<26;i++) cout<<alphabets[i];
    fstream file;
    file.open(fileName, ios :: in);
    string str;
    getline(file,str);
    for(int ch = 0;str[ch] != '\0';ch++){
        for(int i=0;i<26;i++){
            if(str[ch] == alphabets[i]) alphabets[i] = '0';
        }
    }
    file.close();
    char ch;
    file.open(fileName,ios :: out);
    file<< endl;
    for(int i=0;i<26;i++){
        if(alphabets[i] != '0'){
            ch = i + 'a'; 
            file << ch;
        }
    }
    file.close();
}
int main(){
    getMissingAlphabets("alphabets.txt");
    return 0;
}