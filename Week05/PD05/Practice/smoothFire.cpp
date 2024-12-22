#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>

using namespace std;

// Game dimensions
const int width = 50;
const int height = 20;

// Player properties
int playerX = width / 2, playerY = height - 2;
int playerLives = 3;
int playerHealth = 100;
int playerScore = 0;

// Enemy properties
struct Enemy {
    int x, y;
    int type; // 1: horizontal, 2: vertical, 3: random
    int health;
    bool isActive;
};

const int maxEnemies = 5;
Enemy enemies[maxEnemies];

// Game level
int currentLevel = 1;
const int maxLevels = 3;

// Walls and boundaries
vector<pair<int, int>> walls;

// Bullet properties
struct Bullet {
    int x, y;
    bool isActive;
};

const int maxBullets = 10;
Bullet playerBullets[maxBullets];
Bullet enemyBullets[maxBullets];

// Function prototypes
void initializeGame();
void initializeWalls();
void initializeEnemies();
void render();
void update();
void handleInput();
void moveEnemies();
void shootPlayerBullet();
void shootEnemyBullet();
void checkCollisions();
void nextLevel();
void gameOver();

// Utility functions
void sleep(int milliseconds) {
    Sleep(milliseconds);
}

void clearConsole() {
    system("cls");
}

bool isWall(int x, int y) {
    for (auto& wall : walls) {
        if (wall.first == x && wall.second == y) return true;
    }
    return false;
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));
    initializeGame();

    while (true) {
        render();
        handleInput();
        update();
        sleep(100);

        if (playerLives <= 0) {
            gameOver();
            break;
        }
    }
    return 0;
}

// Initialize the game
void initializeGame() {
    initializeWalls();
    initializeEnemies();

    for (int i = 0; i < maxBullets; i++) {
        playerBullets[i].isActive = false;
        enemyBullets[i].isActive = false;
    }
}

// Create walls for each level
void initializeWalls() {
    walls.clear();
    for (int i = 0; i < width; i++) {
        walls.push_back({i, 0});
        walls.push_back({i, height - 1});
    }
    for (int i = 0; i < height; i++) {
        walls.push_back({0, i});
        walls.push_back({width - 1, i});
    }
    if (currentLevel == 2) {
        for (int i = 5; i < 15; i++) walls.push_back({25, i});
    } else if (currentLevel == 3) {
        for (int j = 10; j < 40; j++) walls.push_back({j, 10});
    }
}

// Initialize enemies
void initializeEnemies() {
    for (int i = 0; i < maxEnemies; i++) {
        enemies[i].x = rand() % (width - 2) + 1;
        enemies[i].y = rand() % (height / 2);
        enemies[i].type = rand() % 3 + 1;
        enemies[i].health = 50;
        enemies[i].isActive = true;
    }
}

// Render the game
void render() {
    clearConsole();

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bool printed = false;

            if (x == playerX && y == playerY) {
                cout << 'P';
                printed = true;
            } else {
                for (int k = 0; k < maxEnemies; k++) {
                    if (enemies[k].isActive && enemies[k].x == x && enemies[k].y == y) {
                        cout << 'E';
                        printed = true;
                        break;
                    }
                }
                for (int k = 0; k < maxBullets; k++) {
                    if (playerBullets[k].isActive && playerBullets[k].x == x && playerBullets[k].y == y) {
                        cout << '^';
                        printed = true;
                        break;
                    } else if (enemyBullets[k].isActive && enemyBullets[k].x == x && enemyBullets[k].y == y) {
                        cout << 'v';
                        printed = true;
                        break;
                    }
                }
            }

            if (!printed) {
                if (isWall(x, y)) {
                    cout << '#';
                } else {
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }

    // Display stats
    cout << "Lives: " << playerLives << " | Health: " << playerHealth << " | Score: " << playerScore << endl;
}

// Handle input
void handleInput() {
    if (_kbhit()) {
        char input = _getch();
        if (input == 'a' && !isWall(playerX - 1, playerY)) playerX--;
        if (input == 'd' && !isWall(playerX + 1, playerY)) playerX++;
        if (input == 'w' && !isWall(playerX, playerY - 1)) playerY--;
        if (input == 's' && !isWall(playerX, playerY + 1)) playerY++;
        if (input == ' ') shootPlayerBullet();
    }
}

// Update game logic
void update() {
    moveEnemies();
    shootEnemyBullet();
    for (int i = 0; i < maxBullets; i++) {
        if (playerBullets[i].isActive) playerBullets[i].y--;
        if (enemyBullets[i].isActive) enemyBullets[i].y++;
    }
    checkCollisions();
}

// Move enemies
void moveEnemies() {
    for (int i = 0; i < maxEnemies; i++) {
        if (enemies[i].isActive) {
            if (enemies[i].type == 1) {
                enemies[i].x += (rand() % 2 ? 1 : -1);
                if (isWall(enemies[i].x, enemies[i].y)) enemies[i].x -= 1;
            } else if (enemies[i].type == 2) {
                enemies[i].y += (rand() % 2 ? 1 : -1);
                if (isWall(enemies[i].x, enemies[i].y)) enemies[i].y -= 1;
            } else if (enemies[i].type == 3) {
                enemies[i].x += (rand() % 2 ? 1 : -1);
                enemies[i].y += (rand() % 2 ? 1 : -1);
            }
        }
    }
}

// Shoot player bullet
void shootPlayerBullet() {
    for (int i = 0; i < maxBullets; i++) {
        if (!playerBullets[i].isActive) {
            playerBullets[i].x = playerX;
            playerBullets[i].y = playerY - 1;
            playerBullets[i].isActive = true;
            break;
        }
    }
}

// Shoot enemy bullet
void shootEnemyBullet() {
    for (int i = 0; i < maxEnemies; i++) {
        if (enemies[i].isActive && rand() % 10 < 2) {
            for (int j = 0; j < maxBullets; j++) {
                if (!enemyBullets[j].isActive) {
                    enemyBullets[j].x = enemies[i].x;
                    enemyBullets[j].y = enemies[i].y + 1;
                    enemyBullets[j].isActive = true;
                    break;
                }
            }
        }
    }
}

// Check collisions
void checkCollisions() {
    for (int i = 0; i < maxBullets; i++) {
        if (playerBullets[i].isActive) {
            for (int j = 0; j < maxEnemies; j++) {
                if (enemies[j].isActive && playerBullets[i].x == enemies[j].x && playerBullets[i].y == enemies[j].y) {
                    playerBullets[i].isActive = false;
                    enemies[j].health -= 25;
                    if (enemies[j].health <= 0) {
                        enemies[j].isActive = false;
                        playerScore += 50;
                    }
                }
            }
        }
        if (enemyBullets[i].isActive && enemyBullets[i].x == playerX && enemyBullets[i].y == playerY) {
            enemyBullets[i].isActive = false;
            playerHealth -= 25;
            if (playerHealth <= 0) {
                playerLives--;
                playerHealth = 100;
            }
        }
    }
}

// Advance to the next level
void nextLevel() {
    currentLevel++;
    if (currentLevel > maxLevels) {
        cout << "You won the game! Final Score: " << playerScore << endl;
        exit(0);
    }
    initializeWalls();
    initializeEnemies();
}

// Game over
void gameOver() {
    cout << "Game Over! Final Score: " << playerScore << endl;
}
