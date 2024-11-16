#include<iostream>
using namespace std;
int calculateTotalRestistance(int resistance[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += resistance[i];
    }
    return sum;

}
int main(){
    int n;
    cout<<"Enter the number of total resistors: ";
    cin>>n;
    int resistance[n];
    for(int i=0;i<n;i++){
        cout<<"Enter resistance No."<<i+1<<": ";
        cin>>resistance[i];
    }
    cout<<"The total equivalent resistance is: "<<calculateTotalRestistance(resistance,n)<<"ohms.";
    return 0;
}