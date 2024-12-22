#include<iostream>
#include<fstream>
using namespace std;
int countCharacters(string fileName){
    fstream file;
    file.open(fileName, ios::in);
    string line;
    int count =0;
    while(!file.eof()){
        getline(file,line);
        for(int i=0; line[i]!= '\0';i++) count++;
    }
    return count;
}
int main(){
    cout<<countCharacters("task2.txt");
    return 0;
}