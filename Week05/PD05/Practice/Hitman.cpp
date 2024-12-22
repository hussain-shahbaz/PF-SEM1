#include<iostream>
#include<windows.h>
using namespace std;

// Placement
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

// maze functions
void singleline()
{
    cout << "#######################################################################################################################################################################" << endl;
}
void borders()
{
    cout << "#                                                                                                                                                                     #" << endl;
}
void printMaze1()
{
    singleline();
    for (int i = 0; i < 45; i++)
    {
        if(i == 6) cout<<"#                                                    #########         ########                          #####################################                        #"<<endl;
        if(i == 23) cout<<"#                                                    #########         ########                          #####################################                        #"<<endl;
        if(i == 42) cout<<"#                                                    #########         ########                          #####################################                        #"<<endl;
        borders();
    }
    singleline();
}

// Player movement

int pX = 3,pY = 6;
void printHitmanStationary(int pX,int pY){
        gotoxy(pX, pY);
        cout << "  O   ";
        gotoxy(pX, pY + 1);
        cout << " /|\\ ";
        gotoxy(pX, pY + 2);
        cout << " / \\ ";
}

void printHitmanLeft(int pX, int pY){
        gotoxy(pX, pY);
        cout << "  O   ";
        gotoxy(pX, pY + 1);
        cout << "<=|\\ ";
        gotoxy(pX, pY + 2);
        cout << " / \\ ";
}

void printHitmanRight(int pX, int pY){
    gotoxy(pX, pY);
    cout << "  O   ";
    gotoxy(pX, pY + 1);
    cout << " /|=> ";
    gotoxy(pX, pY + 2);
    cout << " / \\ ";   
}
void printHitmanUp(int pX,int pY){
    gotoxy(pX, pY);
    cout << "  O-^-";
    gotoxy(pX, pY + 1);
    cout << " /|\\ ";
    gotoxy(pX, pY + 2);
    cout << " / \\ ";
}
void printHitmanDown(int pX,int pY){
    gotoxy(pX, pY);
    cout << "  O_ _";
    gotoxy(pX, pY + 1);
    cout << " /|\\V";
    gotoxy(pX, pY + 2);
    cout << " / \\ ";
}
char playerDirection;
// void printHitman(int pX, int pY, char direction) {
//     if (direction == 'S') {
//         gotoxy(pX, pY);
//         cout << "  O   ";
//         gotoxy(pX, pY + 1);
//         cout << " /|\\ ";
//         gotoxy(pX, pY + 2);
//         cout << " / \\ ";
//     } else if (direction == 'R') {
//         gotoxy(pX, pY);
//         cout << "  O   ";
//         gotoxy(pX, pY + 1);
//         cout << " /|=> ";
//         gotoxy(pX, pY + 2);
//         cout << " / \\ ";
//     } else if (direction == 'L') { 
//         gotoxy(pX, pY);
//         cout << "  O   ";
//         gotoxy(pX, pY + 1);
//         cout << "<=|\\ ";
//         gotoxy(pX, pY + 2);
//         cout << " / \\ ";
//     } else if (direction == 'U') { 
//         gotoxy(pX, pY);
//         cout << "  O-^-";
//         gotoxy(pX, pY + 1);
//         cout << " /|\\ ";
//         gotoxy(pX, pY + 2);
//         cout << " / \\ ";
//     } else if(direction = 'D'){
//         gotoxy(pX, pY);
//         cout << "  O_ _";
//         gotoxy(pX, pY + 1);
//         cout << " /|\\V";
//         gotoxy(pX, pY + 2);
//         cout << " / \\ ";
//     }
// }
void eraseHitman(int pX, int pY) {
    gotoxy(pX, pY);
    cout << "      "; 
    gotoxy(pX, pY + 1);
    cout << "      "; 
    gotoxy(pX, pY + 2);
    cout << "      "; 
}
void moveHitmanLeft(){
    eraseHitman(pX,pY);
    pX ++;
    if(getCharAtxy(pX+5 ,pY) == '#') pX --;
    if(getCharAtxy(pX+5 ,pY+1) == '#') pX --;
    if(getCharAtxy(pX+5 ,pY+2) == '#') pX --;
    printHitmanLeft(pX,pY);
}
void moveHitmanRight(){
    eraseHitman(pX,pY);
    pX ++;
    if(getCharAtxy(pX+5 ,pY) == '#') pX --;
    if(getCharAtxy(pX+5 ,pY+1) == '#') pX --;
    if(getCharAtxy(pX+5 ,pY+2) == '#') pX --;
    printHitmanRight(pX,pY);
}
void moveHitmanDown(){
    eraseHitman(pX,pY);
    if (getCharAtxy(pX,   pY+2) == '#') pY --;
    if (getCharAtxy(pX+1, pY+2) == '#') pY --;
    if (getCharAtxy(pX+2, pY+2) == '#') pY --;
    if (getCharAtxy(pX+3, pY+2) == '#') pY --;
    if (getCharAtxy(pX+4, pY+2) == '#') pY --;
    if (getCharAtxy(pX+5, pY+2) == '#') pY --;
    printHitmanDown(pX,pY);
}
void moveHitmanUp(){
    eraseHitman(pX,pY);
    if(getCharAtxy(pX,pY) == '#') pY++;
    if(getCharAtxy(pX+1,pY) == '#') pY++;
    if(getCharAtxy(pX+2,pY) == '#') pY++;
    if(getCharAtxy(pX+3,pY) == '#') pY++;
    if(getCharAtxy(pX+4,pY) == '#') pY++;
    if(getCharAtxy(pX+5,pY) == '#') pY++;
    printHitmanUp(pX,pY);
}
// void movePlayer(){
//     eraseHitman(pX,pY);
//     if(playerDirection == 'R'){
//         pX ++;
//         if(getCharAtxy(pX+5 ,pY) == '#') pX --;
//         if(getCharAtxy(pX+5 ,pY+1) == '#') pX --;
//         if(getCharAtxy(pX+5 ,pY+2) == '#') pX --;
//     }
//     else if(playerDirection == 'L'){
//         pX --;
//         if(getCharAtxy(pX,pY) == '#') pX++;
//         if(getCharAtxy(pX,pY+1) == '#') pX++;
//         if(getCharAtxy(pX,pY+2) == '#') pX++;
//     }
//     else if(playerDirection == 'D' ){
//         pY ++;
//         if (getCharAtxy(pX,   pY+2) == '#') pY --;
//         if (getCharAtxy(pX+1, pY+2) == '#') pY --;
//         if (getCharAtxy(pX+2, pY+2) == '#') pY --;
//         if (getCharAtxy(pX+3, pY+2) == '#') pY --;
//         if (getCharAtxy(pX+4, pY+2) == '#') pY --;
//         if (getCharAtxy(pX+5, pY+2) == '#') pY --;
//     }
//     else if(playerDirection == 'U'){
//         pY --;
//         if(getCharAtxy(pX,pY) == '#') pY++;
//         if(getCharAtxy(pX+1,pY) == '#') pY++;
//         if(getCharAtxy(pX+2,pY) == '#') pY++;
//         if(getCharAtxy(pX+3,pY) == '#') pY++;
//         if(getCharAtxy(pX+4,pY) == '#') pY++;
//         if(getCharAtxy(pX+5,pY) == '#') pY++;
//     }
//     printHitman(pX,pY,playerDirection);
// }

// Shooting mechanics
char bulletDirection[100];
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount = 0;
void bullet(int x, int y)
{
    gotoxy(x,y);
    cout << "*";
}
void eraseBullet(int x,int y){
    gotoxy(x,y);
    cout << " ";
}
void makeBulletInactive(int n){
    isBulletActive[n] = false;
}


void generateBullet(char direction) {
    if (direction == 'R') {
        bulletX[bulletCount] = pX + 6;  // Right of player
        bulletY[bulletCount] = pY + 1;  // Middle of player
    } else if (direction == 'L') {
        bulletX[bulletCount] = pX - 1;  // Left of player
        bulletY[bulletCount] = pY + 1;  // Middle of player
    } else if (direction == 'U') {
        bulletX[bulletCount] = pX + 3;  // Center of player
        bulletY[bulletCount] = pY - 1;  // Above player
    } else if (direction == 'D') {
        bulletX[bulletCount] = pX + 3;  // Center of player
        bulletY[bulletCount] = pY + 3;  // Below player
    }
    isBulletActive[bulletCount] = true;
    bulletCount++;
}

void moveBulletRight() {
    for (int i = 0; i < bulletCount; i++) {
        if (isBulletActive[i]) {
            char next = getCharAtxy(bulletX[i] + 1, bulletY[i]);
            if (next == '#') {  // Bullet hits a wall
                eraseBullet(bulletX[i], bulletY[i]);
                makeBulletInactive(i);
            } else {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletX[i]++;
                bullet(bulletX[i], bulletY[i]);
            }
        }
    }
}

void moveBulletLeft() {
    for (int i = 0; i < bulletCount; i++) {
        if (isBulletActive[i]) {
            char next = getCharAtxy(bulletX[i] - 1, bulletY[i]);
            if (next == '#') {  // Bullet hits a wall
                eraseBullet(bulletX[i], bulletY[i]);
                makeBulletInactive(i);
            } else {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletX[i]--;
                bullet(bulletX[i], bulletY[i]);
            }
        }
    }
}

void moveBulletUp() {
    for (int i = 0; i < bulletCount; i++) {
        if (isBulletActive[i]) {
            char next = getCharAtxy(bulletX[i], bulletY[i] - 1);
            if (next == '#') {  // Bullet hits a wall
                eraseBullet(bulletX[i], bulletY[i]);
                makeBulletInactive(i);
            } else {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletY[i]--;
                bullet(bulletX[i], bulletY[i]);
            }
        }
    }
}

void moveBulletDown() {
    for (int i = 0; i < bulletCount; i++) {
        if (isBulletActive[i]) {
            char next = getCharAtxy(bulletX[i], bulletY[i] + 1);
            if (next == '#') {  // Bullet hits a wall
                eraseBullet(bulletX[i], bulletY[i]);
                makeBulletInactive(i);
            } else {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletY[i]++;
                bullet(bulletX[i], bulletY[i]);
            }
        }
    }
}

void moveBullet(char playerDirection){
    if(playerDirection == 'D') moveBulletDown();
    if(playerDirection == 'R') moveBulletRight();
    if(playerDirection == 'L') moveBulletLeft();
    if(playerDirection == 'U') moveBulletUp();
}



int main(){
    system("cls");
    printMaze1();
    playerDirection = 'S';
    // printHitman(pX,pY,playerDirection);
    printHitmanStationary(pX,pY);
    while(true){
        if (GetAsyncKeyState(VK_LEFT)) {
            bulletDirection[bulletCount] = 'L';
            moveHitmanLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT)){
            bulletDirection[bulletCount] = 'R';
            moveHitmanRight();
        }
        if (GetAsyncKeyState(VK_UP)){
            bulletDirection[bulletCount] = 'U';
            moveHitmanUp();
        } 
        if (GetAsyncKeyState(VK_DOWN)){
            bulletDirection[bulletCount] = 'D';
            moveHitmanDown();
        }
        if (GetAsyncKeyState(VK_SPACE)){
            if(bulletCount < 100){
                isBulletActive[bulletCount] = true;
                bulletDirection[bulletCount] = playerDirection;
                generateBullet(playerDirection);
                bulletCount++;
            }
        }
        moveBullet(bulletDirection[bulletCount]);
        Sleep(20);
    }
    
    return 0;
}