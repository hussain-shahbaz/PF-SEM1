#include<iostream>
using namespace std;
string decideActivity(string temp, string humidity){
    
    if(temp == "cold"){
        if(humidity=="dry") return "basketball";
        else return "watch TV";
    }
    if(temp == "warm"){
        if(humidity=="dry") return "Tennis";
        else return "Tennis";
    }
}
int main(){
    string temp, humidity;
    cout<<"Enter the temparature(warm or cold)";
    cin>>temp;
    cout<<"Enter the Humidity(dry or humid)";
    cin>>humidity;
    cout<<"Recommended activity"<<decideActivity(temp, humidity);
    return 0;
}