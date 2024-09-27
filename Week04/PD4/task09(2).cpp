#include<iostream>
using namespace std;
void tpChecker(int people, int tp){
    int tissue_roll = 500;
    int ttl_tissue = tissue_roll*tp;
    int daysLeft = ttl_tissue/(people*57);
    if(daysLeft<14){
        cout<<"your TP will last only "<<daysLeft<<" days, buy more";
    }
    if(daysLeft>=14){
        cout<<"your TP will last "<<daysLeft<<" days, No need to panic";
    }
}
main(){
    cout<<"enter the numner of people in your household"<<endl;
    int people;
    cin>>people;
    
    cout<<"enter the rolls of TP"<<endl;
    int tp;
    cin>>tp;
    tpChecker(people, tp);

}