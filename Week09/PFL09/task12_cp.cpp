#include<iostream>
using namespace std;
bool isSpecial(int arr[],int size){
    for(int i=0;i<size;i++){
        if(i%2==0){
            if(arr[i]%2 != 0) return false;
        }
        else{
            if(arr[i]%2 == 0) return false;
        }
    }
    return true;
}
int main(){
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter number: ";
        cin>>arr[i];
    }
    if(isSpecial(arr,n)) cout<<"Array is special.";
    else cout<<"array is not special.";
    
    return 0;
}