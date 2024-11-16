#include<iostream>
using namespace std;
int countDigits(int num){
    int count = 0;
    while(num>0){
        num /= 10;
        count++;
    }
    return count;
}
void danceMoves(string PIN){
    string MOVES[10] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado",
    "Pop", "Lock", "Arabesque"};
    if(PIN.size() != 4 || !isdigit(PIN[0]) || !isdigit(PIN[1]) || !isdigit(PIN[2]) || !isdigit(PIN[3])){
        cout<<"Invalid Input"<<endl;
        return;
    }
    for(int i=0;i<4;i++){
        int digit = PIN[i] - '0';
        cout<<MOVES[(i+digit) % 10]<<" ";
    }
}
int main(){
    cout<<"Enter PIN: ";
    string PIN;
    cin>>PIN;
    danceMoves(PIN);
    return 0;
}