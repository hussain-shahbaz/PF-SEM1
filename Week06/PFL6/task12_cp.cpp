#include<iostream>
using namespace std;
float totalIncome(string screenType, int rows, int columns){
    if(screenType == "Premiere") return rows*columns*12.00;
    else if(screenType == "Normal") return rows*columns*7.5;
    else if(screenType == "Discounted") return rows*columns*5.00;
}
int main(){
    string screenType;
    int rows, columns;
    cout<<"Enter Your screen Type : ";
    cin>>screenType;
    cout<<"Enter the number of rows : ";
    cin>>rows;
    cout<<"Enter the number of rows : ";
    cin>>columns;
    cout<<totalIncome(screenType,rows,columns);
    return 0;
}