#include<iostream>
using namespace std;
float calculateDamage(string myType, string opponentType, float myAttackPower, float opponentDefense){
    float effectiveness;
    if(myType == "fire"){
        if(opponentType == "grass") effectiveness = 2;
        else if(opponentType == "electric") effectiveness = 1;
        else effectiveness = 0.5;
    } else if(myType== "water"){
        if(opponentType == "grass") effectiveness = 0.5;
        else if(opponentType == "electric") effectiveness = 0.5;
        else effectiveness = 2;
    } else if(myType== "grass"){
        if(opponentType == "fire") effectiveness = 0.5;
        else if(opponentType == "electric") effectiveness = 1;
        else effectiveness = 2;
    }
    float damage = (myAttackPower/opponentDefense) * 50 * effectiveness;
    return damage;
}
int main(){
    string yourType, opponentType;
    float yourAttackPower, opponentDefense;
    cout << "Enter your type: ";
    cin >> yourType;
    cout << "Enter the opponent's type: ";
    cin >> opponentType;
    cout << "Enter your attack power: ";
    cin >> yourAttackPower;
    cout << "Enter the opponent's defense: ";
    cin >> opponentDefense;
    cout<<calculateDamage(yourType,opponentType,yourAttackPower,opponentDefense);
    return 0;
}