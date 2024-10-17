#include<iostream>
using namespace std;
void diamond(int row){
    for(int i=row;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int row;
    cout<<"Enter the number of rows: ";
    cin>>row;
    diamond(row);
    return 0;
}