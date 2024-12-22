#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int myStoi(string number){
    int num=0;
    for(int i=0;i<number.size();i++){
        num = num*10 + (number[i] - '0');
    }
    return num;
}
vector<int> getNumbers(string fileName){
    fstream file;
    string str;
    file.open(fileName,ios::in);
    getline(file,str);
    file.close();
    vector<int> nums;
    string num = "";
    for(int i=0;i<str.size();i++){
        if(str[i] == ' '){
            if (!num.empty()) {
                nums.push_back(myStoi(num));
                num = "";
            }
        }
        else{
            num += str[i]; 
        }
    }
    if (!num.empty()) {
        nums.push_back(myStoi(num));
    }
    return nums;
}
int main(){
    fstream file;
    file.open("squares.txt",ios::out);
    vector<int> nums = getNumbers("numbers.txt");
    for(int i =0;i<nums.size();i++){
        file << nums[i]*nums[i] << " ";
    }
    file.close();
    return 0;
}