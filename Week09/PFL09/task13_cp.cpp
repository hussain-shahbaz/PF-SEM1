#include<iostream>
using namespace std;
void jazzifyChords(string chords[], int size){
    for(int i=0;i<size;i++){
        chords[i] += '7';
    }
    cout<<"jazzified chords: [";
    for(int i=0;i<size;i++){
        if(i == size-1) cout<<chords[i]<<"]";
        else cout<<chords[i]<<", ";
    }
}
int main(){
    cout<<"Enter the number of chords: ";
    int size;
    cin>>size;
    string chords[size];
    for(int i=0;i<size;i++){
        cout<<"Enter chord: ";
        cin>>chords[i];
    }
    jazzifyChords(chords,size);


    return 0;
}