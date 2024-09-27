#include<iostream>
#include<windows.h>
using namespace std;
void singleline(){
	cout<<"############################################################"<<endl;
}
void borders(){
	cout<<"#                                                          #"<<endl;
}                                                        
void maze(){
	singleline();
	for(int i=0;i<15;i++){
		borders();
	}
	singleline();
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
void printQ(int x,int y){
	gotoxy(x,y);
	cout<<"Q";
	Sleep(100);
	gotoxy(x,y);
	cout<<" ";
}
void printchar(int x, int y){
    printP(x,y);
    printQ(x,y+1);
}
main(){
	maze();	
	int i=1;
	while(true){
		while(true){
			printP(i,3);
			i++;
			if(i==58){
				break;
			}
		}
		while(true){
			printP(i,3);
			i--;
			if(i==1){
				break;
			}
		}
	}
}