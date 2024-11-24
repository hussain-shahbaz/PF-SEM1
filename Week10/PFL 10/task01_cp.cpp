#include<iostream>
using namespace std;
int progressDays(int arr[],int n){
    int count = 0;
    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1]) count++;
    }
    return count;
}
int main(){
    int days;
    cout<<"Enter the number of days you have ran: ";
    cin>>days;
    cout<<"Enter the miles for each day: "<<endl;
    int miles[days];
    for(int i=0;i<days;i++){
        cout<<"Enter miles for day "<<i+1<<": ";
        cin>>miles[i];
    }
    cout<<"Number of progress days: "<<progressDays(miles,days);

    return 0;
}