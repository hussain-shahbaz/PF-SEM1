#include<iostream>
using namespace std;
float calculateFruitPrice(string fruit, string dayOfWeek, double quantity){
    if(dayOfWeek ==  "monday" || dayOfWeek == "tuesday" || dayOfWeek == "wednesday" || dayOfWeek == "thursday" || dayOfWeek == "friday"){
        if(fruit == "banana") return 2.50*quantity;
        else if(fruit == "apple") return 1.20*quantity;    
        else if(fruit == "orange") return 0.85*quantity;    
        else if(fruit == "grapefruit") return 1.45*quantity;    
        else if(fruit == "kiwi") return 2.70*quantity;    
        else if(fruit == "pineapple") return 5.50*quantity;    
        else if(fruit == "grapes") return 3.85*quantity; 
        else return -1;   
    }
    else if(dayOfWeek == "saturday" || dayOfWeek == "sunday"){
        if(fruit == "banana") return 2.70*quantity;
        else if(fruit == "apple") return 1.25*quantity;    
        else if(fruit == "orange") return 0.90*quantity;    
        else if(fruit == "grapefruit") return 1.60*quantity;    
        else if(fruit == "kiwi") return 3.00*quantity;    
        else if(fruit == "pineapple") return 5.60*quantity;    
        else if(fruit == "grapes") return 4.20*quantity; 
        else return -1;
    }
    else return -1;
}
int main(){
    string fruit, day;
  
    cout<<"Enter the fruit name : ";
    cin>>fruit;
    cout<<"Enter the day of the week";
    cin>>day;
    int n;
    cout<<"Enter the quantity fo the fruit : ";
    cin>>n;
    if(calculateFruitPrice(fruit,day,n) == -1){
        cout<<"error";
    }
    else{
        cout<<calculateFruitPrice(fruit,day,n);
    }
    return 0;
}