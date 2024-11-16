#include<iostream>
using namespace std;
int main(){
    string fruits[4] = {"peach" , "apple", "guava","watermelon"};
    int price[4] = {60,70,40,30};
    cout<<"Enter the name of the fruit: ";
    string fruit;
    cin>>fruit;
    cout<<"Enter the quantity in Kgs: ";
    int kgs;
    cin>>kgs;
    int fr = -1;
    for(int i=0;i< 4;i++){
        if(fruit == fruits[i]){
            fr = i;
            break;
        }
    }
    if(fr != -1) 
        int totalPrice = price[fr]*kgs;
    cout<<"Total Bill:\t"<<totalPrice<<endl;

    return 0;
}