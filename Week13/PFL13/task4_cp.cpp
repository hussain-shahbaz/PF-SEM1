#include<iostream>
#include<fstream>
using namespace std;
void saveToFile(string names[], int ages[], float matricMarks[], float fscMarks[], float ecatMarks[], int count, string fileName){
    fstream file;
    file.open(fileName,ios::out);
    for(int i=0;i<count;i++){
        file << "Name: " <<names[i] << endl;
        file << "Age: "<< ages[i] << endl;
        file << "Matric Marks: "<< matricMarks[i] << endl;
        file << "fscMarks: " << fscMarks[i] << endl;
        file << "ecatMarks: " << ecatMarks[i] << endl;
        file << "------------------------" << endl;
    }
    file.close();
}

void getStudentDetails(string names[], int ages[], float
matricMarks[], float fscMarks[], float ecatMarks[], int size, int 
&count){
    string choice;
    
    while(count < size){
        
        cout<<"Enter students name: ";
        cin.ignore();
        getline(cin,names[count]);
        cout<<"Enter students age: ";
        cin>>ages[count];
        cout<<"Enter students score in Matric: ";
        cin>>matricMarks[count];
        cout<<"Enter students score in FSC: ";
        cin >> fscMarks[count];
        cout<<"Enter students score in ECAT: ";
        cin>>ecatMarks[count];
        
        count ++;
        cout<<"Do you want to add another student: (Yes or No)"<<endl;
        cin>>choice;
        if(choice ==  "no"){
            cout<<"Information saved successfully";
            break;
        }
    }
    if(count == size){
        cout<<"You cant add more students. ";
    }
}
int main(){
    const int userCount = 10;
    string names[userCount];
    int ages[userCount];
    float matricMarks[userCount];
    float fscMarks[userCount];
    float ecatMarks[userCount];
    int count = 0;
    getStudentDetails(names,ages,matricMarks,fscMarks,ecatMarks,userCount, count);
    saveToFile(names,ages,matricMarks,fscMarks,ecatMarks,count,"student.txt");
    return 0;
}