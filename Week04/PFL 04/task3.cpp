#include<iostream>
using namespace std;
void numberOFstickers(int  n);
main(){
	cout<<"Enter the number of dimsion";
	float n;
	cin>>n;
	numberOFstickers(n);
}
void numberOFstickers(int n){
	int stickers = n*n * 6;
	cout<<stickers;
}