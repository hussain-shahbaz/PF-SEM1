#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

const int MAX_GUARDS = 4;
const int MAX_BULLETS = 100;

// Guard variables
int guardX[MAX_GUARDS] = {20, 40, 60, 80};
int guardY[MAX_GUARDS] = {10, 12, 14, 16};
char guardDirection[MAX_GUARDS] = {'R', 'L', 'R', 'L'};
int guardHealth[MAX_GUARDS] = {100, 100, 100, 100};

// Player variables
int pX = 50, pY = 15;
int playerHealth = 100;
char playerDirection;

// Bullet variables
int bulletX[MAX_BULLETS];
int bulletY[MAX_BULLETS];
bool isBulletActive[MAX_BULLETS];
char bulletDirection[MAX_BULLETS];
int bulletCount = 0;

// Game variables
int gameScore = 0;

// Function prototypes
void gotoxy(int x, int y);
void printMaze1();
void printHitman(int x, int y, char direction);
void movePlayer();
void meleeAttack();
void meleeDamage();
void shootBullet();
void moveBullets();
void bulletCollisionHitman(int guardIndex);
void bulletCollisionGuard();
void score();

void eraseGuard(int gX, int gY);
void printGuard(int &gX, int &gY, char &direction);
void moveGuard(int &gX, int &gY, char &direction);
void handleGuardShooting(int guardIndex);
// void moveGuardBullets();

int main() {
    system("cls");
    printMaze1();
    playerDirection = 'S';

    while (true) {
        // Erase and move guards
        for (int i = 0; i < MAX_GUARDS; i++) {
            if (guardHealth[i] > 0) {
                eraseGuard(guardX[i], guardY[i]);
                moveGuard(guardX[i], guardY[i], guardDirection[i]);
                printGuard(guardX[i], guardY[i], guardDirection[i]);
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
        // if (GetAsyncKeyState(VK_TAB)) {
        //     meleeAttack();
            // meleeDamage();
        // }
        if (GetAsyncKeyState(VK_SPACE)) {
            shootBullet();
        }

        // Update bullets
        moveBullets();
        moveGuardBullets();

        // Check collisions
        for (int i = 0; i < MAX_GUARDS; i++) {
            if (guardHealth[i] > 0) {
                bulletCollisionHitman(i);
            }
        }
        bulletCollisionGuard();

        // Delay for smooth gameplay
        Sleep(20);
    }

    return 0;
}

// gotoxy implementation
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMaze1() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 100; j++) {
            if (i == 0 || i == 24 || j == 0 || j == 99) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void printHitman(int x, int y, char direction) {
    gotoxy(x, y);
    if (direction == 'L') {
        cout << "<";
    } else if (direction == 'R') {
        cout << ">";
    } else if (direction == 'U') {
        cout << "^";
    } else if (direction == 'D') {
        cout << "v";
    }
}

void movePlayer() {
    gotoxy(pX, pY);
    cout << " ";

    if (playerDirection == 'L' && pX > 1) pX--;
    if (playerDirection == 'R' && pX < 98) pX++;
    if (playerDirection == 'U' && pY > 1) pY--;
    if (playerDirection == 'D' && pY < 23) pY++;

    gotoxy(pX, pY);
    printHitman(pX, pY, playerDirection);
}

void shootBullet() {
    if (bulletCount < MAX_BULLETS) {
        bulletX[bulletCount] = pX;
        bulletY[bulletCount] = pY;
        bulletDirection[bulletCount] = playerDirection;
        isBulletActive[bulletCount] = true;
        bulletCount++;
    }
}

void moveBullets() {
    for (int i = 0; i < bulletCount; i++) {
        if (isBulletActive[i]) {
            gotoxy(bulletX[i], bulletY[i]);
            cout << " ";

            if (bulletDirection[i] == 'L') bulletX[i]--;
            if (bulletDirection[i] == 'R') bulletX[i]++;
            if (bulletDirection[i] == 'U') bulletY[i]--;
            if (bulletDirection[i] == 'D') bulletY[i]++;

            if (bulletX[i] < 1 || bulletX[i] > 98 || bulletY[i] < 1 || bulletY[i] > 23) {
                isBulletActive[i] = false;
            } else {
                gotoxy(bulletX[i], bulletY[i]);
                cout << "*";
            }
        }
    }
}

void bulletCollisionHitman(int guardIndex) {
    for (int i = 0; i < bulletCount; i++) {
        if (isBulletActive[i]) {
            if (bulletX[i] == guardX[guardIndex] && bulletY[i] == guardY[guardIndex]) {
                gameScore += 10;
                guardHealth[guardIndex] -= 10;
                isBulletActive[i] = false;
            }
        }
    }
}

void bulletCollisionGuard() {
    for (int i = 0; i < MAX_GUARDS; i++) {
        for (int j = 0; j < bulletCount; j++) {
            if (isBulletActive[j] && bulletX[j] == guardX[i] && bulletY[j] == guardY[i]) {
                guardHealth[i] -= 10;
                isBulletActive[j] = false;
            }
        }
    }
}

void score() {
    gotoxy(0, 25);
    cout << "Score: " << gameScore << " Player Health: " << playerHealth;
}

void eraseGuard(int gX, int gY) {
    gotoxy(gX, gY);
    cout << " ";
}

void printGuard(int &gX, int &gY, char &direction) {
    gotoxy(gX, gY);
    if (direction == 'L') {
        cout << "G";
    } else if (direction == 'R') {
        cout << "G";
    }
}

void moveGuard(int &gX, int &gY, char &direction) {
    eraseGuard(gX, gY);
    if (direction == 'L') {
        if (gX > 1) {
            gX--;
        } else {
            direction = 'R';
        }
    } else if (direction == 'R') {
        if (gX < 98) {
            gX++;
        } else {
            direction = 'L';
        }
    }
}



