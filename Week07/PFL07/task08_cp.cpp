#include<iostream>
using namespace std;
int calculateMoney(int age, int price, int toyPrice){
    int money=0, toy=0;
    int j=1;
    for(int i=1;i<=age;i+=1){
        if(i%2==0){
            money += 10*j;
            money -= 1;
            j++;
        }
        else toy+=1;
    }
    int totalMoney = money + toy*toyPrice;
    int moneyDifference = totalMoney - price;
    if(moneyDifference>0){
        cout<<"Yes!"<<endl;
        return moneyDifference;
    }
    else{
        cout<<"No!"<<endl;
        return -1*(moneyDifference);
    }
    
}
int main(){
    int age, price, toyPrice;
    cout<<"Enter lilly's age: ";
    cin>>age;
    cout<<"Enter the price of the washing machine: ";
    cin>>price;
    cout<<"Enter the uit price of each toy: ";
    cin>>toyPrice;
    cout<<calculateMoney(age,price,toyPrice);
    return 0;
}