#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

#define RESET "\033[0m"
#define HEAD_COLOR "\033[33m"   // Yellow for head
#define BODY_COLOR "\033[32m"   // Green for body
#define LEGS_COLOR "\033[34m"   // Blue for legs
#define GUN_COLOR "\033[31m"    // Red for gun (when applicable)
#define ARM_COLOR "\033[36m"    // Cyan for arms

void curser(){
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
}
string reverse(string str){
    string answer = "";;
    for(int i=str.size();i>=0;i--){
        answer += str[i];
    }
    return answer;
}
// Placement Functions
char getCharAtxy(short int x, short int y) {
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize = {1, 1};
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

// Maze Functions
void singleline() {
    cout << "#######################################################################################################################################################################" << endl;
}

void borders() {
    cout << "#                                                                                                                                                                     #" << endl;
}
string path = "#          ############################################################################################################################################################";

void printMaze1() {
    singleline();
    for (int i = 1; i < 48; i++) {
        if (i % 16 == 0)       cout << path << endl;
        else if(i%16 == 8) cout<< reverse(path) <<endl;
        else borders();
    }
    singleline();
}

// Player movement

int pX = 2,pY = 44;
char playerDirection;

void printHitman(int pX, int pY, char direction) {
    if (direction == 'S') {  // Standing
        gotoxy(pX, pY);
        cout << HEAD_COLOR << "  O   " << RESET;
        gotoxy(pX, pY + 1);
        cout << ARM_COLOR << " /|\\ " << RESET;
        gotoxy(pX, pY + 2);
        cout << LEGS_COLOR << " / \\ " << RESET;
    } else if (direction == 'R') {  // Right
        gotoxy(pX, pY);
        cout << HEAD_COLOR << "  O   " << RESET;
        gotoxy(pX, pY + 1);
        cout << ARM_COLOR << " /|=> " << RESET;
        gotoxy(pX, pY + 2);
        cout << LEGS_COLOR << " / \\ " << RESET;
    } else if (direction == 'L') {  // Left
        gotoxy(pX, pY);
        cout << HEAD_COLOR << "  O   " << RESET;
        gotoxy(pX, pY + 1);
        cout << ARM_COLOR << " <=|\\ " << RESET;
        gotoxy(pX, pY + 2);
        cout << LEGS_COLOR << " / \\ " << RESET;
    } else if (direction == 'U') {  // Up
        gotoxy(pX, pY);
        cout << HEAD_COLOR << "  O-^- " << RESET;
        gotoxy(pX, pY + 1);
        cout << ARM_COLOR << " /|\\ " << RESET;
        gotoxy(pX, pY + 2);
        cout << LEGS_COLOR << " / \\ " << RESET;
    } else if (direction == 'D') {  // Down
        gotoxy(pX, pY);
        cout << HEAD_COLOR << "  O_ _ " << RESET;
        gotoxy(pX, pY + 1);
        cout << ARM_COLOR << " /|\\V " << RESET;
        gotoxy(pX, pY + 2);
        cout << LEGS_COLOR << " / \\ " << RESET;
    }
}

void eraseHitman(int pX, int pY) {
    gotoxy(pX, pY);
    cout << "       "; 
    gotoxy(pX, pY + 1);
    cout << "       "; 
    gotoxy(pX, pY + 2);
    cout << "       "; 
}

void movePlayer(){
    eraseHitman(pX,pY);
    if(playerDirection == 'R'){
        pX ++;
        if(getCharAtxy(pX+6 ,pY+0) == '#') pX --;
        if(getCharAtxy(pX+6 ,pY+1) == '#') pX --;
        if(getCharAtxy(pX+6 ,pY+2) == '#') pX --;
    }
    else if(playerDirection == 'L'){
        pX --;
        if(getCharAtxy(pX,pY) == '#') pX++;
        if(getCharAtxy(pX,pY+1) == '#') pX++;
        if(getCharAtxy(pX,pY+2) == '#') pX++;
    }
    else if(playerDirection == 'D' ){
        pY ++;
        if (getCharAtxy(pX,   pY+3) == '#') pY --;
        if (getCharAtxy(pX+1, pY+3) == '#') pY --;
        if (getCharAtxy(pX+2, pY+3) == '#') pY --;
        if (getCharAtxy(pX+3, pY+3) == '#') pY --;
        if (getCharAtxy(pX+4, pY+3) == '#') pY --;
        if (getCharAtxy(pX+5, pY+3) == '#') pY --;
    }
    else if(playerDirection == 'U'){
        pY --;
        if(getCharAtxy(pX,pY-1) == '#') pY++;
        if(getCharAtxy(pX+1,pY-1) == '#') pY++;
        if(getCharAtxy(pX+2,pY-1) == '#') pY++;
        if(getCharAtxy(pX+3,pY-1) == '#') pY++;
        if(getCharAtxy(pX+4,pY-1) == '#') pY++;
        if(getCharAtxy(pX+5,pY-1) == '#') pY++;
    }
    printHitman(pX,pY,playerDirection);
}

char guardDirection = 'L';
int gX = rand(),gY = pY;
int guardHealth = 100;
int playerHealth = 100;
int gameScore = 0;

// Shooting mechanics

char bulletDirection[100];
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount = 0;

void bullet(int x, int y){
    gotoxy(x,y);
    cout << "-";
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
        bulletX[bulletCount] = pX + 6;
        bulletY[bulletCount] = pY + 1;
    } else if (direction == 'L') {
        bulletX[bulletCount] = pX - 1;
        bulletY[bulletCount] = pY + 1;
    } else if (direction == 'U') {
        bulletX[bulletCount] = pX + 3;
        bulletY[bulletCount] = pY - 1;
    } else if (direction == 'D') {
        bulletX[bulletCount] = pX + 3;
        bulletY[bulletCount] = pY + 3;
    }
    isBulletActive[bulletCount] = true;
    bulletCount++;
}

void moveBulletRight(int i) {
    char next = getCharAtxy(bulletX[i] + 2, bulletY[i]);
    char next2 = getCharAtxy(bulletX[i] +1, bulletY[i]);
    if (next == '#' || next2 == '#') {
        eraseBullet(bulletX[i], bulletY[i]);
        makeBulletInactive(i);
    } else {
        eraseBullet(bulletX[i], bulletY[i]);
        bulletX[i] +=2;
        bullet(bulletX[i], bulletY[i]);
    }
}

void moveBulletLeft(int i) {
    char next = getCharAtxy(bulletX[i] - 2, bulletY[i]);
    char next2 = getCharAtxy(bulletX[i] - 1, bulletY[i]);
    if (next == '#' || next2 == '#') {
        eraseBullet(bulletX[i], bulletY[i]);
        makeBulletInactive(i);
    } else {
        eraseBullet(bulletX[i], bulletY[i]);
        bulletX[i]-=2;
        bullet(bulletX[i], bulletY[i]);
    }
}

void moveBulletUp(int i) {
    char next = getCharAtxy(bulletX[i], bulletY[i] - 1);
    if (next == '#') {
        eraseBullet(bulletX[i], bulletY[i]);
        makeBulletInactive(i);
    } else {
        eraseBullet(bulletX[i], bulletY[i]);
        bulletY[i]--;
        bullet(bulletX[i], bulletY[i]);
    }
}

void moveBulletDown(int i) {
    char next = getCharAtxy(bulletX[i], bulletY[i]+1);
    if (next == '#') {
        eraseBullet(bulletX[i], bulletY[i]);
        makeBulletInactive(i);
    } else {
        eraseBullet(bulletX[i], bulletY[i]);
        bulletY[i]++;
        bullet(bulletX[i], bulletY[i]);
    }
}

void moveBullets() {
    for (int i = 0; i < bulletCount; i++) {
        if (isBulletActive[i]) {
            if (bulletDirection[i] == 'R') moveBulletRight(i);
            if (bulletDirection[i] == 'L') moveBulletLeft(i);
            if (bulletDirection[i] == 'U') moveBulletUp(i);
            if (bulletDirection[i] == 'D') moveBulletDown(i);
        }
    }
}

void shootBullet(){
    if(bulletCount < 100){
        isBulletActive[bulletCount] = true;
        bulletDirection[bulletCount] = playerDirection;
        generateBullet(bulletDirection[bulletCount]);
    }
}

#define BLOOD "\033[31m"
void impact(int X, int Y){
                gotoxy(X+5,Y+1);
                cout<<BLOOD << "**" << RESET;
                gotoxy(X+5,Y+2);
                cout<<BLOOD << "**" << RESET;
                Sleep(10);
                gotoxy(X+5,Y+1);
                cout<<"  ";
                gotoxy(X+5,Y+2);
                cout<<"  ";
}
//Melee

void meleeAttack(){
    if(playerDirection == 'L'){
        gotoxy(pX-1,pY);
        cout<<"|";
        gotoxy(pX-1,pY+1);
        cout<<"v";
        gotoxy(pX-1,pY+2);
        cout<<" ";
        Sleep(20);
        gotoxy(pX-1,pY);
        cout<<"\\";
        gotoxy(pX-1,pY+1);
        cout<<"v";
        gotoxy(pX-1,pY+2);
        cout<<" ";
        Sleep(10);
        gotoxy(pX-1,pY);
        cout<<" ";
        gotoxy(pX-1,pY+1);
        cout<<" ";
        gotoxy(pX-1,pY+2);
        cout<<" ";
    }
    if(playerDirection == 'R'){
        gotoxy(pX+4,pY);
        cout<<"|";
        gotoxy(pX+4,pY+1);
        cout<<"v";
        gotoxy(pX+4,pY+2);
        cout<<" ";
        Sleep(20);
        gotoxy(pX+4,pY);
        cout<<"/";
        gotoxy(pX+4,pY+1);
        cout<<"v";
        gotoxy(pX+4,pY+2);
         cout<<" ";
        Sleep(10);
        gotoxy(pX+4,pY);
        cout<<" ";
        gotoxy(pX+4,pY+1);
        cout<<" ";
        gotoxy(pX+4,pY+2);
        cout<<" ";
    }
}

// Bullet COllision
void bulletCollisionHitman(int& gX, int& gY, int& guardHealth){
    for(int i=0;i<bulletCount;i++){
        if(isBulletActive[i]){
            if(bulletX[i] + 1 == gX && (bulletY[i] >= gY - 1 && bulletY[i] <= gY + 3)){
                gameScore+= 10;
                guardHealth -= 10;
                impact(gX,gY);
                isBulletActive[i] = false;
            }
        }
    }
}

//       Enemies
#define HEAD_COLOR "\033[33m"   // Yellow for the head (to resemble a face)
#define UNIFORM_COLOR "\033[34m"   // Blue for the uniform (typical police color)
#define GUN_COLOR "\033[31m"    // Red for the gun
#define ARM_COLOR "\033[36m"    // Cyan for the arms
#define PANTS_COLOR "\033[32m"  // Green for the pants
#define BOOTS_COLOR "\033[37m"  // White for the boots (police officers' boots)

void printGuard(int gX, int gY, char direction) {
    if (direction == 'R') {  // Right-facing police officer
        gotoxy(gX, gY - 1);
        cout << ARM_COLOR << "  ^        " << RESET;  // Head in yellow
        gotoxy(gX, gY);
        cout << HEAD_COLOR << "  O        " << RESET;  // Head in yellow
        gotoxy(gX, gY + 1);
        cout << UNIFORM_COLOR << " /*|=====> " << RESET;  // Uniform in blue, gun in red
        gotoxy(gX, gY + 2);
        cout << PANTS_COLOR << " / \\      " << RESET;  // Pants in green
    } else if (direction == 'L') {  // Left-facing police officer
        gotoxy(gX, gY - 1);
        cout << HEAD_COLOR << "      ^    " << RESET;  // Head in yellow
        gotoxy(gX, gY);
        cout << HEAD_COLOR << "      O    " << RESET;  // Head in yellow
        gotoxy(gX, gY + 1);
        cout << UNIFORM_COLOR << "<=====|*\\ " << RESET;  // Uniform in blue, gun in red
        gotoxy(gX, gY + 2);
        cout << PANTS_COLOR << "     / \\  " << RESET;  // Pants in green
    }
}
void eraseGuard(int gX, int gY){
        gotoxy(gX, gY - 1);
        cout << "           ";
        gotoxy(gX, gY);
        cout << "           ";
        gotoxy(gX, gY+1);
        cout << "           ";
        gotoxy(gX, gY + 2);
        cout << "           ";
}

void moveGuard(int& gX, int&gY, char& guardDirection){
    eraseGuard(gX,gY);
    if(guardDirection == 'L'){ 
        gX--;
        if(gX == 5) guardDirection = 'R';
    }
    if(guardDirection == 'R'){
        gX++;
        if(gX == 100) guardDirection = 'L';
    }
    printGuard(gX,gY,guardDirection);
}

// GUARD SHOOTING

int guardBulletX[10000], guardBulletY[10000];
bool isGuardBulletActive[10000];
char guardBulletDirection[10000];
int guardBulletCount = 0;
int guardShootDelay = 0;

void guardBullet(int x,int y){
    gotoxy(x,y);
    cout<<"+";
}

void makeGuardBulletInactive(int n){
    isGuardBulletActive[n] = false;
}

void generateGuardBullet(char direction) {
    if (direction == 'R') {
        guardBulletX[guardBulletCount] = gX + 11;
        guardBulletY[guardBulletCount] = gY + 1;
    } else if (direction == 'L') {
        guardBulletX[guardBulletCount] = gX - 2;
        guardBulletY[guardBulletCount] = gY + 1;
    }
    isGuardBulletActive[guardBulletCount] = true;
    guardBulletDirection[guardBulletCount] = direction;
    guardBulletCount++;
}

void guardBulletActive(){
    if(pY >= gY - 1 && pY <= gY + 1){    
        isGuardBulletActive[bulletCount] = true;
        guardBulletDirection[bulletCount] = guardDirection;
        generateGuardBullet(guardBulletDirection[guardBulletCount]);
    }
}

void moveGuardBulletRight(int i) {
    char next = getCharAtxy(guardBulletX[i] + 1, guardBulletY[i]);
    if (next == '#') {
        eraseBullet(guardBulletX[i], guardBulletY[i]);
        makeGuardBulletInactive(i);
    } else {
        eraseBullet(guardBulletX[i], guardBulletY[i]);
        guardBulletX[i]+=2;
        guardBullet(guardBulletX[i], guardBulletY[i]);
    }
}

void moveGuardBulletLeft(int i) {
    char next = getCharAtxy(guardBulletX[i] - 1, guardBulletY[i]);
    if (next == '#') {
        eraseBullet(guardBulletX[i], guardBulletY[i]);
        makeGuardBulletInactive(i);
    } else{
        eraseBullet(guardBulletX[i], guardBulletY[i]);
        guardBulletX[i] -=2;
        guardBullet(guardBulletX[i], guardBulletY[i]);
    }
}

void moveGuardBullets() {
    for (int i = 0; i < guardBulletCount; i++) {
        if (isGuardBulletActive[i]) {
            if (guardBulletDirection[i] == 'R') {
                if (guardBulletX[i] > 160) { 
                    makeGuardBulletInactive(i);
                    eraseBullet(guardBulletX[i],guardBulletY[i]);
                } else {
                    moveGuardBulletRight(i);
                }
            } else if (guardBulletDirection[i] == 'L') {
                if (guardBulletX[i] <= 2) { 
                    makeGuardBulletInactive(i);
                    eraseBullet(guardBulletX[i],guardBulletY[i]);
                } else {    
                    moveGuardBulletLeft(i);
                }
            }
        }
    }
}

void handleGuardShooting() {
    if (guardShootDelay > 0) {
        guardShootDelay--;
    } else {
        if (pY >= gY - 1 && pY <= gY + 1) {
            if (guardDirection == 'L' && pX < gX) {
                generateGuardBullet('L'); 
            } else if (guardDirection == 'R' && pX > gX) {
                generateGuardBullet('R');
            }
        }
        guardShootDelay = 30;
    }
}

void bulletCollisionGuard(){
    for(int i=0;i<guardBulletCount;i++){
        if(isGuardBulletActive[i]){
            if(guardBulletX[i] + 1 == pX && (guardBulletY[i] >= pY - 1 && guardBulletY[i] <= pY + 3)){
                playerHealth -= 10;
                isGuardBulletActive[i] = false;
                eraseBullet(guardBulletX[i],guardBulletY[i]);
            }
        }
    }
}

void playerEnemyCollisionAndBoundaryCheck() {
    bool isCollidingHorizontally = 
        (pX >= gX && pX <= gX + 9) || 
        (pX + 3 >= gX && pX + 3 <= gX + 9) || 
        (pX + 3 >= gX - 9 && pX + 3 <= gX) || 
        (pX >= gX - 9 && pX <= gX);
    
    bool isCollidingVertically = 
        (pY >= gY - 1 && pY <= gY + 2) || 
        (pY + 1 >= gY - 1 && pY + 1 <= gY + 2) || 
        (pY + 2 >= gY - 1 && pY + 2 <= gY + 2);
    
    if (isCollidingHorizontally && isCollidingVertically) {
        playerHealth -= 20;
        if (playerHealth < 0) playerHealth = 0;
        if (pX < gX) pX = gX - 3;          // Push player to the left of the enemy
        else if (pX > gX) pX = gX + 9;     // Push player to the right of the enemy
        if (pY < gY) pY = gY - 3;          // Push player above the enemy
        else if (pY > gY) pY = gY + 3;     // Push player below the enemy
    }
}

void guard1(){
    if(guardHealth > 0){
        moveGuard(gX,gY,guardDirection);
        handleGuardShooting();
        moveGuardBullets();
        bulletCollisionHitman(gX,gY,guardHealth);
        bulletCollisionGuard();
    }
}
// GUARD 2 SHOOTING

int g2X = 89, g2Y = pY - 8;
char guard2Direction = 'L';
int guard2Health = 100;
int guard2BulletX[10000], guard2BulletY[10000];
bool isGuard2BulletActive[10000];
char guard2BulletDirection[10000];
int guard2BulletCount = 0;
int guard2ShootDelay = 0;


void makeGuard2BulletInactive(int n){
    isGuard2BulletActive[n] = false;
}

void generateGuard2Bullet(char direction) {
    if (direction == 'R') {
        guard2BulletX[guard2BulletCount] = g2X + 11;
        guard2BulletY[guard2BulletCount] = g2Y + 1;
    } else if (direction == 'L') {
        guard2BulletX[guard2BulletCount] = g2X - 2;
        guard2BulletY[guard2BulletCount] = g2Y + 1;
    }
    isGuard2BulletActive[guard2BulletCount] = true;
    guard2BulletDirection[guard2BulletCount] = direction;
    guard2BulletCount++;
}

void guard2BulletActive(){
    if(pY >= g2Y - 1 && pY <= g2Y + 1){    
        isGuard2BulletActive[bulletCount] = true;
        guard2BulletDirection[bulletCount] = guard2Direction;
        generateGuard2Bullet(guard2BulletDirection[guard2BulletCount]);
    }
}

void moveGuard2BulletRight(int i) {
    char next = getCharAtxy(guard2BulletX[i] + 1, guard2BulletY[i]);
    if (next == '#') {
        eraseBullet(guard2BulletX[i], guard2BulletY[i]);
        makeGuard2BulletInactive(i);
    } else {
        eraseBullet(guard2BulletX[i], guard2BulletY[i]);
        guard2BulletX[i]+=2;
        guardBullet(guard2BulletX[i], guard2BulletY[i]);
    }
}

void moveGuard2BulletLeft(int i) {
    char next = getCharAtxy(guard2BulletX[i] - 1, guard2BulletY[i]);
    if (next == '#') {
        eraseBullet(guard2BulletX[i], guard2BulletY[i]);
        makeGuard2BulletInactive(i);
    } else{
        eraseBullet(guard2BulletX[i], guard2BulletY[i]);
        guard2BulletX[i] -=2;
        guardBullet(guard2BulletX[i], guard2BulletY[i]);
    }
}

void moveGuard2Bullets() {
    for (int i = 0; i < guard2BulletCount; i++) {
        if (isGuard2BulletActive[i]) {
            if (guard2BulletDirection[i] == 'R') {
                if (guard2BulletX[i] > 160) { 
                    makeGuard2BulletInactive(i);
                    eraseBullet(guard2BulletX[i],guard2BulletY[i]);
                } else {
                    moveGuard2BulletRight(i);
                }
            } else if (guard2BulletDirection[i] == 'L') {
                if (guard2BulletX[i] <= 2) { 
                    makeGuard2BulletInactive(i);
                    eraseBullet(guard2BulletX[i],guard2BulletY[i]);
                } else {    
                    moveGuard2BulletLeft(i);
                }
            }
        }
    }
}

void handleGuard2Shooting() {
    if (guard2ShootDelay > 0) {
        guard2ShootDelay--;
    } else {
        if (pY >= g2Y - 1 && pY <= g2Y + 1) {
            if (guard2Direction == 'L' && pX < g2X) {
                generateGuard2Bullet('L'); 
            } else if (guard2Direction == 'R' && pX > g2X) {
                generateGuard2Bullet('R');
            }
        }
        guard2ShootDelay = 30;
    }
}

void bulletCollisionGuard2(){
    for(int i=0;i<guard2BulletCount;i++){
        if(isGuard2BulletActive[i]){
            if(guard2BulletX[i] + 1 == pX && (guard2BulletY[i] >= pY - 1 && guard2BulletY[i] <= pY + 3)){
                playerHealth -= 10;
                isGuard2BulletActive[i] = false;
                eraseBullet(guardBulletX[i],guardBulletY[i]);
            }
        }
    }
}

void guard2(){
    if(guard2Health > 0);
        moveGuard(g2X,g2Y, guard2Direction);
        handleGuard2Shooting();
        moveGuard2Bullets();
        bulletCollisionHitman(g2X,g2Y,guard2Health);
        bulletCollisionGuard2();
}



// Guard 3

int g3X = 70, g3Y = pY - 16;
char guard3Direction = 'R';
int guard3Health = 100;
int guard3BulletX[10000], guard3BulletY[10000];
bool isGuard3BulletActive[10000];
char guard3BulletDirection[10000];
int guard3BulletCount = 0;
int guard3ShootDelay = 0;

void makeGuard3BulletInactive(int n) {
    isGuard3BulletActive[n] = false;
}

void generateGuard3Bullet(char direction) {
    if (direction == 'R') {
        guard3BulletX[guard3BulletCount] = g3X + 11;
        guard3BulletY[guard3BulletCount] = g3Y + 1;
    } else if (direction == 'L') {
        guard3BulletX[guard3BulletCount] = g3X - 2;
        guard3BulletY[guard3BulletCount] = g3Y + 1;
    }
    isGuard3BulletActive[guard3BulletCount] = true;
    guard3BulletDirection[guard3BulletCount] = direction;
    guard3BulletCount++;
}

void moveGuard3BulletRight(int i) {
    char next = getCharAtxy(guard3BulletX[i] + 1, guard3BulletY[i]);
    if (next == '#') {
        eraseBullet(guard3BulletX[i], guard3BulletY[i]);
        makeGuard3BulletInactive(i);
    } else {
        eraseBullet(guard3BulletX[i], guard3BulletY[i]);
        guard3BulletX[i] += 2;
        guardBullet(guard3BulletX[i], guard3BulletY[i]);
    }
}

void moveGuard3BulletLeft(int i) {
    char next = getCharAtxy(guard3BulletX[i] - 1, guard3BulletY[i]);
    if (next == '#') {
        eraseBullet(guard3BulletX[i], guard3BulletY[i]);
        makeGuard3BulletInactive(i);
    } else {
        eraseBullet(guard3BulletX[i], guard3BulletY[i]);
        guard3BulletX[i] -= 2;
        guardBullet(guard3BulletX[i], guard3BulletY[i]);
    }
}

void moveGuard3Bullets() {
    for (int i = 0; i < guard3BulletCount; i++) {
        if (isGuard3BulletActive[i]) {
            if (guard3BulletDirection[i] == 'R') {
                if (guard3BulletX[i] > 160) {
                    makeGuard3BulletInactive(i);
                    eraseBullet(guard3BulletX[i], guard3BulletY[i]);
                } else {
                    moveGuard3BulletRight(i);
                }
            } else if (guard3BulletDirection[i] == 'L') {
                if (guard3BulletX[i] <= 2) {
                    makeGuard3BulletInactive(i);
                    eraseBullet(guard3BulletX[i], guard3BulletY[i]);
                } else {
                    moveGuard3BulletLeft(i);
                }
            }
        }
    }
}

void handleGuard3Shooting() {
    if (guard3ShootDelay > 0) {
        guard3ShootDelay--;
    } else {
        if (pY >= g3Y - 1 && pY <= g3Y + 1) {
            if (guard3Direction == 'L' && pX < g3X) {
                generateGuard3Bullet('L');
            } else if (guard3Direction == 'R' && pX > g3X) {
                generateGuard3Bullet('R');
            }
        }
        guard3ShootDelay = 30;
    }
}

void bulletCollisionGuard3() {
    for (int i = 0; i < guard3BulletCount; i++) {
        if (isGuard3BulletActive[i]) {
            if (guard3BulletX[i] + 1 == pX && (guard3BulletY[i] >= pY - 1 && guard3BulletY[i] <= pY + 3)) {
                playerHealth -= 10;
                isGuard3BulletActive[i] = false;
                eraseBullet(guardBulletX[i], guardBulletY[i]);
            }
        }
    }
}

void guard3() {
    if (guard3Health > 0) {
        moveGuard(g3X, g3Y, guard3Direction);
        handleGuard3Shooting();
        moveGuard3Bullets();
        bulletCollisionHitman(g3X, g3Y,guard3Health);
        bulletCollisionGuard3();
    }
}


// Define variables and functions for Guard 4
int g4X = 60, g4Y = pY -24;
char guard4Direction = 'R';
int guard4Health = 100;
int guard4BulletX[10000], guard4BulletY[10000];
bool isGuard4BulletActive[10000];
char guard4BulletDirection[10000];
int guard4BulletCount = 0;
int guard4ShootDelay = 0;

void makeGuard4BulletInactive(int n) {
    isGuard4BulletActive[n] = false;
}

void generateGuard4Bullet(char direction) {
    if (direction == 'R') {
        guard4BulletX[guard4BulletCount] = g4X + 11;
        guard4BulletY[guard4BulletCount] = g4Y + 1;
    } else if (direction == 'L') {
        guard4BulletX[guard4BulletCount] = g4X - 2;
        guard4BulletY[guard4BulletCount] = g4Y + 1;
    }
    isGuard4BulletActive[guard4BulletCount] = true;
    guard4BulletDirection[guard4BulletCount] = direction;
    guard4BulletCount++;
}

void moveGuard4BulletRight(int i) {
    char next = getCharAtxy(guard4BulletX[i] + 1, guard4BulletY[i]);
    if (next == '#') {
        eraseBullet(guard4BulletX[i], guard4BulletY[i]);
        makeGuard4BulletInactive(i);
    } else {
        eraseBullet(guard4BulletX[i], guard4BulletY[i]);
        guard4BulletX[i] += 2;
        guardBullet(guard4BulletX[i], guard4BulletY[i]);
    }
}

void moveGuard4BulletLeft(int i) {
    char next = getCharAtxy(guard4BulletX[i] - 1, guard4BulletY[i]);
    if (next == '#') {
        eraseBullet(guard4BulletX[i], guard4BulletY[i]);
        makeGuard4BulletInactive(i);
    } else {
        eraseBullet(guard4BulletX[i], guard4BulletY[i]);
        guard4BulletX[i] -= 2;
        guardBullet(guard4BulletX[i], guard4BulletY[i]);
    }
}

void moveGuard4Bullets() {
    for (int i = 0; i < guard4BulletCount; i++) {
        if (isGuard4BulletActive[i]) {
            if (guard4BulletDirection[i] == 'R') {
                if (guard4BulletX[i] > 160) {
                    makeGuard4BulletInactive(i);
                    eraseBullet(guard4BulletX[i], guard4BulletY[i]);
                } else {
                    moveGuard4BulletRight(i);
                }
            } else if (guard4BulletDirection[i] == 'L') {
                if (guard4BulletX[i] <= 2) {
                    makeGuard4BulletInactive(i);
                    eraseBullet(guard4BulletX[i], guard4BulletY[i]);
                } else {
                    moveGuard4BulletLeft(i);
                }
            }
        }
    }
}

void handleGuard4Shooting() {
    if (guard4ShootDelay > 0) {
        guard4ShootDelay--;
    } else {
        if (pY >= g4Y - 1 && pY <= g4Y + 1) {
            if (guard4Direction == 'L' && pX < g4X) {
                generateGuard4Bullet('L');
            } else if (guard4Direction == 'R' && pX > g4X) {
                generateGuard4Bullet('R');
            }
        }
        guard4ShootDelay = 30;
    }
}

void bulletCollisionGuard4() {
    for (int i = 0; i < guard4BulletCount; i++) {
        if (isGuard4BulletActive[i]) {
            if (guard4BulletX[i] + 1 == pX && (guard4BulletY[i] >= pY - 1 && guard4BulletY[i] <= pY + 3)) {
                playerHealth -= 10;
                isGuard4BulletActive[i] = false;
                eraseBullet(guardBulletX[i], guardBulletY[i]);
            }
        }
    }
}

void guard4() {
    if (guard4Health > 0) {
        moveGuard(g4X, g4Y, guard4Direction);
        handleGuard4Shooting();
        moveGuard4Bullets();
        bulletCollisionHitman(g4X, g4Y, guard4Health);
        bulletCollisionGuard4();
    }
}

// Define variables and functions for Guard 5
int g5X = 50, g5Y = pY - 32;
char guard5Direction = 'L';
int guard5Health = 100;
int guard5BulletX[10000], guard5BulletY[10000];
bool isGuard5BulletActive[10000];
char guard5BulletDirection[10000];
int guard5BulletCount = 0;
int guard5ShootDelay = 0;

void makeGuard5BulletInactive(int n) {
    isGuard5BulletActive[n] = false;
}

void generateGuard5Bullet(char direction) {
    if (direction == 'R') {
        guard5BulletX[guard5BulletCount] = g5X + 11;
        guard5BulletY[guard5BulletCount] = g5Y + 1;
    } else if (direction == 'L') {
        guard5BulletX[guard5BulletCount] = g5X - 2;
        guard5BulletY[guard5BulletCount] = g5Y + 1;
    }
    isGuard5BulletActive[guard5BulletCount] = true;
    guard5BulletDirection[guard5BulletCount] = direction;
    guard5BulletCount++;
}

void moveGuard5BulletRight(int i) {
    char next = getCharAtxy(guard5BulletX[i] + 1, guard5BulletY[i]);
    if (next == '#') {
        eraseBullet(guard5BulletX[i], guard5BulletY[i]);
        makeGuard5BulletInactive(i);
    } else {
        eraseBullet(guard5BulletX[i], guard5BulletY[i]);
        guard5BulletX[i] += 2;
        guardBullet(guard5BulletX[i], guard5BulletY[i]);
    }
}

void moveGuard5BulletLeft(int i) {
    char next = getCharAtxy(guard5BulletX[i] - 1, guard5BulletY[i]);
    if (next == '#') {
        eraseBullet(guard5BulletX[i], guard5BulletY[i]);
        makeGuard5BulletInactive(i);
    } else {
        eraseBullet(guard5BulletX[i], guard5BulletY[i]);
        guard5BulletX[i] -= 2;
        guardBullet(guard5BulletX[i], guard5BulletY[i]);
    }
}

void moveGuard5Bullets() {
    for (int i = 0; i < guard5BulletCount; i++) {
        if (isGuard5BulletActive[i]) {
            if (guard5BulletDirection[i] == 'R') {
                if (guard5BulletX[i] > 160) {
                    makeGuard5BulletInactive(i);
                    eraseBullet(guard5BulletX[i], guard5BulletY[i]);
                } else {
                    moveGuard5BulletRight(i);
                }
            } else if (guard5BulletDirection[i] == 'L') {
                if (guard5BulletX[i] <= 2) {
                    makeGuard5BulletInactive(i);
                    eraseBullet(guard5BulletX[i], guard5BulletY[i]);
                } else {
                    moveGuard5BulletLeft(i);
                }
            }
        }
    }
}

void handleGuard5Shooting() {
    if (guard5ShootDelay > 0) {
        guard5ShootDelay--;
    } else {
        if (pY >= g5Y - 1 && pY <= g5Y + 1) {
            if (guard5Direction == 'L' && pX < g5X) {
                generateGuard5Bullet('L');
            } else if (guard5Direction == 'R' && pX > g5X) {
                generateGuard5Bullet('R');
            }
        }
        guard5ShootDelay = 30;
    }
}

void bulletCollisionGuard5() {
    for (int i = 0; i < guard5BulletCount; i++) {
        if (isGuard5BulletActive[i]) {
            if (guard5BulletX[i] + 1 == pX && (guard5BulletY[i] >= pY - 1 && guard5BulletY[i] <= pY + 3)) {
                playerHealth -= 10;
                isGuard5BulletActive[i] = false;
                eraseBullet(guardBulletX[i], guardBulletY[i]);
            }
        }
    }
}

void guard5() {
    if (guard5Health > 0) {
        moveGuard(g5X, g5Y, guard5Direction);
        handleGuard5Shooting();
        moveGuard5Bullets();
        bulletCollisionHitman(g5X, g5Y,guard5Health);
        bulletCollisionGuard5();
    }
}



// Guards killing
void guardsKilled(){
    if(guardHealth  <=0) eraseGuard(gX,gY);
    if(guard2Health <= 0) eraseGuard(g2X,g2Y);
    if(guard3Health <= 0) eraseGuard(g3X,g3Y);
    if(guard4Health <= 0) eraseGuard(g4X,g4Y);
    if(guard5Health <= 0) eraseGuard(g5X,g5Y);
}

// SCORE
void score() {
    gotoxy(200, 2);  
    cout << "\033[1;33m------------------------------\n";
    gotoxy(200, 3);
    cout << "|   *** GAME SCOREBOARD ***   |";
    gotoxy(200, 4);
    cout << "------------------------------\n";
    cout << "\033[0m";  
    gotoxy(200, 6);
    
    cout <<HEAD_COLOR<< "Game Score: " << gameScore << "\033[0m";
    
    gotoxy(200, 7);
    cout <<BODY_COLOR << "Player Health: " << playerHealth << RESET;
    
    gotoxy(200, 8);
    if(guardHealth <= 0) cout<<BLOOD<<"guardKilled                   "<<RESET;
    else cout << "Guard 1 Health: " << guardHealth;
    gotoxy(200, 9);
    if(guard2Health <= 0) cout<<BLOOD<<"guardKilled                  "<<RESET;
    else cout << "Guard 2 Health: " << guard2Health;
    gotoxy(200, 10);
    if(guard3Health <=0) cout<<BLOOD<<"GuardKilled                   "<<RESET;
    else cout << "Guard 3 Health: " << guard3Health;
    gotoxy(200, 11);
    if(guard4Health <=0) cout<<BLOOD<<"GuardKilled                   "<<RESET;
    else cout << "Guard 4 Health: " << guard4Health;
    gotoxy(200, 12);
    if(guard5Health <=0) cout<<BLOOD<<"GuardKilled                   "<<RESET;
    else cout << "Guard 5 Health: " << guard5Health;

    // Print Remaining Ammunition
    gotoxy(200, 13);
    cout << "\033[1;36mRemaining Ammo: " << 100 - bulletCount << "\033[0m";
    
    // Closing line
    gotoxy(200, 15);
    cout << "\033[1;33m------------------------------\n";

    gotoxy(200, 17);

}


void meleeDamage(){
    // Arrays for guard positions
    int guardPositionsX[] = {gX, g2X, g3X, g4X, g5X};
    int guardPositionsY[] = {gY, g2Y, g3Y, g4Y, g5Y};
    int guardHealths[] = {guardHealth, guard2Health, guard3Health, guard4Health, guard5Health};
    for (int i = 0; i < 5; ++i) {
        if (playerDirection == 'R') {
            if (((pX + 4 == guardPositionsX[i] || pX + 4 == guardPositionsX[i] + 1 || 
                 pX + 4 == guardPositionsX[i] + 2 || pX + 4 == guardPositionsX[i] + 3) && 
                (pY == guardPositionsY[i] || pY + 1 == guardPositionsY[i] || 
                 pY + 2 == guardPositionsY[i] || pY - 1 == guardPositionsY[i]))) {
                gameScore += 10;
                guardHealths[i] -= 10;  
                impact(guardPositionsX[i], guardPositionsY[i]);  
                switch(i) {
                    case 0: guardHealth = guardHealths[i]; break;
                    case 1: guard2Health = guardHealths[i]; break;
                    case 2: guard3Health = guardHealths[i]; break;
                    case 3: guard4Health = guardHealths[i]; break;
                    case 4: guard5Health = guardHealths[i]; break;
                }
            }
        }

        if (playerDirection == 'L') {
            if (((pX == guardPositionsX[i] + 8 || pX == guardPositionsX[i] + 6 || 
                 pX == guardPositionsX[i] + 7 || pX == guardPositionsX[i] + 9) && 
                (pY == guardPositionsY[i] || pY + 1 == guardPositionsY[i] || 
                 pY + 2 == guardPositionsY[i] || pY - 1 == guardPositionsY[i]))) {
                gameScore += 10;
                guardHealths[i] -= 10;  // Decrease health in the array
                impact(guardPositionsX[i], guardPositionsY[i]);  
                
                // Update the corresponding global guard health
                switch(i) {
                    case 0: guardHealth = guardHealths[i]; break;
                    case 1: guard2Health = guardHealths[i]; break;
                    case 2: guard3Health = guardHealths[i]; break;
                    case 3: guard4Health = guardHealths[i]; break;
                    case 4: guard5Health = guardHealths[i]; break;
                }
            }
        }
    }
}

void getAmmunation() {
    gotoxy(45, rand());
    cout << "&&";  
    
    for (int i = 0; i < 3; ++i) {  
        for (int j = 0; j < 3; ++j) {
            if (getCharAtxy(pX + i, pY + j) == '&') {
                gameScore += 10;  
                break;  
            }
        }
    }
}

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return columns;
}

void printCentered(const string& text) {
    int width = getConsoleWidth();
    int padding = (width - text.length()) / 2;
    for (int i = 0; i < padding; ++i) cout << " ";
    cout << text << endl;
}

void printMenu(){
    system("cls");

    // Align and print the lines with the appropriate color
    cout<<endl;
    cout<<endl;
    printCentered("                                       \033[1;33m\033[1;32m$$\\\033[1;33m   $$\\ \033[1;32m$$$$$$\\ \033[1;33m$$$$$$$$\\ \033[1;33m$$\\      $$\\  \033[1;33m$$$$$$\\ \033[1;33m$$\\   $$\\             $$\\   $$\\ \033[0m");
    printCentered("      \033[1;33m$$ |  $$ |\\_$$  _|\\__$$  __|$$$\\    $$$ |\033[1;32m$$  __$$\\ \033[1;33m$$$$\\  $$ |            $$ |  $$ | \033[0m");
    printCentered("      \033[1;33m$$ |  $$ |  $$ |     $$ |   $$$$\\  $$$$ |\033[1;32m$$ /  $$ | \033[1;33m$$$$\\ $$ |            $$ |  $$ | \033[0m");
    printCentered("\033[1;33m$$$$$$$$ |  $$ |     $$ |   $$\\$$\\$$ $$ |\033[1;32m$$$$$$$$ |$$ $$\\$$ |            $$$$$$$$ | \033[0m");
    printCentered("\033[1;33m$$  __$$ |  $$ |     $$ |   $$ \\$$$  $$ |\033[1;32m$$  __$$ |$$ \\$$$$ |            \\_____$$ | \033[0m");
    printCentered("\033[1;33m$$ |  $$ |  $$ |     $$ |   $$ |\\$  /$$ |\033[1;32m$$ |  $$ |$$ |\\$$$ |                  $$ | \033[0m");
    printCentered("\033[1;33m$$ |  $$ |$$$$$$\\    $$ |   $$ | \\_/ $$ |\033[1;32m$$ |  $$ |$$ | \\$$ |                  $$ | \033[0m");
    printCentered("\033[1;33m\\__|  \\__|\\______|   \\__|   \\__|     \\__|\\__|  \\__|  \\__|                  \\__| \033[0m");

    cout << BLOOD << "Press Any Key To continue.." << RESET;
    getch();
}

void youLost() {
    system("cls");
    cout << "\033[1;33m$$\\     $$\\                         $$\\                       $$\\     \033[0m" << endl;
    cout << "\033[1;33m\\$$\\   $$  |                        $$ |                      $$ |    \033[0m" << endl;
    cout << "\033[1;33m \\$$\\ $$  /$$$$$$\\  $$\\   $$\\       $$ | $$$$$$\\   $$$$$$$\\ $$$$$$\\   \033[0m" << endl;
    cout << "\033[1;33m  \\$$$$  /$$  __$$\\ $$ |  $$ |      $$ |$$  __$$\\ $$  _____|\\_$$  _|  \033[0m" << endl;
    cout << "\033[1;33m   \\$$  / $$ /  $$ |$$ |  $$ |      $$ |$$ /  $$ |\\$$$$$$\\    $$ |    \033[0m" << endl;
    cout << "\033[1;33m    $$ |  $$ |  $$ |$$ |  $$ |      $$ |$$ |  $$ | \\____$$\\   $$ |$$\\  \033[0m" << endl;
    cout << "\033[1;33m    $$ |  \\$$$$$$  |\\$$$$$$  |      $$ |\\$$$$$$  |$$$$$$$  |  \\$$$$  |  \033[0m" << endl;
    cout << "\033[1;33m    \\__|   \\______/  \\______/       \\__| \\______/ \\_______/    \\____/   \033[0m" << endl;
}


void youWon(){

    {
        cout << "\033[1;33m$$\\     $$\\                                                           \033[0m" << endl;
        cout << "\033[1;33m\\$$\\   $$  |                                                          \033[0m" << endl;
        cout << "\033[1;33m \\$$\\ $$  /$$$$$$\\  $$\\   $$\\       $$\\  $$\\  $$\\  $$$$$$\\  $$$$$$$\\  \033[0m" << endl;
        cout << "\033[1;33m  \\$$$$  /$$  __$$\\ $$ |  $$ |      $$ | $$ | $$ |$$  __$$\\ $$  __$$\\  \033[0m" << endl;
        cout << "\033[1;33m   \\$$  / $$ /  $$ |$$ |  $$ |      $$ | $$ | $$ |$$ /  $$ |$$ |  $$ |  \033[0m" << endl;
        cout << "\033[1;33m    $$ |  $$ |  $$ |$$ |  $$ |      $$ | $$ | $$ |$$ |  $$ |$$ |  $$ |  \033[0m" << endl;
        cout << "\033[1;33m    $$ |  \\$$$$$$  |\\$$$$$$  |      \\$$$$$\\$$$$  |\\$$$$$$  |$$ |  $$ |  \033[0m" << endl;
        cout << "\033[1;33m    \\__|   \\______/  \\______/        \\_____\\____/  \\______/ \\__|  \\__|   \033[0m" << endl;

    }
    
}

int main(){
    string opt;
    while(true){
        printMenu();
        system("cls");
        curser();
        printMaze1();
        playerDirection = 'S';
        printHitman(pX,pY,playerDirection);
        printGuard(gX,gY,guardDirection);
        while(true){
            printHitman(pX,pY,playerDirection);
            if (GetAsyncKeyState(VK_LEFT)) {
                playerDirection = 'L';
                movePlayer();
            }
            if (GetAsyncKeyState(VK_RIGHT)){
                playerDirection = 'R';
                movePlayer();
            }
            if (GetAsyncKeyState(VK_UP)){
                playerDirection = 'U';
                movePlayer();
            }   
            if (GetAsyncKeyState(VK_DOWN)){
                playerDirection = 'D';
                movePlayer();
            }
            if (GetAsyncKeyState(VK_TAB)){
                meleeAttack();
                meleeDamage();
                
            }
            if (GetAsyncKeyState(VK_SPACE)){
                shootBullet();
            }
            score();
            moveBullets();
            guard1();
            guard2();
            guard3();
            guard4();
            guard5();
            guardsKilled();
            Sleep(20);
            if(playerHealth <= 0){
                youLost();
                break;
            }
        }
        if(guardHealth <= 0 && guard2Health <= 0 && guard3Health <=0 && guard4Health <= 0 && guard5Health <=0) youWon();
        playerHealth = 100;
        cout<<"Press q to quit, any key to continue"<<endl;
        cin>>opt;
        if(opt == "q") break;
    }
    
    return 0;
}