#include<iostream>
using namespace std;
string checkTitle(char gender, float age){
    if(gender == 'm'){
        if(age>=16) return "Mr.";
        else return "Master.";
    }
    if(gender == 'f'){
        if(age>=16) return "Miss.";
        else return "Ms.";
    }
}
int main(){
    float age;
    char gender;
    cout<<"ENter your gender(m/f) : ";
    cin>>gender;
    cout<<"Enter your age : ";
    cin>>age;
    cout<<"Your personal Title is "<<checkTitle(gender, age);
    return 0;
}