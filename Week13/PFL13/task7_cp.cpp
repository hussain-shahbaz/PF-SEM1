#include<iostream>
#include<fstream>
using namespace std;
int mySize(string word){
    int count = 0;
    for(int i=0;word[i] != '\0';i++){
        count ++;
    }
    return count;
}
void displayWords(string fileName){
    fstream file;
    file.open(fileName, ios:: in);
    string line;
    string word = "";
    while(!file.eof()){
        getline(file,line);
        for(int i=0;line[i] != '\0';i++){
            if(line[i] != ' '){
                word += line[i];
            } else{
                if(mySize(word) < 4 && word != "") cout<<word<<" ";
                word = "";
            }
        }
        if(mySize(word) < 4 && word != "") cout<<word<<" ";
    }
    file.close();
}
int main(){
    displayWords("task7.txt");
    return 0;
}