#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter number for index "<<i<<": ";
        cin>>arr[i];
    }
    cout<<"Array: ";
    for(int i=0;i<n;i++){
        if(i == n-1) cout<<arr[i];
        else cout<<arr[i]<<",";
    }
    return 0;
}