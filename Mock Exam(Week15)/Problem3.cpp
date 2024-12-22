#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main(){
    double a, b;
    cout<<"enter first number: ";
    cin>>a;
    cout<<"enter second number: ";
    cin>>b;
    fstream inputFile,outputFile;
    inputFile.open("input3.in",ios::out);
    inputFile << a <<" " << b;
    inputFile.close();

    double sum = a + b;
    double difference = a - b;
    double product = a * b;
    double quotient = a / b; 
     
    outputFile.open("output3.in",ios::out);
    outputFile << "sum : "<<setprecision(3) << sum<< "\n";
    outputFile << "difference : "<<setprecision(3) << difference<< "\n";
    outputFile << "product : "<<setprecision(3) << product<< "\n";
    outputFile << "quotient : "<<setprecision(3) << quotient<< "\n";
    outputFile.close();

    return 0;
}