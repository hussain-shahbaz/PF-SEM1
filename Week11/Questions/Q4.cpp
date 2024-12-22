#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int x,y;
    cout<<"Enter the value of x; ";
    cin>>x;
    cout<<"Enter the value of y; ";
    cin>>y;
    swap(x,y);
    cout<<"the value of x: "<<x <<endl;
    cout<<"the value of y: "<<y<<endl;
    return 0;
}