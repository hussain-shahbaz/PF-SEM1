#include <iostream>
using namespace std;
void calculatePoolState(float,float,float,float);
int main()
{
    float volume, flowRate1,flowRate2,hours;
    cout << "Enter volume of the pool in litres: ";
    cin >> volume;
    cout << "Enter flow rate of the first pipe per hour: ";
    cin >> flowRate1;
    cout << "Enter flow rate of the second pipe per hour: ";
    cin >> flowRate2;
    cout << "Enter hours that the worker is absent: ";
    cin >> hours;
    calculatePoolState(volume, flowRate1,flowRate2,hours);

}
void calculatePoolState(float volume,float flowRate1,float flowRate2,float hours){
    int filledUpVolume = (flowRate1+flowRate2)*hours;
    if(filledUpVolume < volume){
        cout<<"The pool is "<<(filledUpVolume/volume)*100<<" % filled up. The volume filled by Pipe 1 is "<< ((flowRate1*hours)/filledUpVolume)*100<<"% and the volume filled by pipe 2 is "<<((flowRate2*hours)/filledUpVolume)*100<<"%"<<endl;
    }
    else{
        cout<<"For "<<hours<<", the pool has overflowed "<<filledUpVolume - volume<<" litres";
    }
}