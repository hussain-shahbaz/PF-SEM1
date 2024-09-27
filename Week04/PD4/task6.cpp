#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x,int y){
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printHussain(){
    gotoxy(40,9);
    cout << "###  ###      ###  ###      ######       ######        ######       ###      ##   ###" << endl;
    gotoxy(40,10);
    cout << "###  ###      ###  ###      ###          ###          ###  ###      ###      ###  ###" << endl;
    gotoxy(40,11);
    cout << "########      ###  ###       #####        #####       ########      ###      ########" << endl;
    gotoxy(40,12);
    cout << "###  ###      ###  ###          ###          ###      ###  ###      ###      ### ####" << endl;
    gotoxy(40,13);
    cout << "###  ###       #####       ######       ######        ###  ###      ###      ###  ###" << endl;
}
main(){
    printHussain();
    gotoxy(0,1000);
}
