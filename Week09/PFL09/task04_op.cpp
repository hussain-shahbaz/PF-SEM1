#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";          
    cin>>n;
    if(n<=0){
        cout<<"invalid";
        return 0;
    }
    int a[n];
     
    for(int i=0;i<n;i++){
        cout<<"Enter a number: ";
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        cout<<a[i]<<endl;
    }
    return 0;
};