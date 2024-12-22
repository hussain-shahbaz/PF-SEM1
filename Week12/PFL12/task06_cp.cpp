#include<iostream>
using namespace std;
char matrix[5][5] = {
    {'.', '.', '.', '*', '*'},
    {'.', '*', '.', '.', '.'},
    {'.', '*', '.', '.', '.'},
    {'.', '*', '.', '.', '.'},
    {'.', '.', '*', '*', '.'},
    };
string fire(string cc){
    int rowNum = cc[0] - 'A';
    int colNum = cc[1] - '0' - 1;
    cout<<rowNum<<colNum;
    if(matrix[rowNum][colNum ] == '*') return "BOOM";
    return "splash";

}
int main(){
    
    cout<<"Enter Co-ordinates: ";
    string cc;
    cin>>cc;
    cout<<fire(cc);
    return 0;
}