#include<iostream>
using namespace std;
void reverse(string arr[], int size){
    for(int i=size - 1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}
int main(){
    cout<<"Enter the size of the sentence: ";
    int size;
    cin>>size;
    string arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter word "<<i+1<<": ";
        cin>>arr[i];
    }
    reverse(arr,size);
    return 0;
}