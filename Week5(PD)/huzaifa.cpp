#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int, int);
void maze();

void print_caveman();
void erase_caveman();

void movecaveman();
string caveman_direction();

bool caveman_directionRight=false;


void print_soldier(int, int);
void erase_soldier(int, int);
void movesoldier(int, int);
void updown_soldier(int, int);

void ufo();

void robot();


int cx = 149;
int cy = 15;
string direction = "left";
main()
{
  system("cls");
  maze();
  
  while(true)
  { 
    // print_caveman();
    movecaveman();
    Sleep(10);
  }

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


void movecaveman()
{
 erase_caveman();
  if(caveman_direction() == "left"){
    cx--;
  }
  else if(caveman_direction()=="right"){
    cx++;
  }
  print_caveman();


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



void print_caveman()
{
  gotoxy(cx, cy);
  cout<< "     .--.      ";     
  gotoxy(cx, cy+1);
  cout<< "   -=:+.+:   "; 
  gotoxy(cx, cy+2);
  cout<< " :=-:===:==: ";
  gotoxy(cx, cy+3);
  cout<< ":=.+:::.::-==. ";
  gotoxy(cx, cy+4);
  cout<< "=:  ++++  := ";
  gotoxy(cx, cy+5);
  cout<< "==  =+  +=  == ";
  gotoxy(cx, cy+6);
  cout<< "   :=  =:    ";
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















void updown_soldier(int sx, int sy)
{
  while(sy != 33)
   {
      movesoldier(sx, sy);
     sy = sy+1;
   }
   while(sy>=22)
   {
      movesoldier(sx, sy);
      sy = sy-1;
   } 
}

void movesoldier(int sx, int sy)
{
  gotoxy(sx, sy);
  print_soldier(sx, sy);
  Sleep(200);
  gotoxy(sx, sy);
  erase_soldier(sx, sy);
}

void print_soldier(int sx, int sy)
{

  gotoxy(sx, sy);
  cout<< "          __";
  gotoxy(sx, sy+1);
  cout<< "         .. ";
  gotoxy(sx, sy+2);
  cout<< "  -:=++=##*>";
  gotoxy(sx, sy+3);
  cout<< "        -*+:";
  gotoxy(sx, sy+4);
  cout<< "        .*:";
  gotoxy(sx, sy+5);
  cout<< "         +";
  gotoxy(sx, sy+6);
  cout<< "        -+=+:";
}

void erase_soldier(int sx, int sy)
{
  gotoxy(sx, sy);
  cout << "               ";
  gotoxy(sx, sy+1);
  cout << "               ";
  gotoxy(sx, sy+2);
  cout << "               ";
  gotoxy(sx, sy+3);
  cout << "               ";
  gotoxy(sx, sy+4);
  cout << "               ";
  gotoxy(sx, sy+5);
  cout << "               ";
  gotoxy(sx, sy+6);
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



void gotoxy(int x, int y)
{

COORD coordinates;

coordinates.X = x;

coordinates.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}