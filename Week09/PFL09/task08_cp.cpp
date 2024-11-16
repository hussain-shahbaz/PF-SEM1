#include<iostream>
using namespace std;
void insertArrayInTheMiddle(int firstArray[],int firstArraySize, int secondArray[], int secondArraySize){
    int resultingArraySize = firstArraySize+secondArraySize;
    int resultingArray[resultingArraySize];
    int lastElement = firstArray[1];
    
    resultingArray[0] = firstArray[0];
    for(int i=1;i<resultingArraySize-1;i++){
        resultingArray[i] = secondArray[i-1];
    }
    resultingArray[resultingArraySize-1] = lastElement;
    
    cout<<"Resulting Array: [";
    for(int i=0;i<resultingArraySize;i++){
        if(i == resultingArraySize-1) cout<<resultingArray[i]<<"]";
        else cout<<resultingArray[i]<<", ";
        
    }
    
}
int main(){
    int n;
    cout<<"Enter the size of the first Array: (must be 2)";
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr1[i];
    }
    int m;
    cout<<"Enter the size of the second Array: ";
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cout<<"Enter element: ";
        cin>>arr2[i];
    }
    insertArrayInTheMiddle(arr1,n,arr2,m);
    
    return 0;
}