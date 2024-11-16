#include<iostream>
using namespace std;
int main(){
    string movies[5] = {"Gladiator", "StarWars", "Terminator", "TakingLives", "TombRider"};
    string movie;
    cout<<"Enter the name of the movie: ";
    cin>>movie;
    int price = 500;
    int disc;
    for(int i=0;i<5;i++){
        if(movie == movies[i]){
            disc = i;
        }
    }
    if(disc%2==0) cout<<"Your total Bill is Rs."<< price*.9;
    else cout<<"Your total Bill is Rs."<< price*.95;

    return 0;
}