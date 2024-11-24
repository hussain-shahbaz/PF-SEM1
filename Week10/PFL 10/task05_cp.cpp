#include<iostream>
using namespace std;
int volumeBoxes(int arr[],int n){
    if(n%3 != 0){
        return -1;
    }
    int totalVolume = 0;
    for(int i=0;i<n;i += 3){
        int volume = 1;
        for(int j=i;j<i+3;j++){
            volume *= arr[j];
        }
        totalVolume += volume;
    }
    return totalVolume;}
int main(){
    int n;
    cout<<"Enter the total amount of numbers: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the numbers: ";
        cin>>arr[i];
    }
    cout<<volumeBoxes(arr,n)<<" cubic units";
    return 0;
}