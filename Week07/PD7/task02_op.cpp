#include<iostream>
using namespace std;
void halfDiamond(int row){
    row=row/2;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=(row-i);j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=row;i>=1;i--){
        for(int j=1;j<=(row-i);j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int row;
    cout<<"Enter the number of rows: ";
    cin>>row;
    halfDiamond(row);
    return 0;
}