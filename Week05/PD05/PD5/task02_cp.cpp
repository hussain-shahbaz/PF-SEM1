#include<iostream>
#include<cmath>
using namespace std;
double volumePyramid(double, double,double,string);
main(){
    double width;
    cout<<"Enter the width of the pyramid (in metres) : ";
    cin>>width;
    double height;
    cout<<"Enter the height of the pyramid (in metres) : ";
    cin>>height;
    double lenght;
    cout<<"Enter the lenght of the pyramid (in metres) : ";
    cin>>lenght;
    string units;
    cout<<"Enter the units (centimetres, millimetres, kilometres, metres) : ";
    cin>>width;
    cout<<volumePyramid(width,height,lenght, units);

}
double volumePyramid(double l, double w, double h, string unit){
    double volume = (1/3)*l*w*h;
    if(unit == "centimetres") return (volume * pow(10,-6));
    else if(unit == "millimetres") return (volume * pow(10,-9));
    else if(unit == "kilometres") return (volume * pow(10,9));
    else if(unit == "metres") return (volume);
    cout<<" cubic"<<unit<<"s";
    else cout<<"Please enter a valid unit";

}