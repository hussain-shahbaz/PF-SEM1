#include<iostream>
#include<fstream>
using namespace std;
string getData(string fileName){
    fstream file;
    file.open(fileName,ios::in);
    string str;
    getline(file,str);
    file.close();
    string answer = "";
    int commaCount = 0;
    for(int i=0;str[i] != '\0';i++){
        if(str[i] == '"'){
            commaCount ++;

        }
        else if(commaCount == 1){
            answer += str[i];
        }
        else if(commaCount == 2) break;
    }
    if(answer.size() == 0) return "Why did you make this";
    return answer;
}
int main(){
    cout<<getData("data.txt");
    return 0;
}