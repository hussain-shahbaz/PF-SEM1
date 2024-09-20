#include<iostream>
using namespace std;
main(){
    string movie;
    int adult_price, child_price, adult_sold, child_sold, charity;
    cout<<"Enter the movie name : ";
    cin>>movie;
    cout<<"Enter the ticket price for adults $";
    cin>>adult_price;
    cout<<"Enter the ticket price for children $";
    cin>>child_price;
    cout<<"enter the amount of tickets sold to adults : ";
    cin>>adult_sold;
    cout<<"Enter the amount of tickets sold to children : ";
    cin>>child_sold;
    cout<<"Enter the charity %";
    cin>>charity;


    int ttl = adult_price*adult_sold + child_price*child_sold;
    int amount_charity = ttl*charity/100;
    cout<<"Movie name : "<<movie;
    cout<<"Total amount generated : $"<<ttl;
    cout<<"Amount donated to charity (%"<<charity<<") : "<< amount_charity;
    cout<<"Remaining amount : $"<< ttl - amount_charity;
}