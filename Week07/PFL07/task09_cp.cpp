#include<iostream>
using namespace std;
int calculatePrice(int money, int year){
    int spentMoney=0;
    int age=18;
    for(int i=1800;i<=year;i++){
        if(i%2==0){
            spentMoney += 12000;
        }
        else{
            spentMoney += (12000+50*age);
        }
        age++;
    }
    int remainingMoney = money - spentMoney;
    if(remainingMoney>0){
        cout<<"Yes! He will live a carefree life and will have "<<remainingMoney<<" Dollars left"<<endl;
    }
    else{
        cout<<"No! He will have to earn  "<<-1*remainingMoney<<" Dollars more."<<endl;
    }
}
int main(){
    int money,year;
    cout<<"Enter Money: ";
    cin>>money;
    cout<<"Enter Year: ";
    cin>>year;
    cout<<calculatePrice(money,year);
    return 0;
}