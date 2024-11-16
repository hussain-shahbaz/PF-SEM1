#include<iostream>
using namespace std;    
bool isEvenOrOdd(string s){
    int len = 0;
    for(int i=0;s[i] != '\0';i++){
        len++;
    }
    if(len%2==0) return true;
    return false;

}
int main(){
    string s;
    cout<<"enter a string: ";
    cin>>s;
    cout<<isEvenOrOdd(s);
    return 0;
}