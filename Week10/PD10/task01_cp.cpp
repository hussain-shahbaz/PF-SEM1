#include<iostream>
using namespace std;
int abs(int n){
    if(n<0) return -1*n;
    return n;
}
void sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
bool arrangedConsecutive(int arr[], int n){
    sort(arr,n);
    for(int i=1;i<n;i++){
        if(abs(arr[i-1] - arr[i])  != 1) return false;
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter the total amount of numbers: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the numbers: ";
        cin>>arr[i];
    }
    cout<<arrangedConsecutive(arr,n);
    return 0;
}