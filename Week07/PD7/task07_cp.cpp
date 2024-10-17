#include<iostream>
using namespace std;
int main(){
    int days;
    int treated=0, untreated=0;
    int patients;
    int doctors = 7;
    cout<<"Enter the number of days you visited hospital: ";
    cin>>days;
    for(int i=1;i<=days;i++){
        cout<<"Number of patients who visited hospital on Day" <<i<<": ";
        cin>>patients;
        if(i%3==0 && untreated>treated){
            doctors+=1;
        }
        if(patients>doctors){
            treated += doctors;
            untreated += (patients - doctors);
        }
        else{
            treated += patients;
        }
        
    }
    cout<<"Treated Patients: "<<treated<<endl;
    cout<<"unreated Patients: "<<untreated<<endl;
    
    
    
    
    
    
    
    return 0;
}