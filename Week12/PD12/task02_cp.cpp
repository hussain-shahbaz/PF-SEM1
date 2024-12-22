#include <iostream>
#include <windows.h>
#include<conio.h>
#include<string>
using namespace std;
void pressAnyKey(){
    cout<<endl<<"                      Press any key to continue..."<<endl;
    getch();
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X    = 1;
    coordBufSize.Y = 1; 
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
int bX = 70, bY = 10;
int eX = 5, eY = 1;
int sY, sX;
int e2X = 145, e2Y = 26;
int e3X = 80, e3Y = 7;
char direction = 'R';
char direction2 = 'U';
string direction3 = "RD";
int pX = 15, pY = 20;
int enemyHealth = 100;
int gameScore = 0;  
void singleline()
{
    cout << "#######################################################################################################################################################################" << endl;
}
void borders()
{
    cout << "#                                                                                                                                                                     #" << endl;
}
void maze()
{
    singleline();
    for (int i = 0; i < 45; i++)
    {
        borders();
    }
    singleline();
}
void printSmallStar()
{
    cout << "*-*";
}
void eraseSmallStar()
{
    cout << "   ";
}
void printBigStar()
{
    cout << "{)0(}";
}
void eraseBigStar()
{
    cout << "     ";
}
void backGround()
{
    eraseBigStar();
    eraseSmallStar();
    int x = rand() % 6;
    if (x == 0)
    {
        sX = 7;
        sY++;
    }
    gotoxy(sX, sY);
    printBigStar();
    gotoxy(sX + 15, sY);
    printSmallStar();
}
void bonusPill(int bX,int bY)
{
    gotoxy(bX, bY); 
    cout << ">0<";
}
void eraseBonusPill()
{
    gotoxy(bX, bY);
    cout << "   ";
}
void getBonus()
{
    if (pY - 1 == bY && (pX + 5 == bX || pX +6 == bX || pX + 4 == bX || pX + 3 == bX || pX + 7 == bX))
    {
        gameScore += 10;
        eraseBonusPill();
        bX = rand() % 50;
        bY = rand() % 70;
        bonusPill(bX,bY);
    }
}
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
void Direction()
{
    if (eX == 105)
    {
        direction = 'L';
    }
    if (eX == 5)
    {
        direction = 'R';
    }
}
void movemenentEnemy()
{
    eraseEnemy();
    if (direction == 'R')
        eX++;
    if (direction == 'L')
        eX--;
    printEnemy();
    Sleep(10);
}
void printEnemy2()
{
    gotoxy(e2X, e2Y);
    cout << "    /\\\\   //\\ " << endl;
    gotoxy(e2X, e2Y + 1);
    cout << "    \\  \\ /  /  " << endl;
    gotoxy(e2X, e2Y + 2);
    cout << "     \\||.||/    " << endl;
    gotoxy(e2X, e2Y + 3);
    cout << "      \\\\V//    " << endl;
    gotoxy(e2X, e2Y + 4);
    cout << "       \\./      " << endl;
}
void eraseEnemy2()
{
    gotoxy(e2X, e2Y);
    cout << "                 " << endl;
    gotoxy(e2X, e2Y + 1);
    cout << "                 " << endl;
    gotoxy(e2X, e2Y + 2);
    cout << "                 " << endl;
    gotoxy(e2X, e2Y + 3);
    cout << "                 " << endl;
    gotoxy(e2X, e2Y + 4);
    cout << "                 " << endl;
}
void Direction2()
{
    if (getCharAtxy(e2X, e2Y - 2) == '#')
        direction2 = 'D';
    else if (getCharAtxy(e2X, e2Y + 15) == '#')
        direction2 = 'U';
}
void moveEnemy2()
{
    eraseEnemy2();
    if (direction2 == 'D')
        e2Y++;
    else if (direction2 == 'U')
        e2Y--;
    printEnemy2();
}
void printEnemy3()
{
    gotoxy(e3X, e3Y);
    cout << "         \\\\    " << endl;
    gotoxy(e3X, e3Y + 1);
    cout << "      /| / \\__  " << endl;
    gotoxy(e3X, e3Y + 2);
    cout << "--===o========>- " << endl;
    gotoxy(e3X, e3Y + 3);
    cout << "      \\| \\ /-- " << endl;
    gotoxy(e3X, e3Y + 4);
    cout << "         //      " << endl;
}
void eraseEnemy3()
{
    gotoxy(e3X, e3Y);
    cout << "                 " << endl;
    gotoxy(e3X, e3Y + 1);
    cout << "                 " << endl;
    gotoxy(e3X, e3Y + 2);
    cout << "                 " << endl;
    gotoxy(e3X, e3Y + 3);
    cout << "                 " << endl;
    gotoxy(e3X, e3Y + 4);
    cout << "                 " << endl;
}
void Direction3()
{
    if (getCharAtxy(e3X + 19, e3Y) == '#' || getCharAtxy(e3X, e3Y + 6) == '#')
        direction3 = "LU";
    else if (getCharAtxy(e3X - 1, e3Y) == '#' || getCharAtxy(e3X, e3Y - 8) == '#')
        direction3 = "RD";
}
void moveEnemy3()
{
    eraseEnemy3();
    if (direction3 == "RD")
    {
        e3X += 2;
        e3Y++;
    }
    else if (direction3 == "LU")
    {
        e3X -= 2;
        e3Y--;
    }
    printEnemy3();
}
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
    if (pX == 130)
    {
        pX = 128;
    }
    printPlayer();
}
void movePlayerUP()
{
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
    pY++;
    if (getCharAtxy(pX, pY + 6) == '#')
    {
        pY -= 1;
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
    printPlayer();
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
    printPlayer();
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
    if (getCharAtxy(pX, pY + 6) == '#')
    {
        pY -= 1;
    }
    printPlayer();
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
    if (getCharAtxy(pX, pY + 6) == '#')
    {
        pY -= 1;
    }
    printPlayer();
}

// Shooting mechanics
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount = 0;
void bullet(int x, int y)
{
    gotoxy(x,y);
    cout << "^";
}
void eraseBullet(int x,int y){
    gotoxy(x,y);
    cout << " ";
}
void makeBulletInactive(int n){
    isBulletActive[n] = false;
}
void generateBullet(){
    bulletX[bulletCount] =  pX + 6;
    bulletY[bulletCount] = pY;
}
void moveBulletX(){
    for(int i=0;i<bulletCount;i++){
        if(isBulletActive[i]){
            char next = getCharAtxy(bulletX[i] +1,bulletY[i]);
            if(next != ' '){
                eraseBullet(bulletX[i],bulletY[i]);
                makeBulletInactive(i);
            }
            else{
                eraseBullet(bulletX[i], bulletY[i]);
                bulletX[i] += 1;
                bullet(bulletX[i],bulletY[i]);
            }
        }
    }
}
void moveBulletY(){
    for(int i=0;i<bulletCount;i++){
        if(isBulletActive[i]){
            char next = getCharAtxy(bulletX[i],bulletY[i]-1);
            if(next != ' '){
                eraseBullet(bulletX[i],bulletY[i]);
                makeBulletInactive(i);
            }
            else{
                eraseBullet(bulletX[i], bulletY[i]);
                bulletY[i] -= 1;
                bullet(bulletX[i],bulletY[i]);
            }
        }
    }
}

// Winning Status
void youWon()
{
    eraseEnemy();
    cout<<endl;
    cout << "     #     # ####### #     #      #     # ####### #     # " << endl;
    cout << "      #   #  #     # #     #      #  #  # #     # ##    # " << endl;
    cout << "       # #   #     # #     #      #  #  # #     # # #   # " << endl;
    cout << "        #    #     # #     #      #  #  # #     # #  #  # " << endl;
    cout << "        #    #     # #     #      #  #  # #     # #   # # " << endl;
    cout << "        #    #     # #     #      #  #  # #     # #    ## " << endl;
    cout << "        #    #######  #####        ## ##  ####### #     # " << endl;
}
void youLost()
{
    erasePlayer();
    cout<<endl;
    cout << "     #     # ####### #     #    #       #######  #####  ####### " << endl;
    cout << "      #   #  #     # #     #    #       #     # #     #    #    " << endl;
    cout << "       # #   #     # #     #    #       #     # #          #    " << endl;
    cout << "        #    #     # #     #    #       #     #  #####     #    " << endl;
    cout << "        #    #     # #     #    #       #     #       #    #    " << endl;
    cout << "        #    #     # #     #    #       #     # #     #    #    " << endl;
    cout << "        #    #######  #####     ####### #######  #####     #    " << endl;
}

void detection(){
    for (int i = 0; i < bulletCount; i++)
        {
            if (isBulletActive[i])
            {
                if ((bulletX[i] >= eX && bulletX[i] <= eX + 10 && bulletY[i] >= eY && bulletY[i] <= eY + 4) ||  // Enemy 1
                    (bulletX[i] >= e2X && bulletX[i] <= e2X + 10 && bulletY[i] >= e2Y && bulletY[i] <= e2Y + 4) ||  // Enemy 2
                    (bulletX[i] >= e3X && bulletX[i] <= e3X + 10 && bulletY[i] >= e3Y && bulletY[i] <= e3Y + 4))   // Enemy 3
                {
                    gotoxy(bulletX[i],bulletY[i]);
                    cout<<"******";
                    gotoxy(bulletX[i],bulletY[i]+1);
                    cout<<"******";
                    Sleep(5);

                    eraseBullet(bulletX[i], bulletY[i]);
                    makeBulletInactive(i);
                    enemyHealth -= 10; 
                    gotoxy(200,3);
                    cout<<"Criticle HIT -10";
                    gotoxy(bulletX[i],bulletY[i]);
                    cout<<"      ";
                    gotoxy(bulletX[i],bulletY[i]+1);
                    cout<<"      ";
                }
            }
        }
}

int main()
{
    system("cls");
    maze();
    while (true)
    {
        gotoxy(200, 1);
        cout << "Enemy Health : " << enemyHealth << endl;
        gotoxy(200, 2);
        cout << "Game Score : " << gameScore << endl;
        // backGround();
        getBonus();
        Direction();
        Direction2();
        Direction3();
        movemenentEnemy();
        moveEnemy2();
        moveEnemy3();
        printPlayer();
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
        if (GetAsyncKeyState(VK_SPACE))
        {
            isBulletActive[bulletCount] = true;
            generateBullet();
            bulletCount++;
            
        }
        moveBulletY();
        detection();

        if ((pY == eY + 5 && (pX == eX)) || (pY == e2Y + 5 && (pX == e2X)) || (pY == e3Y + 5 && (pX == e3X)))
        {
            youLost();
            pressAnyKey();
            break;
        }

        if (enemyHealth <= 0)
        {
            youWon();
            pressAnyKey();
            break;
        }
    }
    return 0;
}