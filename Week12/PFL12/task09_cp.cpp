#include<iostream>
#include<windows.h>
using namespace std;
void swap(char &a,char &b){
    char temp = a;
    a = b;
    b = temp;
}
char spareArr[5] = {'-','-','-','-','-'};
char objects[5][5] = {
                    {'-', '#', '#', '-', '#'},
                    {'-', '-', '-', '#', '-'},
                    {'-', '#', '-', '#', '-'},
                    {'#', '-', '#', '-', '#'},
                    {'#', '-', '-', '-', '-'}
                    };
bool gravity = false;
void displayWorld(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<objects[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool setGravityStatus(bool status){
    gravity = status;
}
void applyGravity(){
    for(int col=0;col<5;col++){
        for(int row = 3;row >=0;row--){
            if(objects[row][col] == '#' && objects[row+1][col] == '-') swap(objects[row][col], objects[row+1][col]);
            if(objects[row][col] == objects[row+1][col]) continue;
        }

    }
}
void tickTime(int n){
    for(int i=0;i<n;i++){
        if(gravity){
            applyGravity();
        }
    }
}


int main(){
    displayWorld();
    setGravityStatus(true);
    tickTime(3);
    cout<<endl<<endl<<endl;
    displayWorld();


    return 0;
}