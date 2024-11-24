#include<iostream>
using namespace std;
bool isRepeatingCycle(int arr[], int size, int cycle){
    if(cycle > size) return true;
    for(int i=0;i<size - cycle;i++){
        if(arr[i] != arr[i+cycle]) return false;
    }
    return true;
}
int main(){
    int n, cycleLength;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the length of the cycle: ";
    cin >> cycleLength;
    cout<<isRepeatingCycle(arr,n,cycleLength);
}