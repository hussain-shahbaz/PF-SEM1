#include<iostream>
using namespace std;
void swapUsingReferences(int& a, int& b){
    a = a + b;
    b = a - b;
    a = a - b;
}
int main(){
    int x,y;
    cout<<"Enter the value of x; ";
    cin>>x;
    cout<<"Enter the value of y; ";
    cin>>y;
    swapUsingReferences(x,y);
    cout<<"the value of x: "<<x <<endl;
    cout<<"the value of y: "<<y<<endl;
    return 0;
}