#include<iostream>
#include<fstream>
using namespace std;
int myStoi(string str){
    int number = 0;
    for(int i=0;str[i] != '\0';i++){
        number = number*10 + (str[i] - '0');
    }
    return number;
}
void getBirthdayCake(string fileName){
    fstream file;
    file.open(fileName,ios::in);
    string str;
    getline(file,str);
    file.close();
    string name = "";
    string age = "";
    bool nameDone = false;
    for(int i=0;str[i] != '\n';i++){
        if(str[i] == ','){ nameDone = true; continue;}
        if(!nameDone){
            name += str[i];
        }
        else{
            age += str[i];
        }
    }
    int Age = myStoi(age);
    char ch;
    if(Age%2 == 0){
        ch = '#';
    }
    else ch = '*';
    int n = name.size() + 11;
    for(int i=0;i<n;i++) cout<<ch;
    cout<<endl;
    cout<<ch<<" HB " + name + to_string(Age) + " ! "<<ch<<endl; 
    for(int i=0;i<n;i++) cout<<ch;
    
}
int main(){
    getBirthdayCake("text.txt");
    return 0;
}