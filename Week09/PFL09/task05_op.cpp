#include<iostream>
using namespace std;
bool isAlreadyEntered(int arr[], int n, int m){
    for(int i=0;i<n;i++){
        if(arr[i] == m) return true;
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Number: ";
        cin>>arr[i];
        if(isAlreadyEntered(arr,i,arr[i])){
            cout<<"Already Entered: "<<arr[i]<<endl;
        }
    }
    cout<<"UniqueNumbers: ";
    for(int i=0;i<n;i++){
        if(isAlreadyEntered(arr,i,arr[i])) continue;
        else cout<<arr[i]<<" ";
    }
    return 0;
}