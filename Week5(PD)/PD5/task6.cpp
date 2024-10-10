#include <iostream>
#include <windows.h>
using namespace std;
int enemyHealth = 100;
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
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//Enemy Functions
int eX = 1, eY = 2;
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
void moveEnemy()
{
    eraseEnemy();
    eX += 1;
    if (eX == 90)
    {
        eX = 5;
    }
    printEnemy();
}
void moveEnemyToTheLeft()
{
    eraseEnemy();
    Sleep(10);
    eX--;

    if (eX == 5)
    {
        eX = 90;
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
        eX = 5;
    }
    printEnemy();
    Sleep(50);
}
void movementEnemy(){
    moveEnemyToTheLeft();
    moveEnemyToTheRight();
}
// Player Functions
int pX = 1, pY = 28;
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
        pX = 90;
    }
    printPlayer();
}
void movePlayerToTheRight()
{
    erasePlayer();
    pX++;
    if (pX == 90)
    {
        pX = 5;
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
        pY = 28;
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
        pY = 4;
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
        pX = 90;
    }
    if (pY == 4)
    {
        pY = 28;
    }
}
void movePlayerDiagonalUpRight()
{
    erasePlayer();
    pX++;
    pY--;
    if (pX == 90)
    {
        pX = 5;
    }
    if (pY == 4)
    {
        pY = 28;
    }
}
void movePlayerDiagonalDownLeft()
{
    erasePlayer();
    pX--;
    pY++;
    if (pX == 90)
    {
        pX = 5;
    }
    if (pY == 28)
    {
        pY = 4;
    }
}
void movePlayerDiagonalDownRight()
{
    erasePlayer();
    pX++;
    pY--;
    if (pX == 90)
    {
        pX = 5;
    }
    if (pY == 28)
    {
        pY = 4;
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
    cout << "#     # ####### #      #     #     # ####### #     # " << endl;
    cout << "  #   #  #     # #     #     #  #  # #     # ##    # " << endl;
    cout << "   # #   #     # #     #     #  #  # #     # # #   # " << endl;
    cout << "    #    #     # #     #     #  #  # #     # #  #  # " << endl;
    cout << "    #    #     # #     #     #  #  # #     # #   # # " << endl;
    cout << "    #    #     # #     #     #  #  # #     # #    ## " << endl;
    cout << "    #    #######  #####       ## ##  ####### #     # " << endl;
}
void youLost(){
    cout << "#     # ####### #     #    #       #######  #####  ####### " << endl;
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
    while (true)
    {
        gotoxy(90, 1);
        cout << "Enemy Health : " << enemyHealth << endl;
        printEnemy();

        printPlayer();
        moveEnemyToTheRight();

        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerToTheLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerToTheRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUP();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_LEFT))
        {
            movePlayerDiagonalUpLeft();
        }
        if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerDiagonalUpRight();
        }
        if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_LEFT))
        {
            movePlayerDiagonalDownLeft();
        }
        if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerDiagonalDownRight();
        }
        if (GetAsyncKeyState(VK_SPACE))
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
            eraseEnemy(  );
            youWon();
            break;
        }
    }

    gotoxy(1, 1000);
}
