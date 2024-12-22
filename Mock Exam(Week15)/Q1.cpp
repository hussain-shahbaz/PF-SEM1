#include<iostream>
#include<vector>
using namespace std;
int factorial(int n){
    int factorial = 1;
    for(int i=2;i<=n;i++){
        factorial *= i;
    }
    return factorial;
}

int main(){
    vector<int> nums;
    int n;
    while(true){
        cout<<"Enter number(press -1 to exit): ";
        cin>>n;
        if(n == -1) break;
        nums.push_back(n);
    }
    for(int i=0;i< nums.size();i++) cout<<"factorial of "<<nums[i]<<" is: "<<factorial(nums[i])<<endl;
    return 0;
}