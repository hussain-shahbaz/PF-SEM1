#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x,int y){
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void Cursor(int x, int y){
    gotoxy(x,y);
    cout<<"P";
}
main(){
    Cursor(4,5);
}