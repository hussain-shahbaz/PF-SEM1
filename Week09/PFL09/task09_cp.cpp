#include<iostream>
using namespace std;
bool canPayWithChange(double change[],double amount){   
    double coins[4] = {.25,.10,.05,.01};
    int sum = 0;
    for(int i=0;i<4;i++){
        sum+= change[i]*coins[i];
    }
    return sum == amount;
}
int main(){
    int amount;
    double arr[4];
    cout<<"Enter quaters: ";
    cin>>arr[0];
    cout<<"Enter dimes: ";
    cin>>arr[1];
    cout<<"Enter Nickels: ";
    cin>>arr[2];
    cout<<"Enter pennies: ";
    cin>>arr[3];
    cout<<"Enter amount due: $";
    cin>>amount;
    bool answer = canPayWithChange(arr,amount);
    cout<<"can we pay the change? ";
    if(answer) cout<<"Yes";
    else cout<<"No";


    return 0;
}