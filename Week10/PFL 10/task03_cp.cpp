#include<iostream>
using namespace std;
void peak(int arr[],int n){
    int j=0;
    int result[n];
    
    for(int i=1;i<n-1;i++){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            result[j] = arr[i];
            j++;
        }
    }
    if(j==0) {
        cout<<"No peaks found ";
        return;
    }
    cout<<"[ ";
    for(int i=0;i<j;i++){
        cout<<result[i]<<" ";
        
    }
    cout<<"]";
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
    peak(arr,n);
    return 0;
}