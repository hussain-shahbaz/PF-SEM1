#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;

int money;
int balance = 50000;
string email = "example@UET.com";
int PIN = 1234;
string userEmail;
int userPIN;
int cash;
int opt;
char ch;
float loanAmount, payment, interestRate, years;
int option;
string name, email2 = "";
int CNIC, accNumber, PIN2;
string adminEmail = "admin";
int adminPass = 1234;
int balance2 = 0;
int loanMoney;
string loanName;
bool loanApplication = 0;
int loanApproval = -1;
float interest;

void printInterface() {
    cout << "___   ___ ____    ____  ________     .______        ___      .__   __.  __  ___ " << endl;
    cout << "\\  \\ /  / \\   \\  /   / |       /     |   _  \\      /   \\     |  \\ |  | |  |/  / " << endl;
    cout << " \\  V  /   \\   \\/   /  `---/  /      |  |_)  |    /  ^  \\    |   \\|  | |  '  /  " << endl;
    cout << "  >   <     \\_    _/      /  /       |   _  <    /  /_\\  \\   |  . `  | |    <   " << endl;
    cout << " /  .  \\      |  |       /  /----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\  " << endl;
    cout << "/__/ \\__\\     |__|      /________|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\ " << endl;

    cout << "Welcome to the application of XYZ bank :" << endl;
    cout << endl << endl;
    cout << "Press 1 to login" << endl;
    cout << "Press 2 to login as an administrator" << endl;
    cout << "Press 3 to signUP" << endl;
    cout << "Press 0 to close the application" << endl;
    cin >> option;
}

void printHeader() {
    cout << "___   ___ ____    ____  ________     .______        ___      .__   __.  __  ___ " << endl;
    cout << "\\  \\ /  / \\   \\  /   / |       /     |   _  \\      /   \\     |  \\ |  | |  |/  / " << endl;
    cout << " \\  V  /   \\   \\/   /  `---/  /      |  |_)  |    /  ^  \\    |   \\|  | |  '  /  " << endl;
    cout << "  >   <     \\_    _/      /  /       |   _  <    /  /_\\  \\   |  . `  | |    <   " << endl;
    cout << " /  .  \\      |  |       /  /----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\  " << endl;
    cout << "/__/ \\__\\     |__|      /________|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\ " << endl;

    cout << "Please Login to your account" << endl;
    cout << "Email : ";
    cin >> userEmail;
    cout << "PIN : ";
    cin >> userPIN;
}

void body() {
    cout << "Welcome USER to the Banking application of XYZ Bank" << endl;
    cout << "Press 1 to make a transaction" << endl;
    cout << "Press 2 to add Money" << endl;
    cout << "Press 3 to Check Balance" << endl;
    cout << "Press 4 to donate funds" << endl;
    cout << "Press 5 to obtain Banking History" << endl;
    cout << "Press 6 to pay bills/fees" << endl;
    cout << "Press 7 to calculate the loan balance " << endl;
    cout << "Press 8 to apply for Loan" << endl;
    cout << "Press 9 to LogOut" << endl;
    cout << "Press 0 to Exit the Application" << endl;
}

void ApplyforLoan() {
    cout << "Enter your name: ";
    cin >> loanName;
    cout << "Enter Loan Amount: ";
    cin >> loanMoney;
    cout << "Thank you, you have applied for loan successfully" << endl;
    loanApplication = 1;
}

void checkLoanStatus() {
    if (!loanApplication) {
        cout << "You haven't applied for a loan";
    }
    else {
        if (loanApproval == 1) {
            cout << "Your loan Application has been approved with interest rate: " << interest << endl;
        }
        else {
            cout << "Your loan Application has been rejected." << endl;
        }
    }
}

void transaction() {
    cout << "How many dollars you want to withdraw? $";
    cin >> cash;
    if (cash > balance) {
        cout << "Sorry! You cannot withdraw since you have less amount" << endl;
    }
    else {
        cout << "Withdrawal successful" << endl;
        balance -= cash;
        cout << "Your balance is $" << balance << endl;
    }
}

void addMoney() {
    cout << "How many dollars you want to add? ";
    cin >> cash;
    balance += cash;
    cout << "Money added successfully" << endl;
    cout << "Your balance is $" << balance << endl;
}

void Footer() {
    cout << "Thank you for using XYZ Bank" << endl;
    cout << "Copyright@2024\nAll Rights Reserved" << endl;
}

void checkBalance() {
    cout << "Your balance is $" << balance;
}

void logInSuccessful() {
    while (true) {
        body();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: transaction(); break;
            case 2: addMoney(); break;
            case 3: checkBalance(); break;
            case 4: cout << "Donations feature"; break;  // Placeholder for actual donation logic
            case 5: cout << "History feature"; break;    // Placeholder for actual history logic
            case 6: cout << "Bill payment feature"; break;  // Placeholder for actual payment logic
            case 7: cout << "Loan calculation feature"; break; // Placeholder
            case 8: ApplyforLoan(); break;
            case 9: return;  // LogOut
            case 0: Footer(); exit(0);
            default: cout << "Invalid choice, try again." << endl;
        }
    }
}

int main() {
    printInterface();
    if (option == 1) {
        system("cls");
        printHeader();
        if ((userEmail == email && userPIN == PIN) || (userEmail == email2 && userPIN == PIN2)) {
            logInSuccessful();
        }
        else {
            cout << "Invalid username or password" << endl;
            printInterface();
        }
    }
    else if (option == 2) {
        cout << "Admin login feature";
        // Admin login logic placeholder
    }
    else if (option == 3) {
        cout << "Signup feature";
        // Sign up logic placeholder
    }
    else {
        Footer();
    }

    return 0;  // Main should return an int
}
