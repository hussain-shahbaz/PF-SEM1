#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n = 7;
    int arr[n] = {1,2,7,9,10,15,19};
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    int sumA;
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                sumA = arr[i]+arr[j]+arr[k];
                ans.push_back(sumA);
                sumA = 0;
            }

        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<ans.size();j++){
            if(arr[i] == sum - 3*ans[j]){
            cout<<arr[i];
            break;
            }
        }
    }
}