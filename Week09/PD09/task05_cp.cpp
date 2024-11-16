#include<iostream>
using namespace std;
bool stringChecker(string arr[], int size){
    for(int i=1;i<size;i++){
        if(arr[i-1] != arr[i]) return false;
    }
    return true;
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
    cout<<stringChecker(arr,size); 
    return 0;
}