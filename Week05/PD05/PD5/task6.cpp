#include <iostream>
#include <windows.h>
using namespace std;
int enemyHealth = 100;
char direction='R';
int eX = 5, eY = 0;
int pX = 1, pY = 28;
// Maze Functions
void singleline()
{
    cout << "#####################################################################################################################" << endl;
}
void borders()
{
    cout << "#                                                                                                                   #" << endl;
}
void maze()
{
    singleline();
    for (int i = 0; i < 50; i++)
    {
        borders();
    }
    singleline();
}
//GOTOXY functino
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar: ' ';
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//Enemy Functions

void printEnemy()
{
    gotoxy(eX, eY);
    cout << "(~~~) (~~~)";
    gotoxy(eX, eY + 1);
    cout << "|=| | | |=|";
    gotoxy(eX, eY + 2);
    cout << "|=| | | |=|";
    gotoxy(eX, eY + 3);
    cout << "  \\     / ";
    gotoxy(eX, eY + 4);
    cout << "   \\   /  ";
}
void eraseEnemy()
{
    gotoxy(eX, eY);
    cout << "           ";
    gotoxy(eX, eY + 1);
    cout << "           ";
    gotoxy(eX, eY + 2);
    cout << "           ";
    gotoxy(eX, eY + 3);
    cout << "           ";
    gotoxy(eX, eY + 4);
    cout << "           ";
}
void moveEnemyToTheLeft()
{
    eraseEnemy();
    Sleep(10);
    eX--;

    if (eX == 5)
    {
        direction == 'R';
        return;
    }
    printEnemy();
}
void moveEnemyToTheRight()
{
    eraseEnemy();
    Sleep(10);
    eX += 1;
    if (eX == 90)
    {
        direction == 'L';
        return;
        
    }
    printEnemy();
    Sleep(10);
}
void getDirection() {
    if(eX==105) direction=='L';
    if(eX==5) direction=='R';
}
void moveEnemy(){
    if(direction=='R') moveEnemyToTheRight();
    if(direction=='L') moveEnemyToTheLeft(); 
} 
void movementEnemy(char direction) {
    eraseEnemy();
    if(direction == 'R') eX++;
    if(direction == 'L') eX--;
    printEnemy();
    Sleep(10);
}
// Player Functions
void printPlayer()
{
    gotoxy(pX, pY);
    cout << "    /  \\     ";
    gotoxy(pX, pY + 1);
    cout << " __/ ~~ \\__  ";
    gotoxy(pX, pY + 2);
    cout << "/  |    |  \\ ";
    gotoxy(pX, pY + 3);
    cout << "===.____.===  ";
    gotoxy(pX, pY + 4);
    cout << "    ||||      ";
}
void erasePlayer()
{
    gotoxy(pX, pY);
    cout << "              ";
    gotoxy(pX, pY + 1);
    cout << "              ";
    gotoxy(pX, pY + 2);
    cout << "              ";
    gotoxy(pX, pY + 3);
    cout << "              ";
    gotoxy(pX, pY + 4);
    cout << "              ";
}
void movePlayerToTheLeft()
{
    erasePlayer();
    pX--;

    if (pX == 5)
    {
        pX = 6;
    }
    printPlayer();
}
void movePlayerToTheRight()
{
    erasePlayer();
    pX++;
    if (pX == 90)
    {
        pX = 89;
    }
    printPlayer();
    // Sleep(50);
}
void movePlayerUP()
{
    erasePlayer();
    erasePlayer();
    pY--;
    if (pY == 4)
    {
        pY = 5;
    }
    printPlayer();
}
void movePlayerDown()
{
    erasePlayer();
    erasePlayer();
    pY++;
    if (pY == 28)
    {
        pY =28;
    }
    printPlayer();
}
void movePlayerDiagonalUpLeft()
{
    erasePlayer();
    pX--;
    pY--;
    if (pX == 5)
    {
        pX = 6;
    }
    if (pY == 4)
    {
        pY = 5;
    }
}
void movePlayerDiagonalUpRight()
{
    erasePlayer();
    pX++;
    pY--;
    if (pX == 90)
    {
        pX = 89;
    }
    if (pY == 4)
    {
        pY = 5;
    }
}
void movePlayerDiagonalDownLeft()
{
    erasePlayer();
    pX--;
    pY++;
    if (pX == 90)
    {
        pX = 89;
    }
    if (pY == 28)
    {
        pY = 28;
    }
}
void movePlayerDiagonalDownRight()
{
    erasePlayer();
    pX++;
    pY--;
    if (pX == 90)
    {
        pX = 89;
    }
    if (pY == 28)
    {
        pY = 28;
    }
}
// Shooting mechanics
void bullet()
{
    cout << "^";
}
void eraseBullet()
{
    cout << " ";
}
void shootEnemy(int pX, int pY)
{
    int posNozzle = (pX + 6);
    int bY = pY;
    while (true)
    {
        gotoxy(posNozzle, bY);
        eraseBullet();
        bY -= 1;
        gotoxy(posNozzle, bY);
        bullet();
        Sleep(10);
        if (bY == 5)
        {
            break;
        }
        if (bY == eY + 4 && posNozzle >= eX && posNozzle <= eX + 8)
        {
            enemyHealth -= 10;
            cout << "Criticle Hit! -10";
            Sleep(10);
            cout << "                    ";
            if (enemyHealth <= 0)
            {      
                break;
            }
        }
    }
}
// Winning Status
void youWon(){
    cout << " #     # ####### #      #     #     # ####### #     # " << endl;
    cout << "  #   #  #     # #     #      #  #  # #     # ##    # " << endl;
    cout << "   # #   #     # #     #      #  #  # #     # # #   # " << endl;
    cout << "    #    #     # #     #      #  #  # #     # #  #  # " << endl;
    cout << "    #    #     # #     #      #  #  # #     # #   # # " << endl;
    cout << "    #    #     # #     #      #  #  # #     # #    ## " << endl;
    cout << "    #    #######  #####        ## ##  ####### #     # " << endl;
}
void youLost(){
    cout << " #     # ####### #     #    #       #######  #####  ####### " << endl;
    cout << "  #   #  #     # #     #    #       #     # #     #    #    " << endl;
    cout << "   # #   #     # #     #    #       #     # #          #    " << endl;
    cout << "    #    #     # #     #    #       #     #  #####     #    " << endl;
    cout << "    #    #     # #     #    #       #     #       #    #    " << endl;
    cout << "    #    #     # #     #    #       #     # #     #    #    " << endl;
    cout << "    #    #######  #####     ####### #######  #####     #    " << endl;
    }


main()
{
    system("cls");
    maze();
    // direction = 'R';
    while (true)
    {
        gotoxy(90, 1);
        cout << "Enemy Health : " << enemyHealth << endl;
        printEnemy();
        printPlayer();
        getDirection();
        moveEnemy();
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerToTheLeft();
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerToTheRight();
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUP();
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        else if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_LEFT))
        {
            movePlayerDiagonalUpLeft();
        }
        else if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerDiagonalUpRight();
        }
        else if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_LEFT))
        {
            movePlayerDiagonalDownLeft();
        }
        else if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerDiagonalDownRight();
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            shootEnemy(pX, pY);
        }

        if (pY == eY)
        {
            youLost();
            break;
        }

        if (enemyHealth == 0)
        {
            eraseEnemy();
            youWon();
            break;
        }
        cout<<direction; 
    }

    gotoxy(1, 1000);
}
