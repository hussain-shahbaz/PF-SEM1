#include<iostream>
using namespace std;
int abs(int n){
    if(n<0) return -1*n;
    return n;
}
int rotation(string arr[], int n){
    int check;
    for(int i=0;i<n;i++){
        if(arr[i] == "left") check += 1;
        else check -= 1;
    }
    check = abs(check)/4;
    return check;
}
int main(){
    cout<<"Enter the number of rotation: ";
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter direction: ";
        cin>>arr[i];
    }
    cout<<"Total rotations: "<<rotation(arr,n);
    return 0;
}