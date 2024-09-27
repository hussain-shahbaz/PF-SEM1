#include<iostream>
#include<windows.h>
using namespace std;
void maze(){
    system("cls");
    cout<<"############################################################"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"#                                                          #"<<endl;
    cout<<"############################################################"<<endl;
}
void gotoxy(int x,int y){
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printP(int x,int y){
	gotoxy(x,y);
	cout<<"P";
	Sleep(10000);
	gotoxy(x,y);
	cout<<" ";
}
main(){
    maze();
    printP(4,3);
    gotoxy(0,15);

}