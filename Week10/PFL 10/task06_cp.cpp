#include<iostream>
using namespace std;
void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
void sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main(){
    int arr[7] = {3,6,1,8,3,0,11};
    sort(arr,7);
     for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
    
   
}