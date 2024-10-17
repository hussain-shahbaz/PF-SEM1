#include<iostream>
using namespace std;
void printfibbanoci(int n){

    int n1=0,n2=1;
    
    if(n == 1){
        cout<<n1;
        return;
    }   
    int next;  
    cout<<n1<<", "<<n2;
    for(int i=2 ;i<n;i++){
        next = n1+n2;
        n1=n2;
        n2=next;
        cout<<", "<<next;
    }
    
}
int main(){
    int n;
    cout<<"Enter the number of terms of fibbanocci numbers: ";
    cin>>n;
    printfibbanoci(n);
    return 0;
}