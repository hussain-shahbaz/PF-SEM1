#include<iostream>
using namespace std;
main(){
    int weight, cost, area;
    cout<<"Enter the weight of the fertilizer bag in kgs : ";
    cin>>weight;
    cout<<"Enter the cost of the bag in $ : ";
    cin>>cost;
    cout<<"Enter the area in square feet : ";
    cin>>area;
    int cost_per_kg = cost/weight;
    int fertilizing_per_area= cost/area;

    cout<<"cost per kg for fertilizing is : $"<<cost_per_kg<<endl;
    cout<<"cost of fertilizing per square foot is : $"<<fertilizing_per_area;
}