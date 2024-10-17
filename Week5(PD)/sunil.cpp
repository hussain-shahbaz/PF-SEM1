#include <iostream>
#include <windows.h>
using namespace std;

void maize();
void gotoxy(int, int);
void printplayer();
void eraseplayer();
void moveplayerright();
void moveplayerleft();

int ex = 11, ey = 1;
int px = 10, py = 19;
int main()
{
    int x, y;
    system("cls");
    maize();
    printplayer();
    while (true)
    {

        if (GetAsyncKeyState(VK_LEFT))

        {

            moveplayerleft();
        }

        if (GetAsyncKeyState(VK_RIGHT))

        {

            moveplayerright();
        }

        Sleep(10);
    }
}
void moveplayerright()
{
    eraseplayer();
    px = px + 1;
    printplayer();
}
void moveplayerleft()
{
    eraseplayer();
    px = px - 1;
    printplayer();
}
void printplayer()
{
    gotoxy(px,py);
    cout<< "(o_o)";
    
}

void eraseplayer()
{

    gotoxy(px, py);
    cout << "      ";
}
void maize()
{
    cout << "########################################################################" << endl;
    cout << "#    #    #                        #                    #              #" << endl;
    cout << "#    #    #     ##############     #    #        #      #        #     #" << endl;
    cout << "#         #     #                  #    #        #      #        #     #" << endl;
    cout << "#     #####     #                       ##########      #        #     #" << endl;
    cout << "#               #              #        #               #        #     #" << endl;
    cout << "#               #########      #        #        #               #     #" << endl;
    cout << "#               #              #        #        #       #########     #" << endl;
    cout << "#########       #       #          ######        #                     #" << endl;
    cout << "#       #       #       #                        #   #                 #" << endl;
    cout << "###     #     ####      #     #        #         ########        #######" << endl;
    cout << "#       #     #         #     #        #         #                     #" << endl;
    cout << "#       #     #         #     #        #         #      ##########     #" << endl;
    cout << "###     #     #         #     #        #                         #     #" << endl;
    cout << "#       #     ###       #     #        #         #     #         #     #" << endl;
    cout << "#             #               #        #         #     #         #     #" << endl;
    cout << "#    #                #       ################## #     #         #     #" << endl;
    cout << "#    #        #       #      #                         #         #     #" << endl;
    cout << "#    #        #       #      #     #   #                         #     #" << endl;
    cout << "######     ############            #   ###################       #     #" << endl;
    cout << "#                                  #                                   #" << endl;
    cout << "########################################################################" << endl;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}