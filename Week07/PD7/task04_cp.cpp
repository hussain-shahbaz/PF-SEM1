#include<iostream>
using namespace std;
int triangle(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum +=i;
    }
    cout<<"The number of dots are: ";
    return sum;
}
int main(){
    int tri;
    cout<<"Enter the number of triangle: ";
    cin>>tri;
    cout<<triangle(tri);
    return 0;
}