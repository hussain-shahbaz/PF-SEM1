#include<iostream>
#include<windows.h>
using namespace std;
int cx = 149, cy = 20;
string direction = "left";
void gotoxy(int x, int y)
{

COORD coordinates;

coordinates.X = x;

coordinates.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}
void print_caveman()
{
  gotoxy(cx, cy);
  cout<< "     .--.       ";     
  gotoxy(cx, cy+1);
  cout<< "   -=:+.+:      "; 
  gotoxy(cx, cy+2);
  cout<< " :=-:===:==:    ";
  gotoxy(cx, cy+3);
  cout<< ":=.+:::.::-==.  ";
  gotoxy(cx, cy+4);
  cout<< "=:  ++++  :=    ";
  gotoxy(cx, cy+5);
  cout<< "==  =+  +=  ==  ";
  gotoxy(cx, cy+6);
  cout<< "   :=  =:       ";
}

void erase_caveman()
{
  gotoxy(cx, cy);
  cout << "               ";
  gotoxy(cx, cy+1);
  cout << "               ";
  gotoxy(cx, cy+2);
  cout << "               ";
  gotoxy(cx, cy+3);
  cout << "               ";
  gotoxy(cx, cy+4);
  cout << "               ";
  gotoxy(cx, cy+5);
  cout << "               ";
  gotoxy(cx, cy+6);
  cout << "               ";
}
void maze()
{
  cout<< "######################################################################################################################################################################"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "#                                                                                                                                                                    #"<< endl;
  cout<< "######################################################################################################################################################################"<< endl;
 
}
string caveman_direction()
{
  
  if(cx == 149)
  {
    direction = "left";
  }
  else if(cx == 50)
  {
    direction = "right";

  }
  return direction;
}
void move_caveman(){
    erase_caveman();
    if(caveman_direction()=="left"){
        cx--;
    }
    if(caveman_direction()=="right"){
        cx++;
    }
    print_caveman();
}









int main(){
    maze();
    while(true){
        print_caveman();
        move_caveman();
        Sleep(10);
    }

    return 0;
}