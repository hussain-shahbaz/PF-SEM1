#include<iostream>
#include<windows.h>
using namespace std;
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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

void eraseCursor(){
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
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
string path = "#       ###############################################################################################################################################################";

void printMaze1() {
    setColor(04);
    singleline();
    for (int i = 1; i < 48; i++) {
        if (i % 12 == 0)       cout << path << endl;
        else if(i%12 == 6) cout<< reverse(path) <<endl;
        else borders();
    }
    singleline();
}

// Player movement

int pX = 2,pY = 44;
char playerDirection;

void printHitman(int pX, int pY, char direction) {
    if (direction == 'S') {
        gotoxy(pX, pY);
        cout << "  O   ";
        gotoxy(pX, pY + 1);
        cout << " /|\\ ";
        gotoxy(pX, pY + 2);
        cout << " / \\ ";
    } else if (direction == 'R') {
        gotoxy(pX, pY);
        cout << "  O   ";
        gotoxy(pX, pY + 1);
        cout << " /|=> ";
        gotoxy(pX, pY + 2);
        cout << " / \\ ";
    } else if (direction == 'L') { 
        gotoxy(pX, pY);
        cout << "  O   ";
        gotoxy(pX, pY + 1);
        cout << "<=|\\ ";
        gotoxy(pX, pY + 2);
        cout << " / \\ ";
    } else if (direction == 'U') { 
        
        gotoxy(pX, pY);
        cout << "  O-^-";
        gotoxy(pX, pY + 1);
        cout << " /|\\ ";
        gotoxy(pX, pY + 2);
        cout << " / \\ ";
    } else if(direction = 'D'){
        gotoxy(pX, pY);
        cout << "  O_ _";
        gotoxy(pX, pY + 1);
        cout << " /|\\V";
        gotoxy(pX, pY + 2);
        cout << " / \\ ";
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
int gX = 23,gY = pY;
int 
guardHealth = 100;
int guard2Health = 100;
int playerHealth = 100;
int gameScore = 0;

int g2X = 23, g2Y = pY - 12, g3X, g3Y, g4X, g4Y, g5X, g5Y;
char guard2Direction = 'R', guard3Direction = 'R', guard4Direction = 'R', guard5Direction = 'R';
// Shooting mechanics

char bulletDirection[100];
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount = 0;

void bullet(int x, int y){
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
void bulletCollisionHitman(int& gX, int& gY){
    for(int i=0;i<bulletCount;i++){
        if(isBulletActive[i]){
            if(bulletX[i] + 1 == gX && (bulletY[i] >= gY - 1 && bulletY[i] <= gY + 3)){
                gameScore+= 10;
                guardHealth -=10;
                isBulletActive[i] = false;
            }
        }
    }
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

void meleeDamage(){
    if(playerDirection == 'L'){
        if(((pX + 4 == gX + 8 || pX + 4 == gX + 9 || pX  +4 == gX + 7 || pX + 4 == gX + 6) && 
            (pY == gY || pY + 1 == gY || pY + 2 == gY || pY - 1 == gY))) gameScore += 10;
    }
    if(playerDirection == 'R'){
        if(((pX + 4 == gX + 8 || pX + 4 == gX + 9 || pX  +4 == gX + 7 || pX + 4 == gX + 6) && 
            (pY == gY || pY + 1 == gY || pY + 2 == gY || pY - 1 == gY))) gameScore += 10;
    }
}
// Score
void score(){
    gotoxy(200,9);
    cout<<"Remaining aimo: "<<100-bulletCount<<endl;
    gotoxy(200,10);
    cout<<"Game score: " << gameScore << endl;
    gotoxy(200,20);
    cout<<"Player Health: " << playerHealth<<endl;
    gotoxy(200,22);
    cout<<"Guard Health: " << guardHealth<<endl;
}

int health = 100;

// Enemies

void printGuard(int gX, int gY,char direction) {
    
    if (direction == 'R') { 
        gotoxy(gX, gY - 1);
        cout << "  ^        ";
        gotoxy(gX, gY);
        cout << "  O        ";
        gotoxy(gX, gY + 1);
        cout << " /*|=====> ";
        gotoxy(gX, gY + 2);
        cout << " / \\      ";
    } else if (direction == 'L') {
        gotoxy(gX, gY - 1);
        cout << "      ^    ";
        gotoxy(gX, gY);
        cout << "      O    ";
        gotoxy(gX, gY+1);
        cout << "<=====|*\\ ";
        gotoxy(gX, gY + 2);
        cout << "     / \\  ";
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

void moveGuard(int& gX, int& gY){
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

void guardBulletActive(int& gX, int& gY){
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
                    eraseBullet(guardBulletX[i],guardBulletY[i]);
                    makeGuardBulletInactive(i);
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

void handleGuardShooting(int& guardHealth) {
    if(guardHealth <=0) return;
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
    // Collision Detection
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

void guardFunction(int &gX, int& gY,int guardHealth){
            moveGuard(gX,gY);
            printGuard(gX,gY,guardDirection);
            guardBulletActive(gX,gY);
            handleGuardShooting(guardHealth);
            moveGuardBullets();
            bulletCollisionHitman(gX,gY);
            bulletCollisionGuard();
}

//Guard2

int guard2BulletX[10000], guard2BulletY[10000];
bool isGuard2BulletActive[10000];
char guard2BulletDirection[10000];
int guard2BulletCount = 0;
int guard2ShootDelay = 0;


bool alive = true;
int healthUpdate(int guardHealth){
    return max(guardHealth,0);
}
int main(){
    // setColor(24);
    eraseCursor();
    system("cls");
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
            if(bulletCount < 100){
                isBulletActive[bulletCount] = true;
                bulletDirection[bulletCount] = playerDirection;
                generateBullet(bulletDirection[bulletCount]);
            }
        }
        score();
        moveBullets();
        if(guardHealth >0){
            guardFunction(gX,gY,guardHealth);
        }
        // if(guard2Health >0){
        //     guardFunction(g2X,g2Y,guard2Health);
        // }
        if(guardHealth == 0) eraseGuard(gX,gY);
        Sleep(20);
    }
    
    return 0;
}