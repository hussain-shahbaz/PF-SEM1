#include<iostream>
using namespace std;
void flowerShop(int RedRose, int whiterose, int tulip){
    float Red = 2*RedRose;
    float tulips = 2.50*tulip;
    float white = 4.10*whiterose;
    float price = Red + tulips + tulips;
    if(price > 200){
        cout<<"original price : "<<price;
        cout<<"after discount price : "<<price*.80;
    }
    else{
        cout<<"original price : "<<price;
        cout<<"no discount applied";
    }
}
main(){
    int RedRose, whiterose, tulip;
    cout<<"Enter the number of red roses : $";
    cin>> RedRose;
    cout<<"Enter the number of white roses : $";
    cin>> whiterose;
    cout<<"Enter the number of tulips : $";
    cin>> tulip;
    flowerShop(RedRose, whiterose, tulip);
}