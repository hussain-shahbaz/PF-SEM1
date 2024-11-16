#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;
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
void printInterface(){
    cout << "___   ___ ____    ____  ________     .______        ___      .__   __.  __  ___ " << endl;
    cout << "\\  \\ /  / \\   \\  /   / |       /     |   _  \\      /   \\     |  \\ |  | |  |/  / " << endl;
    cout << " \\  V  /   \\   \\/   /  `---/  /      |  |_)  |    /  ^  \\    |   \\|  | |  '  /  " << endl;
    cout << "  >   <     \\_    _/      /  /       |   _  <    /  /_\\  \\   |  . `  | |    <   " << endl;
    cout << " /  .  \\      |  |       /  /----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\  " << endl;
    cout << "/__/ \\__\\     |__|      /________|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\ " << endl;

    cout<<"Welcome to the applicatoin of XYZ bank :"<<endl;
    cout<<endl<<endl;
    cout<<endl;    
    cout<<"                                  1. Log IN                         "<<endl;
    cout<<"                                  2. Sign UP to XYZ bank            "<<endl;;
    cout<<endl<<endl<<"Press 1 to login\nPress 2 to sign UP";                
    cin>>option;                                                                     

}
void printHeader(){
    cout << "___   ___ ____    ____  ________     .______        ___      .__   __.  __  ___ " << endl;
    cout << "\\  \\ /  / \\   \\  /   / |       /     |   _  \\      /   \\     |  \\ |  | |  |/  / " << endl;
    cout << " \\  V  /   \\   \\/   /  `---/  /      |  |_)  |    /  ^  \\    |   \\|  | |  '  /  " << endl;
    cout << "  >   <     \\_    _/      /  /       |   _  <    /  /_\\  \\   |  . `  | |    <   " << endl;
    cout << " /  .  \\      |  |       /  /----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\  " << endl;
    cout << "/__/ \\__\\     |__|      /________|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\ " << endl;

    cout<<"Please Login to your account"<<endl;
    cout<<"Email : ";
    cin>>userEmail;
    cout<<"PIN : ";
    cin>>userPIN;
    cout<<"Forgot Password?";
    
}
void body(){
    cout<<"Welcome USER to the Banking application of XYZ Bank"<<endl;
    cout<<"Press 1 to make a transaction"<<endl;
    cout<<"Press 2 to add Money"<<endl;
    cout<<"Press 3 to Check Balance"<<endl;
    cout<<"Press 4 to donate funds"<<endl;
    cout<<"Press 5 to obtain Banking History"<<endl;
    cout<<"Press 6 to pay bills/fees"<<endl;
    cout<<"Press 7 to calculate the loan balance "<<endl;
    cout<<"Press 8 to Exit the Application"<<endl;
}
void transaction(){
    cout<<"How many dollars you want to withdraw? $";
    cin>>cash;
    if(cash>balance){
        cout<<"Sorry! You cannot withdraw since you have less amount"<<endl;
    }
    else{
        cout<<"Withdrawal successful"<<endl;
        balance -= cash;
        cout<<"Your balance is $"<<balance<<endl;
    }
}
void addMoney(){
    cout<<"How many dollars you want to add? ";
    cin>>cash;
    balance+=cash;
    cout<<"Money added successfully"<<endl;
    cout<<"Your balance is $"<< balance<<endl;
    
}
void Footer(){
    cout<<"Thank you for using XYZ Bank"<<endl;
    cout<<"Copyright@2024\nAll Rights Reserved"<<endl;
}
void checkBalance(){
    cout<<"Your balance is $"<<balance;
}
void donations(){
    cout<<"Which organization you want to donate? "<<endl;
    cout<<"Press 1 for Palestine "<<endl;
    cout<<"Press 2 for Al-Khidmat Foundation "<<endl;
    cin>>opt;
    cout<<"How many Dollars you want to donate?"<<endl;
    cin>>cash;
    balance = balance - cash;
    cout<<"Donation successful"<<endl;
    cout<<"Your balance is $"<<balance<<endl;
    

}
void History(){
    cout << "Transaction History:" << endl;
        cout << "Deposit of $1000 on 2022-01-01" << endl;
        cout << "Withdrawal of $500 on 2022-01-05" << endl;
        cout << "Donation of $200 on 2022-01-10" << endl;
        cout << "Deposit of $2000 on 2022-01-15" << endl;
        cout << "Withdrawal of $800 on 2022-01-20" << endl;
}
void payBills(){
    cout<<"Which bill you want to pay? "<<endl;
    cout<<"Press 1 for Electricity "<<endl;
    cout<<"Press 2 for Gas "<<endl;
    cout<<"Press 3 for Water "<<endl;
    cout<<"Press 4 for University fees "<<endl;
    cout<<"Press 5 for taxes(if payable) "<<endl;
    cin>>opt;
    if(opt ==1) {
        cout<<"The Electricity Bill is $30, do you proceed to Pay?(Y/n)"<<endl;
        cin>>ch;
        if(ch == 'Y'){
            balance = balance - 30;
            cout<<"successful";
            cout<<"Your balance is $"<<balance<<endl;
        }
        else{
            cout<<"Transaction cancelled"<<endl;
        }
    }
    else if(opt == 2){
        cout<<"The Gas Bill is $50, do you proceed to Pay?(Y/n)"<<endl;
        cin>>ch;
        if(ch == 'Y'){
            balance = balance - 50;
            cout<<"successful";
            cout<<"Your balance is $"<<balance<<endl;
        }
        else{
            cout<<"Transaction cancelled"<<endl;
        }
    }
    else if(opt == 3){
        cout<<"The Water Bill is $20, do you proceed to Pay?(Y/n)"<<endl;
        cin>>ch;
        if(ch == 'Y'){
            balance = balance - 20;
            cout<<"successful";
            cout<<"Your balance is $"<<balance<<endl;
        }
        else{
            cout<<"Transaction cancelled"<<endl;
        }
    }
    else if(opt == 4){
        cout<<"The semester fee is $100, do you proceed to Pay?(Y/n)"<<endl;
        cin>>ch;
        if(ch == 'Y'){
            balance = balance - 100;
            cout<<"Fee successful";
            cout<<"Your balance is $"<<balance<<endl;
        }
        else{
            cout<<"Transaction cancelled"<<endl;
        }

    }

}
void payTax(){
    cout<<"The tax is $50, do you proceed to Pay?(Y/n)"<<endl;
    cin>>ch;
    if(ch == 'Y'){
        balance = balance - 50;
        cout<<"Tax successful";
        cout<<"Your balance is $"<<balance<<endl;
    }
    else{
        cout<<"Transaction cancelled"<<endl;
    }
}
void calculateLoanBalance(){
    cout<<"Enter the loan amount: $";
    cin>>loanAmount;
    cout<<"Enter the annual interest rate: %";
    cin>>interestRate;
    cout<<"Enter the number of years: ";
    cin>>years;
    cout<<"Enter  the payment Amount(monthly): $";
    cin>>payment;
    interestRate = (interestRate/100)/12;
    years = years * 12;
    float balanceAmount = loanAmount*pow((1+interestRate),years) - (payment/interestRate)*((pow((1+interestRate),years))-1);
    cout<<"The balance Loan will be : $"<<balanceAmount<<endl;

}
void logInSuccessful(){
    if(userEmail == email && userPIN == PIN){
        while(true){
            // system("cls");
            // printHeader();
            cout<<endl<<endl<<endl;
            body();
            int choice;
            cin>>choice;
            if(choice == 1){
                transaction();
            }
            else if(choice == 2){
                addMoney();
            }
            else if(choice == 3){
                checkBalance();
            }
            else if(choice == 4){
                donations();
            }
            else if(choice == 5){
                History();
            }
            else if(choice == 6){
                payBills();
            }
            else if(choice == 6){
                payTax();
            }
            else if(choice == 7){
                calculateLoanBalance();
            }
            else if(choice == 8){
                Footer();
                break;
            }
            else{
                cout<<"Invalid choice"<<endl;
                printHeader();
            }
        }
        
        
    }
    else{
            cout<<"Invalid Email or PIN"<<endl;
            Footer();

        }
}
main(){
    printInterface();
    if(option==1){
        system("cls");

    }
}