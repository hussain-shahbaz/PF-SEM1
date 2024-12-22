#include<iostream>
using namespace std;
bool doesBrickFit(int a, int b, int c, int w, int h){
    if((a <= w && b <= h) || (a <= h && b <= w) ||
            (a <= w && c <= h) || (a <= h && c <= w) ||
            (b <= w && c <= h) || (b <= h && c <= w)) return true;

    return false;
}
int main(){
    int A, B, C, W, H;
    cout << "Enter dimensions of the brick (A B C): ";
    cin >> A >> B >> C;
    cout << "Enter dimensions of the opening (W H): ";
    cin >> W >> H;
    cout<<doesBrickFit(A,B,C,W,H);
    return 0;
}