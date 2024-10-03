#include<iostream>
#include<cmath>
using namespace std;
void solutions_quadratic(float,float,float);
main(){
    float a,b,c;
    cout<<"Enter the value of 'a' : ";
    cin>>a;
    cout<<"Enter the value of 'b' : ";
    cin>>b;
    cout<<"Enter the value of 'c' : ";
    cin>>c;
    cout<<"The Quadratic equation is : "<<a<<"x^2 + "<<b<<"x + "<<c<<endl;
    solutions_quadratic(a,b,c);
}
void solutions_quadratic(float a,float b, float c){
    float disc = pow(b,2)-4*a*c;
    float root1, root2;
    if(disc>0){
        root1 = (-b + pow(disc,0.5))/(2*a);
        root2 = (-b - pow(disc,0.5))/(2*a);
        cout<<"x1 = "<<root1<<endl;
        cout<<"x2 = "<<root2<<endl;
    }
    if(disc<0){
        cout<<"Complex Solutions :"<<endl;
        disc = -1 * disc;
        cout<<"x1 = "<<(-b/2*a)<<" + "<< (pow(disc,0.5)/(2*a))<<" i"<<endl;
        cout<<"x2 = "<<(-b/2*a)<<" - "<< (pow(disc,0.5)/(2*a))<<" i"<<endl;
    }
    if(disc=0){
        root1 = (-b)/(2*a);
        cout<<"x = "<<root1;
    }
}