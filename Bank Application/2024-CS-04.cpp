#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<conio.h>
#include<string>
#include <time.h>
using namespace std;
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/*Data*/
const int userNumbers = 10;
int userCount =2;
string nameData[userNumbers] =          {"Hussain","Ayyan"};            
string emailData[userNumbers] =         {"first@UET.com","second@UET.com"};
string passwordData[userNumbers] =      {"1234","4568"};
string DOBData[userNumbers] =           {"23-06-2005","25-10-2007"};
string CNICData[userNumbers]  =         {"33201-9664417-5","55555-7777777-1"};

int accNumberData[userNumbers] =        {1111,1112};

int balanceData[userNumbers] =          {500,230000};
float debtData[userNumbers] =           {0,0};
int debt[userNumbers]                   {0,0};

float loanAmountData[userNumbers] =     {0.0,0.0};
float interest[userNumbers] =           {0,0};
float yearsData[userNumbers];


bool loanApplicationData[userNumbers] =    {0};
int loanApprovalData[userNumbers] =        {0};

int userNo;
const int transactionLimit = 50;

string transactionHistory[userNumbers][transactionLimit];
int transactionCount[userNumbers] = {0};

int accNo;
string password;
string email;
string userEmail;
int userPIN;
int cash;
int opt;
string option;
string adminEmail = "admin";
int adminPass = 1234;
float 
Money;


// INTERFACE
void printInterface(){
    system("cls");
    cout<<endl;
    cout << "___   ___ ____    ____  ________     .______        ___      .__   __.  __  ___ " << endl;
    cout << "\\  \\ /  / \\   \\  /   / |       /     |   _  \\      /   \\     |  \\ |  | |  |/  / " << endl;
    cout << " \\  V  /   \\   \\/   /  `---/  /      |  |_)  |    /  ^  \\    |   \\|  | |  '  /  " << endl;
    cout << "  >   <     \\_    _/      /  /       |   _  <    /  /_\\  \\   |  . `  | |    <   " << endl;
    cout << " /  .  \\      |  |       /  /----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\  " << endl;
    cout << "/__/ \\__\\     |__|      /________|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\ " << endl;

    cout<<"Welcome to the applicatoin of XYZ bank :"<<endl;
    cout<<endl<<endl;
    cout<<"Press 1 to login"<<endl;
    cout<<"Press 2 to login as an administrator"<<endl;
    cout<<"Press 3 to signUP"<<endl;
    cout<<"Press 0 to close the application"<<endl;
    cin>>option;                                                                     
}

void Footer(){
    cout<<"Thank you for using XYZ Bank"<<endl;
    cout<<"Copyright@2024\nAll Rights Reserved"<<endl;
}

void pressAnyKey(){
    cout<<endl<<"Press any key to continue..."<<endl;
    getch();
    system("cls");
}
// VALIDATORS

int getAccNo(int accNo){ 
    for(int i=0;i<userCount;i++){
        if(accNo == accNumberData[i]) return i;
    }
    return -1;
}

bool signIN(string username, string password){
    for(int i=0;i<userCount;i++){
        if(userEmail == emailData[i] && password == passwordData[i]){
            userNo = i;
            return true;
        }
    }
    return false;
}

bool checkUserCapacity(){
    if(userCount<userNumbers){ 
        userNo = userCount;
        return true;
    }
    return false;
}

int getUserEmail(string email){
    for(int i=0;i<userCount;i++){
        if(email == emailData[i]) return i;
    }
    return -1;
}

void DeleteUserData(int userNo){
    for (int i = userNo; i < userCount - 1; i++) {
        accNumberData[i] = accNumberData[i + 1];
        nameData[i] = nameData[i + 1];
        CNICData[i] = CNICData[i + 1];
        DOBData[i] = DOBData[i + 1];
        balanceData[i] = balanceData[i + 1];
        emailData[i] = emailData[i + 1];
        passwordData[i] = passwordData[i + 1];
        debtData[i] = debtData[i + 1];
    }
    userCount--;
}

bool CNICval(string cnic){
    if(cnic.size() != 15) return false;
    for(int i=0;i<15;i++){
        if(i==5 || i==13){
            if(cnic[i] != '-') return false;
        }
        else{
            if(!isdigit(cnic[i])) return false;
        }
    }
    return true;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
bool isValidDOB(int day, int month, int year) {
    if (month<1 || month>12) {
        return false;
    }
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    if (day<1 || day>daysInMonth[month - 1]) {
        return false; 
    }
    if(year >2024) return false;
    return true;
}
bool isValidDOBFormat(string dob) {
    if (dob.length() != 10) {
        return false;
    }
    if (!isdigit(dob[0]) || !isdigit(dob[1]) || dob[2] != '-' ||
        !isdigit(dob[3]) || !isdigit(dob[4]) || dob[5] != '-' ||
        !isdigit(dob[6]) || !isdigit(dob[7]) || !isdigit(dob[8]) || !isdigit(dob[9])) {
        return false; 
    }

    int day = (dob[0]-'0') * 10 + (dob[1]-'0');
    int month = (dob[3]-'0') * 10 + (dob[4]-'0');
    int year = (dob[6]-'0') * 1000 + (dob[7]-'0') * 100 + (dob[8]-'0') * 10 + (dob[9]-'0');
    return isValidDOB(day, month, year);
}

bool checkCom(string email){
    string sub = "";
    string com = "moc.";
    for(int i=email.size()-1;i>email.size()-5;i--){
        sub+= email[i];
    }
    if(sub == com) return true;
    return false;
}
bool checkAt(string email){
    for(int i=0;email[i] != '.';i++){
        if(email[i] == '@') return true;
    }
    return false;
}
bool checkSpace(string email){
    for(int i=0;i<email[i] != '\0';i++){
        if(email[i] = ' ') return false;
    }
}
bool emailVal(string email){
    return checkAt(email) && checkCom(email) && !checkSpace(email);
}
int getCNIC(string cnic){
    for(int i=0;i<userCount;i++){
        if(cnic == CNICData[i]) return i;
    }
    return -1;
}

// USER SIGN IN

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
    cin>>password; 
}

void body(){
    cout<<endl<<endl;

    cout<<"Welcome "<<nameData[userNo]<<" to the Banking application of XYZ Bank"<<endl;
    cout<<endl<<"Account Number: "<<accNumberData[userNo]<<endl;
    cout<<"Press 1 to make a transaction"<<endl;
    cout<<"Press 2 to add Money"<<endl;
    cout<<"Press 3 to Check Balance"<<endl;
    cout<<"Press 4 to donate funds"<<endl;
    cout<<"Press 5 to obtain Banking History"<<endl;
    cout<<"Press 6 to pay bills/fees"<<endl;
    cout<<"Press 7 to calculate the loan balance "<<endl;
    cout<<"Press 8 to apply for Loan"<<endl;
    cout<<"Press 9 to check loan status"<<endl;
    cout<<"Press 10 to check loan Debt"<<endl;
    cout<<"Press 11 transfer Money"<<endl;
    cout<<"Press 12 to pay Debt"<<endl;
    cout<<"Press -1 to LogOut"<<endl;
    cout<<"Press 0 to Exit the Application"<<endl;
}

void ApplyforLoan(){
    system("cls");
    cout<<"Enter Loan Amount: ";
    cin>>loanAmountData[userNo];
    cout<<"Enter number of Years: ";
    cin>>yearsData[userNo];
    cout<<"Thankyou, you have applied for loan successfully"<<endl;;
    loanApplicationData[userNo] = 1;
    pressAnyKey();
}
void checkLoanStatus(){
    if(loanApprovalData[userNo]==1){
        cout<<"Your loan of $ "<<loanAmountData[userNo]<<" has been approved with interest rate: "<<interest[userNo]<<endl;
        loanApprovalData[userNo] = -1;
    }
    else if(loanApprovalData[userNo]==0){
        cout<<"Your loan application has been rejected"<<endl;
        loanApprovalData[userNo] = -1;
    }
    else{
        cout<<"You havenet applied for a loan"<<endl;
    }
    pressAnyKey();
}

void transaction(){
    cout<<"How many dollars you want to withdraw? $";
    cin>>cash;
    if(cash>balanceData[userNo]){
        cout<<"Sorry! You cannot withdraw since you have less amount"<<endl;
    }
    else{
        cout<<"Withdrawal successful"<<endl;
        balanceData[userNo] -= cash;
        cout<<"Your balance is $"<<balanceData[userNo]<<endl;
    }
    transactionHistory[userNo][transactionCount[userNo]] = to_string(cash) + " USD withdrawed on date: " + currentDateTime();
    transactionCount[userNo]++;
    pressAnyKey();
}

void addMoney(){
    cout<<"How many dollars you want to add? ";
    cin>>cash;
    balanceData[userNo]+=cash;
    cout<<"Money added successfully"<<endl;
    cout<<"Your balance is $"<< balanceData[userNo]<<endl;
    transactionHistory[userNo][transactionCount[userNo]] = to_string(cash) + " USD Added on date: " + currentDateTime();
    transactionCount[userNo]++;
    pressAnyKey();
}

void checkBalance(){
    cout<<"Your balance is $"<<balanceData[userNo];
    pressAnyKey();
}

void donations(){
    cout<<"Which organization you want to donate? "<<endl;
    cout<<"Press 1 for Palestine "<<endl;
    cout<<"Press 2 for Al-Khidmat Foundation "<<endl;
    cin>>opt;
    cout<<"How many Dollars you want to donate?"<<endl;
    cin>>cash;
    balanceData[userNo] = balanceData[userNo] - cash;
    cout<<"Donation successful"<<endl;
    cout<<"Your balance is $"<<balanceData[userNo]<<endl;
    
    transactionHistory[userNo][transactionCount[userNo]] = to_string(cash) + " USD Donated on date: " + currentDateTime();
    transactionCount[userNo]++;
    pressAnyKey();

}

void History(int userNo){
    if(transactionCount[userNo] == 0){
        cout<<"You have not made any transaction."<<endl;
        return;
        pressAnyKey();
    }
    cout<<"Transaction History: "<<endl;
    for(int i=0;i<transactionCount[userNo];i++){
        cout<<i+1<<". "<<transactionHistory[userNo][i]<<endl<<endl;
    }
    pressAnyKey();
}

void payBills(){
    string ch;
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
        if(ch == "Y"){
            balanceData[userNo] = balanceData[userNo] - 30;
            cout<<"successful";
            cout<<"Your balance is $"<<balanceData[userNo]<<endl;
            
            transactionHistory[userNo][transactionCount[userNo]] = to_string(30) + "USD Paid on Electricity Bills on date: " + currentDateTime();
            transactionCount[userNo]++;
        }
        else{
            cout<<"Transaction cancelled"<<endl;
        }
    }
    else if(opt == 2){
        cout<<"The Gas Bill is $50, do you proceed to Pay?(Y/n)"<<endl;
        cin>>ch;
        if(ch == "Y"){
            balanceData[userNo] = balanceData[userNo] - 50;
            cout<<"successful";
            cout<<"Your balance is $"<<balanceData[userNo]<<endl;
            
            transactionHistory[userNo][transactionCount[userNo]] = to_string(50) + "USD Paid on Gas on date: " + currentDateTime();
            transactionCount[userNo]++;
        }
        else{
            cout<<"Transaction cancelled"<<endl;
        }
    }
    else if(opt == 3){
        cout<<"The Water Bill is $20, do you proceed to Pay?(Y/n)"<<endl;
        cin>>ch;
        if(ch == "Y"){
            balanceData[userNo] = balanceData[userNo] - 20;
            cout<<"successful";
            cout<<"Your balance is $"<<balanceData[userNo]<<endl;
            
    
            transactionHistory[userNo][transactionCount[userNo]] = to_string(20) + "USD Paid on water Bill on date: " + currentDateTime();
            transactionCount[userNo]++;
        }
        else{
            cout<<"Transaction cancelled"<<endl;
        }
    }
    else if(opt == 4){
        cout<<"The semester fee is $100, do you proceed to Pay?(Y/n)"<<endl;
        cin>>ch;
        if(ch == "Y"){
            balanceData[userNo] = balanceData[userNo] - 100;
            cout<<"Fee successful";
            cout<<"Your balance is $"<<balanceData[userNo]<<endl;
            
            transactionHistory[userNo][transactionCount[userNo]] = to_string(100) + "USD Paid on Semester Fees on date: " + currentDateTime();
            transactionCount[userNo]++;
        }
        else{
            cout<<"Transaction cancelled"<<endl;
        }

    }
    pressAnyKey();
}

void payTax(){
    char ch;
    cout<<"The tax is $50, do you proceed to Pay?(Y/n)"<<endl;
    cin>>ch;
    if(ch == 'Y'){
        balanceData[userNo] = balanceData[userNo] - 50;
        cout<<"Tax successful";
        cout<<"Your balance is $"<<balanceData[userNo]<<endl;
        
        transactionHistory[userNo][transactionCount[userNo]] = to_string(50) + " USD Paid Tax on date: " + currentDateTime();
        transactionCount[userNo]++;
    }
    else{
        cout<<"Transaction cancelled"<<endl;
    }
    pressAnyKey();
}

void calculateLoanBalance(){
    float loanAmount, payment, interestRate, years;
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
    pressAnyKey();
}

void checkDebt(){
    if(debtData[userNo] !=0){
        cout<<"You are in loan debt: $"<< debtData[userNo]<<endl; 
    }
    else{
        cout<<"You are debt free"<<endl;
    }
    pressAnyKey();
}

void payDebt(){
    char ch;    
    if(debtData[userNo] == 0){
        cout<<"You are debt Free."<<endl;
        return;
    }
    cout<<"Are you sure you want to pay the debt: (Y/n)"<<endl;
    cin>>ch;
    if(ch == 'Y' && balanceData[userNo] >= debt[userNo]){
        balanceData[userNo] -= debt[userNo];
        debt[userNo] = 0;
        cout<<"You have paid your debt"<<endl;
        cout<<"Your remaining balance: $"<<balanceData[userNo]<<endl;
        
        transactionHistory[userNo][transactionCount[userNo]] = to_string(debt[userNo]) + " USD Paid on Debt on date: " + currentDateTime();
        transactionCount[userNo]++;
    }
    else if(ch == 'n'){
        cout<<"Debt payment dismissed."<<endl;
        return;
    }
    else{
        cout<<"You dont have enough Money"<<endl;
    }
    pressAnyKey();
}

void transferMoney(){
    cout<<"Enter the account Number: ";
    cin>>accNo;
    if(getAccNo(accNo) == -1){
        cout<<"No such account number exists."<<endl;
        pressAnyKey();
        return;
    }
    cout<<"Enter amount you want to transfer: "<<endl;
    cin>>cash;
    if(cash>balanceData[userNo]){
        cout<<"You dont have enough money."<<endl;
        pressAnyKey();
        return;
    }
    balanceData[userNo] -= cash;
    balanceData[getAccNo(accNo)] += cash;
    cout<<cash<<"USD transferred successfully to "<<nameData[getAccNo(accNo)]<<endl;
    
    transactionHistory[userNo][transactionCount[userNo]] = to_string(cash) + " USD Paid transferred to " + nameData[getAccNo(accNo)] + "on date: " + currentDateTime();
    transactionCount[userNo]++;
    pressAnyKey();
}

void logInSuccessful() {
    while (true) { 
        body();
        string choice;
        if (!(cin >> choice)) {
            cin.clear();  
            cout << "Invalid input. Please enter a number." << endl;
            pressAnyKey();  
            continue; 
        }
        
            if(choice == "1"){ transaction(); }
            else if(choice == "2"){ addMoney(); }
            else if(choice == "3"){ checkBalance(); }
            else if(choice == "4") {donations();}
            else if(choice == "5"){ History(userNo);}
            else if(choice == "6"){payBills(); }
            else if(choice == "7") {calculateLoanBalance(); }
            else if(choice == "8"){ ApplyforLoan();}
            else if(choice == "9") {checkLoanStatus();}
            else if(choice == "10") {checkDebt();}
            else if(choice == "11") {transferMoney();}
            else if(choice == "12") {payDebt();}
            else if(choice == "-1") return;
            else if(choice == "0") {Footer(); break;}
            else {cout << "Invalid choice, try again." << endl; pressAnyKey();}
        
    }
    printInterface();
}

// Sign UP

void signUP(){
    if(checkUserCapacity()){
        string cnic,DOB,email2,password,name;
        cout<<"Enter your name : ";
        cin.ignore();
        getline(cin,name);
        nameData[userNo] = name;
        DOB:
        cout<<"Enter your Date of birth: ";
        cin>>DOB;
        if(isValidDOBFormat(DOB)){
            DOBData[userNo] = DOB;
        }
        else{
            cout<<"Invalid DOB, please try again"<<endl;
            goto DOB;
        }
        CNIC:
        cout<<"Enter your CNIC: (with Dashes)";
        cin>>cnic;
        if(CNICval(cnic)){
            if(getCNIC(cnic) != -1){
                cout<<"CNIC already exists."<<endl;
                goto CNIC;
            }
            else CNICData[userNo] = cnic;
        }
        else{
            cout<<"Please Enter a valid CNIC"<<endl;
            goto CNIC;
        }
        Email:
        cout<<"Enter your email: ";
        cin>>email2;
        if(emailVal(email2)){
            if(getUserEmail(email2) != -1){
                cout<<"email already exists"<<endl;
                goto Email;
            }
            else emailData[userNo] = email2;
        }
        else{
            cout<<"Invalid Email."<<endl;
            goto Email;
        }
        cout<<"Enter your password: ";
        cin>>passwordData[userNo];
        cout<<"Congratulations! you have successfully been registered to XYZ bank.\n Login to your bank account with the same credentials";
            userCount++;
    }
    else{
        cout<<"The bank is full, contact the admin."<<endl;
        pressAnyKey();
        return;
    }
    accNumberData[userNo] = accNumberData[userNo-1] + 1;
    balanceData[userNo] = 0;
    debtData[userNo] = 0;
    balanceData[userNo] =0;
    pressAnyKey();
}

// ADMIN

void adminLogin(){
    cout<<endl;
    cout << "___   ___ ____    ____  ________     .______        ___      .__   __.  __  ___ " << endl;
    cout << "\\  \\ /  / \\   \\  /   / |       /     |   _  \\      /   \\     |  \\ |  | |  |/  / " << endl;
    cout << " \\  V  /   \\   \\/   /  `---/  /      |  |_)  |    /  ^  \\    |   \\|  | |  '  /  " << endl;
    cout << "  >   <     \\_    _/      /  /       |   _  <    /  /_\\  \\   |  . `  | |    <   " << endl;
    cout << " /  .  \\      |  |       /  /----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\  " << endl;
    cout << "/__/ \\__\\     |__|      /________|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\ " << endl;
    cout<<"Please Login to your admin account"<<endl;
    cout<<"Email : ";
    cin>>userEmail;
    cout<<"PIN : ";
    cin>>userPIN;
}

void adminAddSubtractMoney(){
    cout<<"Enter the email";
    cin>>userEmail;
    if(getUserEmail(userEmail) == -1){
        cout<<"Account doesnt Exist. "<<endl;
    }
    else{
        userNo = getUserEmail(userEmail);
        cout<<"Press 1 to add money, 2 to subtract money";
        cin>>option;
        if (option == "1"){
            cout<<"how many money you want to remove: $";
            cin>>cash;
            balanceData[userNo]-=cash;
            cout<<"cash has been removed";
        }
        if (option == "2"){
            cout<<"how many money you want to add: $";
            cin>>cash;
            balanceData[userNo]+=cash;
            cout<<"money has been added";
        }
    }
    pressAnyKey();
}

void adminViewUser() {
    cout << left << setw(10) << "SerialNo." 
         << setw(15) << "AccountNo"
         << setw(20) << "Name" 
         << setw(15) << "Balance" 
         << setw(20) << "CNIC"
         << setw(15) << "DOB"
         << setw(25) << "Email" 
         << setw(20) << "Password" 
         << setw(10) << "Debt" 
         << endl;
    cout << string(150, '-') << endl;

    for (int i = 0; i < userCount; i++) {
        cout << left << setw(10) << i + 1
             << setw(15) << accNumberData[i]
             << setw(20) << nameData[i]
             << setw(15) << balanceData[i]
             << setw(20) << CNICData[i]
             << setw(15) << DOBData[i]
             << setw(25) << emailData[i]
             << setw(20) << passwordData[i]
             << setw(10) << debtData[i]
             << endl;
    }
    pressAnyKey();
}

void adminLoan(){
    if(loanApplicationData[userNo] == 1){
        cout<<"Loan Application by user: "<<nameData[userNo]<<" of amount $"<<loanAmountData[userNo]<<"for: "<<yearsData[userNo]<<"Years"<<endl;
        cout<<"Press 1 to approve, 0 to reject";
        cin>>loanApprovalData[userNo];
        if(loanApprovalData[userNo]==1){
            cout<<"Enter interest Rate: ";
            cin>>interest[userNo];
            cout<<"Loan Approved.";
            debtData[userNo] += interest[userNo] * loanAmountData[userNo]/100 + loanAmountData[userNo];
            balanceData[userNo] += loanAmountData[userNo];
            
            transactionHistory[userNo][transactionCount[userNo]] = to_string(loanAmountData[userNo]) + " USD Loan Approved on date: " + currentDateTime();
            transactionCount[userNo]++;
        }
        else{
            cout<<"Loan dismissed.";
        }
    }
    else{
        cout<<"No loan Application";
    
    }
    pressAnyKey();
}

bool adminDelete(string emailIN){
    if(getUserEmail(emailIN) == -1){
        return 0;
    }
    DeleteUserData(getUserEmail(emailIN));
    return 1;
}

void adminUpdatePassword(string emailIN){
    if(getUserEmail(emailIN) == -1){
        cout<<"User doesnot exist;"<<endl;
        return;
    }
    else{
        cout<<"Enter new password: ";
        cin>>password;
        passwordData[getUserEmail(emailIN)] = password;
        cout<<"Password Updated Successfully"<<endl;
    }
    pressAnyKey();
}

void adminGiveBonus(int amount){
    for(int i=0;i<userCount;i++){
        balanceData[i] += amount;
    }
    cout<<"Bonus Successful"<<endl;
    pressAnyKey();
}

void adminViewHistory(string email){
    int user = getUserEmail(email);
    if(user == -1){
        cout<<"User doesnot exist."<<endl;
        return;
    }
    cout<<"History for the user "<<nameData[user]<<endl;
    History(user);

    pressAnyKey();
}

void adminFunction(){
    while(true){
        cout<<endl;
        cout<<"Press 1 to create account"<<endl;
        cout<<"Press 2 to add/remove money to the account"<<endl;
        cout<<"press 3 to approve loans"<<endl;
        cout<<"Press 4 to check User Data"<<endl;
        cout<<"Press 5 to Delete User"<<endl;
        cout<<"Press 6 to Update Password"<<endl;
        cout<<"Press 7 to Give Bonus to All Users"<<endl;
        cout<<"Press 8 to obtain banking History"<<endl;
        cout<<"press 0 to logOut"<<endl;
        cout<<"Your option: ";
        cin>>option;
        if(option == "1"){
            signUP();
        }
        else if(option == "2"){
            adminAddSubtractMoney();
        }
        else if(option == "3"){
            adminLoan();
        }
        else if(option == "4"){
            adminViewUser();
        }
        else if(option == "5"){
            cout<<"Enter the email of the user you want to delete"<<endl;
            cin>>email;
            if(!adminDelete(email)) cout<<"email doesnot exist.";
            else cout<<"Deleted successfully.";
        } 
        else if(option == "6"){
            cout<<"Enter the email you want to update password: ";
            cin>>email;
            adminUpdatePassword(email);
            cout<<"Password Updated";
        }
        else if(option == "7"){
            int amount;
            cout<<"How much bonus you want to give them? : ";
            cin>>amount;
            adminGiveBonus(amount);
        }
        else if(option == "8"){
            string email;
            cout<<"Enter email of the user you want to obtain the bankin history: ";
            cin>>email;
            adminViewHistory(email);
        }
        else if(option == "0"){
            break;
        }
        else{
            cout<<"Invalid."<<endl;
            pressAnyKey();
        }
    }
}


main(){ 
    system("cls");
    while(true){
        start:
        printInterface();
        if(option=="1"){
            system("cls");
            printHeader();
            if(signIN(userEmail,password)){
                logInSuccessful();
            }
            else{
                cout<<"Invalid username or password";
                pressAnyKey();
                goto start;
            } 
        }
        else if(option == "2"){
            adminLogin();
            if(userEmail == adminEmail && userPIN == adminPass){
                adminFunction();
            }
            else{
                cout<<"Invalid username or password";
                pressAnyKey();
                goto start;
            }
        }
        else if(option == "3"){
            signUP();
        }
        else if(option == "0"){
            Footer();
            break;
        }
        else{
            cout<<"InvalidOption";
            pressAnyKey();
            goto start;
        }
    }
} 