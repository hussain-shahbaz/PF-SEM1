#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> field =  {
    {'#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#'},
    {' ',' ',' ','#',' ',' ',' '},
    {' ',' ',' ','#',' ',' ',' '},
    {' ',' ',' ','#',' ',' ',' '},
    {' ',' ',' ','#',' ',' ',' '},
    
};
bool Goal(string cc){
    int rowNum = cc[0] - 'A';
    int colNum = cc[1] - '0' - 1;
    if(field[rowNum][colNum ] == ' ' &&  rowNum < 4) return true;
    return false;
}
int main(){
    cout<<"Enter Co-ordinates: ";
    string cc;
    cin>>cc;
    cout<<Goal(cc);
    return 0;
}