#include<iostream>
using namespace std;
float perimetre(char shape, float value){
    
    if(shape == 'C'){
        return 6.28*value;
    }
    else if(shape == 'S'){
        return 4*value;
    }
    else if(shape == 'T'){
        return 3*value;
    }
    else if(shape == 'H'){
       return 6*value;
    }
    
}
int main(){
    float value;
    char shape;
    cout<<"Enter the char for the shape : \n C for Circle\nT for triangle(equilateral)\nH for hexagon\nS for square : "<<endl;
    cin>>shape;
    cout<<"Enter the value of one side of the shape(radius in csse of circle)";
    cin>>value;
    cout<<"THe perimetre is : "<<perimetre(shape, value)<<"Units.";
    return 0;
}