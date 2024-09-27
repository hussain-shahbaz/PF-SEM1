#include<iostream>
#include<windows.h>
using namespace std;
void printH(){
    cout << "###  ###" << endl;
    cout << "###  ###" << endl;
    cout << "#######" << endl;
    cout << "###  ###" << endl;
    cout << "###  ###" << endl;
    cout<<endl;
}
void printU(){
    cout << "###  ###" << endl;
    cout << "###  ###" << endl;
    cout << "###  ###" << endl;
    cout << "###  ###" << endl;
    cout << " ######" << endl;
    cout<<endl;
}
void printS(){
    cout << "###### " << endl;
    cout << "###    " << endl;
    cout << " ##### " << endl;
    cout << "    ###" << endl;
    cout << "###### " << endl;
    cout<<endl;
}
void printA(){
    cout << "######## " << endl;
    cout << "###  ###" << endl;
    cout << "########" << endl;
    cout << "###  ###" << endl;
    cout << "###  ###" << endl;
    cout<<endl;
}
void printI(){
    cout << "###" << endl;
    cout << "###" << endl;
    cout << "###" << endl;
    cout << "###" << endl;
    cout << "###" << endl;
    cout<<endl;
}
void printN(){
    cout << "###   ##" << endl;
    cout << "####  ##" << endl;
    cout << "########" << endl;
    cout << "### ####" << endl;
    cout << "###  ###" << endl;
    cout<<endl;
}
void printHussain(){
    printH();
    printU();
    printS();
    printS();
    printA();
    printI();
    printN();
}
void printHassan(){
    printH();
    printA();
    printS();
    printS();
    printA();
    printN();

}
main(){
    printHassan();
}
