#include<iostream>
#include<cmath>
using namespace std;
main(){
    float horizontal_distance, angle_of_elevation;
    cout<<"Enter the horizontal distance (in feet) : ";
    cin>>horizontal_distance;
    cout<<"Enter The angle of elevation (in degrees) : ";
    cin>>angle_of_elevation;
    cout<<"The height of the tree is "<< horizontal_distance*(angle_of_elevation/57.3);
}