#include<iostream>
using namespace std;
bool sevenChecker(int n){
    while(n!=0){
        int digit = n%10;
        if(digit==7) return true;
        n /= 10;
    }
    return false;
}
void boom(int arr[],int size){
    for(int i=0;i<size;i++){
        if(sevenChecker(arr[i])){
            cout<<"BOOM!";
            return;
        }
    }
    cout<<"There is no 7";
}
int main(){
    cout<<"Enter the size of the array: ";
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter Number: ";
        cin>>arr[i];
    }
    boom(arr,size);
    return 0;
}