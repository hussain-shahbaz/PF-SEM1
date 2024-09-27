#include<iostream>
using namespace std;
void inchesToFeet(float n);
main(){
	float n;
	cin>>n;
	inchesToFeet(n);
}
void inchesToFeet(float n){
	float inches;
	float feet = inches/12;
	cout<<feet;
}