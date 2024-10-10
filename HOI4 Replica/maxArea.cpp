#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>  &height) {
    int mxArea = 0;
    int mini=0;
    int mx=0;
    int left = 0;
    int right = height.size() - 1;
    vector<int> ans;
    while(left<right){
        int mini = min(height[left],height[right]);
        mxArea = (right-left)*mini;
        mx = max(mxArea,mx);
        height[left]<height[right] ? left++ : right--;
    }
    
    return mx;
}
int main(){
    vector<int> x = {1,2,3};
    cout<<maxArea(x);
}

