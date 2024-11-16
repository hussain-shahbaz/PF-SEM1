#include<iostream>
using namespace std;
int findLargest(int arr[], int n){
    int largest = INT_MIN;
    for(int i=0;i<n;i++){
        largest = max(largest, arr[i]);
    }
    return largest;
}
int main(){
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Number: ";
        cin>>arr[i];
    }
    cout<<"The largest number in the array is: "<<findLargest(arr,n);
    return 0;
}