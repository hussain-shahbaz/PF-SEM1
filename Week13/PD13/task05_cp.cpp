#include<iostream>
#include<cctype>
using namespace std;
char letters[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
        'U', 'V', 'W', 'X', 'Y', 'Z', 
        '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
    };
string morseCode[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
        "..-", "...-", ".--", "-..-", "-.--", "--..", 
        ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
    };
string mourseCode(string str){
    int j;
    string answer = "";
    for(int i = 0; str[i] != '\0';i++){
        for(j=0;j<36;j++){
            if(toupper(str[i]) == letters[j]) break;
        }
        answer += morseCode[j];
        answer += " ";
    }
    return answer;
}
int main(){
    cout<<mourseCode("john f kennedy");
    return 0;
}