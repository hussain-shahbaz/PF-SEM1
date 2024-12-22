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
    
    vector<int> nums = getNumbers("data.txt");
    int evenSum = 0;
    int oddSum = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] %2 == 0) evenSum += nums[i];
        else oddSum += nums[i];
    }
    cout<<"sum of even numbers: "<<evenSum<<endl;
    cout<<"sum of odd  numbers: "<<oddSum<<endl;
    return 0;
}