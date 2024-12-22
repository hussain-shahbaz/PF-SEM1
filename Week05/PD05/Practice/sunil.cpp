void printScoreMenu() {
    
    // Set cursor position using gotoxy(x, y) - x is horizontal, y is vertical
    gotoxy(200, 2);  // Move cursor to position (200, 2) for header
    cout << "\033[1;33m------------------------------\n";
    gotoxy(200, 3);
    cout << "|   *** GAME SCOREBOARD ***   |";
    gotoxy(200, 4);
    cout << "------------------------------\n";
    cout << "\033[0m";  // Reset color

    // Print Game Score
    gotoxy(200, 6);
    cout << "\033[1;32mGame Score: " << gameScore << "\033[0m";
    
    // Print Player Health
    gotoxy(200, 7);
    cout << "\033[1;31mPlayer Health: " << playerHealth << "\033[0m";
    
    // Print Guard Healths
    gotoxy(200, 8);
    cout << "\033[1;34mGuard 1 Health: " << guardHealth << "\033[0m";
    gotoxy(200, 9);
    cout << "Guard 2 Health: " << guard2Health;
    gotoxy(200, 10);
    cout << "Guard 3 Health: " << g3Health;
    gotoxy(200, 11);
    cout << "Guard 4 Health: " << guard4Health;
    gotoxy(200, 12);
    cout << "Guard 5 Health: " << guard5Health;

    // Print Remaining Ammunition
    gotoxy(200, 13);
    cout << "\033[1;36mRemaining Ammo: " << remainingAmmo << "\033[0m";
    
    // Closing line
    gotoxy(200, 15);
    cout << "\033[1;33m------------------------------\n";

    gotoxy(200, 17);
}