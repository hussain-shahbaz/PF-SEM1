#include<iostream>
using namespace std;
string digitToText(int n){
    string result = "";
    if(n>=20){
        if(n/10 == 2){
            result += "Twenty";
        }
        else if(n/10 == 3){
            result += "Thirty";
        }
        else if(n/10 == 4){
            result += "Forty";
        }
        else if(n/10 == 5){
            result += "Fifty";
        }
        else if(n/10 == 6){
            result += "Sixty";
        }
        else if(n/10 == 7){
            result += "Seventy";
        }
        else if(n/10 == 8){
            result += "Eighty";
        }
        else if(n/10 == 9){
            result += "Ninety";
        }
    }
    if(n%10 !=0){
        n = n%10;
    }
    else{
        return result;
    }
    if (n == 1) result += "One";
    else if (n == 2) result += "Two";
    else if (n == 3) result += "Three";
    else if (n == 4) result += "Four";
    else if (n == 5) result += "Five";
    else if (n == 6) result += "Six";
    else if (n == 7) result += "Seven";
    else if (n == 8) result += "Eight";
    else if (n == 9) result += "Nine";
    else if (n == 10) result += "Ten";
    else if (n == 11) result += "Eleven";
    else if (n == 12) result += "Twelve";
    else if (n == 13) result += "Thirteen";
    else if (n == 14) result += "Fourteen";
    else if (n == 15) result += "Fifteen";
    else if (n == 16) result += "Sixteen";
    else if (n == 17) result += "Seventeen";
    else if (n == 18) result += "Eighteen";
    else if (n == 19) result += "Nineteen";

    return result;
}

main(){
    int n;
    cout<<"Enter a digit(1-99)";
    cin>>n;
    cout<<digitToText(n);
}