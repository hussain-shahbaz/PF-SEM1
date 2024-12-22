#include<iostream>
#include<fstream>
using namespace std;
int calculateFrequency(string filename){
    fstream file;
    file.open(filename,ios::in);
    string ch;
    getline(file,ch);
    string str;
    int count = 0;
    while(!file.eof()){
        getline(file,str);
        for(int i=0;str[i] != '\0';i ++){
            if(str[i] == 's' || str[i] == 'S') count++;
        }
    }
    return count;
}
int main(){
    cout << calculateFrequency("task3.txt");
    return 0;
}