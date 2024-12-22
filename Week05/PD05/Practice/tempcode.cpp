#include<iostream>
#include<windows.h>
using namespace std;

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
string path = "#       ###############################################################################################################################################################";

void printMaze1() {
    singleline();
    for (int i = 1; i < 48; i++) {
        if (i % 24 == 0)       cout << path << endl;
        else if(i%24 == 6) cout<< reverse(path) <<endl;
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

// char guardDirection = 'L';
// int gX = 23,gY = pY;
// int guardHealth = 100;
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



void shootBullet(){
    isBulletActive[bulletCount] = true;
    bulletDirection[bulletCount] = playerDirection;
    generateBullet(bulletDirection[bulletCount]);
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

// void meleeDamage(){
//     if(playerDirection == 'L'){
//         if(((pX + 4 == gX + 8 || pX + 4 == gX + 9 || pX  +4 == gX + 7 || pX + 4 == gX + 6) && 
//             (pY == gY || pY + 1 == gY || pY + 2 == gY || pY - 1 == gY))) gameScore += 10;
//     }
//     if(playerDirection == 'R'){
//         if(((pX + 4 == gX + 8 || pX + 4 == gX + 9 || pX  +4 == gX + 7 || pX + 4 == gX + 6) && 
//             (pY == gY || pY + 1 == gY || pY + 2 == gY || pY - 1 == gY))) gameScore += 10;
//     }
// }
// Score


int health = 100;

// Enemies

const int guardCount = 4;

// Guard variables
int gX[guardCount] = {10, 50, 90, 130};
int gY[guardCount] = {10, 12, 14, 16};
char guardDirection[guardCount] = {'R', 'L', 'R', 'L'};
int guardHealth[guardCount] = {100,100,100,100};

// Bullet variables
int guardBulletX[10000], guardBulletY[10000];
bool isGuardBulletActive[10000];
char guardBulletDirection[10000];
int guardBulletCount = 0;
int guardShootDelay[guardCount] = {0};

// Print a guard
void printGuard(int index) {
    if (guardDirection[index] == 'R') { 
        gotoxy(gX[index], gY[index] - 1);
        cout << "  ^        ";
        gotoxy(gX[index], gY[index]);
        cout << "  O        ";
        gotoxy(gX[index], gY[index] + 1);
        cout << " /*|=====> ";
        gotoxy(gX[index], gY[index] + 2);
        cout << " / \\      ";
    } else if (guardDirection[index] == 'L') {
        gotoxy(gX[index], gY[index] - 1);
        cout << "      ^    ";
        gotoxy(gX[index], gY[index]);
        cout << "      O    ";
        gotoxy(gX[index], gY[index] + 1);
        cout << "<=====|*\\ ";
        gotoxy(gX[index], gY[index] + 2);
        cout << "     / \\  ";
    }
}

// Erase a guard
void eraseGuard(int index) {
    gotoxy(gX[index], gY[index] - 1);
    cout << "           ";
    gotoxy(gX[index], gY[index]);
    cout << "           ";
    gotoxy(gX[index], gY[index] + 1);
    cout << "           ";
    gotoxy(gX[index], gY[index] + 2);
    cout << "           ";
}

// Move a guard
void moveGuard(int index) {
    eraseGuard(index);
    if (guardDirection[index] == 'L') { 
        gX[index]--;
        if (gX[index] == 5) guardDirection[index] = 'R';
    } else if (guardDirection[index] == 'R') {
        gX[index]++;
        if (gX[index] == 100) guardDirection[index] = 'L';
    }
    printGuard(index);
}

// Generate a bullet for a specific guard
void generateGuardBullet(int index) {
    if (guardDirection[index] == 'R') {
        guardBulletX[guardBulletCount] = gX[index] + 11;
        guardBulletY[guardBulletCount] = gY[index] + 1;
    } else if (guardDirection[index] == 'L') {
        guardBulletX[guardBulletCount] = gX[index] - 2;
        guardBulletY[guardBulletCount] = gY[index] + 1;
    }
    isGuardBulletActive[guardBulletCount] = true;
    guardBulletDirection[guardBulletCount] = guardDirection[index];
    guardBulletCount++;
}

// Handle guard shooting
void handleGuardShooting(int index) {
    if (guardShootDelay[index] > 0) {
        guardShootDelay[index]--;
    } else {
        if (pY >= gY[index] - 1 && pY <= gY[index] + 1) {
            if (guardDirection[index] == 'L' && pX < gX[index]) {
                generateGuardBullet(index);
            } else if (guardDirection[index] == 'R' && pX > gX[index]) {
                generateGuardBullet(index);
            }
        }
        guardShootDelay[index] = 30;
    }
}
void bulletCollisionHitman(int guardIndex) {
    for (int i = 0; i < bulletCount; i++) {
        if (isBulletActive[i]) {
            if (bulletX[i] + 1 == gX[guardIndex] && (bulletY[i] >= gY[guardIndex] - 1 && bulletY[i] <= gY[guardIndex] + 3)) {
                gameScore += 10;
                guardHealth[guardIndex] -= 10;
                isBulletActive[i] = false;
            }
        }
    }
}
// Update all guards
void updateGuards() {
    for (int i = 0; i < guardCount; i++) {
        moveGuard(i);
        handleGuardShooting(i);
    }
}

void score(){
    gotoxy(200,9);
    cout<<"Remaining aimo: "<<100-bulletCount<<endl;
    gotoxy(200,10);
    cout<<"Game score: " << gameScore << endl;
    gotoxy(200,20);
    cout<<"Player Health: " << playerHealth<<endl;
    for(int i=0;i<guardCount;i++){
        gotoxy(200,21+i);
        cout<<"guard"<<i+1<<"health: "<<guardHealth[i];
    }
    
}

int main() {
    system("cls");
    printMaze1();
    playerDirection = 'S';

    while (true) {
        // Erase and move guards
        for (int i = 0; i < guardCount; i++) {
            if (guardHealth[i] > 0) {
                eraseGuard(i);
                moveGuard(i);
                printGuard(i);
                handleGuardShooting(i);
            }
        }

        // Update player actions
        score();
        printHitman(pX, pY, playerDirection);
        if (GetAsyncKeyState(VK_LEFT)) {
            playerDirection = 'L';
            movePlayer();
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            playerDirection = 'R';
            movePlayer();
        }
        if (GetAsyncKeyState(VK_UP)) {
            playerDirection = 'U';
            movePlayer();
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            playerDirection = 'D';
            movePlayer();
        }
        if (GetAsyncKeyState(VK_TAB)) {
            meleeAttack();
        }
        if (GetAsyncKeyState(VK_SPACE)) {
            shootBullet();
        }

        // Update bullets
        moveBullets();
        // moveGuardBullets();

        // Check collisions
        for (int i = 0; i < guardCount; i++) {
            if (guardHealth[i] > 0) {
                bulletCollisionHitman(guardHealth[i]);
            }
        }

        // Delay for smooth gameplay
        Sleep(10);
    }

    return 0;
}