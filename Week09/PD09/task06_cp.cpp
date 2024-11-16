#include<iostream>
using namespace std;
void evenOddTransofrmation(int arr[], int size, int times){
    for(int x=0;x<times;x++){
        for(int i=0;i<size;i++){
            if(arr[i]%2==0) arr[i]-=2;
            else arr[i]+=2;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
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
    cout<<"Enter number of times transormation need to be done: ";
    int times;
    cin>>times;
    evenOddTransofrmation(arr,size,times);
    return 0;
}