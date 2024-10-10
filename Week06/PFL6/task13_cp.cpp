#include<iostream>
using namespace std;
float lowestPrice(string time, int kms){
    float taxiRate,trainRate,busRate;
    if(kms>=100)  return 0.06*kms;
    if(kms>=20)  return 0.09*kms;
    if(time == "day") return .7 + .79*kms;
    if(time == "Night") return .7 + .9*kms;


}
int main(){
    int kms;
    string time;
    cout<<"Enter the time of travel(Day/Night)";
    cin>>time;
    cout<<"Enter the number of kilometres : ";
    cin>>kms;
    cout<<"Your lowest price for " <<kms<< "kms is "<<lowestPrice(time,kms);
    return 0;
}