#include<iostream>
#include<fstream>
using namespace std;
int countLines(string fileName){
    fstream file;
    file.open(fileName, ios::in);
    string line;
    int count =0;
    char ch;   
    getline(file,line);
    ch = line[0];
    while(!file.eof()){
        getline(file,line);
       
        if(line[0] != ch) count++;
    }
    return count;
}
int main(){
    cout<<countLines("task6.txt");
    return 0;
    
}