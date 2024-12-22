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
void getStudentDetails(string names[], int adNumbers[], int
percentages[], int size, int &count, string fileName){
        fstream file;
        file.open(fileName, ios:: in);
        string perc;
        string ad;
        
        while(!file.eof()){
            getline(file,names[count]);
            getline(file, ad);
            adNumbers[count] = myStoi(ad);
            getline(file,perc);
            percentages[count] = myStoi(perc);
            count++;
        }
        file.close();
}
void saveToFile(string names[], int adNumbers[], int
percentages[], int count, string fileName){
    fstream file;
    file.open(fileName,ios::out);
    for(int i=0;i<count;i++){
        if(percentages[i] < 70) continue;
        file << "Name: " <<names[i] << endl;
        file << "Admission No: " << adNumbers[i] << endl;   
        file << "percentage: " << percentages[i] << endl;   
    }
    file.close();
}
int main(){
    const int userCount = 10;
    string names[userCount];
    int adNumbers[userCount];
    int percentages[userCount];
    int count = 0;
    getStudentDetails(names,adNumbers, percentages, userCount, count, "task5.txt");
    saveToFile(names, adNumbers,percentages,count,"toppers.txt");
    return 0;
}