#include<iostream>
#include<string>
using namespace std;
bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
string integerToBinary(int n){
    string binary="";
    string answer="";
    while(n!=0){
        if(n%2==1) binary += "1";
        else  binary += "0";
        n /=2;
    }
    for(int i=binary.size()-1;i>=0;i--){
        answer += binary[i];
    }
    return answer;
}
int oneCountInBinaryOfInt(int n){
    string bin = integerToBinary(n);
    int oneCount=0;
    for(int i=0;i<bin.size();i++){
        if(bin[i]=='1') oneCount++;
    }
    return oneCount;
}
string howBad(int n){
    string answer = "";
    int ones = oneCountInBinaryOfInt(n);
    if(ones%2 != 0) answer += "Odius";
    else answer += "Evil";
    if(isPrime(ones)) answer += ", Pernious";
    return answer;
}
int main(){
    cout<<howBad(23);
    return 0;
}