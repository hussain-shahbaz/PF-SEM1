#include<iostream>
using namespace std;
string checkPointPosition(int h, int x, int y){
    string answer;
    if((x > 0 && x < h && y > 0 && y < h) || (x > h && x < 2 * h && y > 0 && y < 4 * h) || (x > 0 && x < h && y > 2 * h && y < 4 * h)) answer = "inside";
    else if((x == 0 && y >= 0 && y <= h) || 
        (x == h && y >= 0 && y <= 4 * h) || 
        (x == 2 * h && y >= 0 && y <= 3 * h) || 
        (y == 0 && x >= 0 && 
        
        x <= 2 * h) || 
        (y == h && x >= 0 && x <= 2 * h) ||
        (y == 2 * h && x >= h && x <= 2 * h) ||
        (y == 3 * h && x >= h && x <= 2 * h) || 
        (y == 4 * h && x >= h && x <= 2 * h)) answer =  "border";
    else answer =  "outside";
    return answer;
}
int main(){
    int x,y,h;
    cout<<"Enter the x-coordinate: ";
    cin>>x;
    cout<<"Enter the y-coordinate: ";
    cin>>y;
    cout<<"Enter the height: ";
    cin>>h;
    cout<<checkPointPosition(x,y,h);
    return 0;
}