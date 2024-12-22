#include<iostream>
#include<fstream>
using namespace std;
int countLines(string fileName){
    fstream file;
    file.open(fileName,ios:: in);
    string str;
    int count = 0;
    while(!file.eof()){
        getline(file,str);
        count++;
    }
    file.close();
    return count;
}
int main(){
    
    cout<<countLines("task1.txt");
    return 0;
}