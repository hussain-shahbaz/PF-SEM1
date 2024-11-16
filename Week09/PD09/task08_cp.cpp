#include<iostream>
using namespace std;
int color(string s[],int size){
    int time=size*2;
    for(int i=1;i<size;i++){
        if(s[i-1] != s[i]) time ++;
    }
    return time;
}
int main(){
    cout<<"Enter the size of the string array: ";
    int size;
    cin>>size;
    string arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter string: ";
        cin>>arr[i];
    }
    cout<<"The time required to paint is "<<color(arr,size)<<"s";
    return 0;
}