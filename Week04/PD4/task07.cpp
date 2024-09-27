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
	Sleep(100);
	gotoxy(x,y);
	cout<<" ";
}
main(){
    maze();	
	int i=1;
	while(true){
		while(true){
			printP(5,i);
			i++;
			if(i==9){
				break;
			}
		}
		while(true){
			printP(5,i);
			i--;
			if(i==1){
				i=1;
				break;
			}
		}
	}
}