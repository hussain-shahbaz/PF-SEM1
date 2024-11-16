#include<iostream>
using namespace std;
string plant(string seed, int water, int fert, int temp){
    string answer = "";
    for(int i=0;i<water;i++){
        for(int j=0;j<water;j++){
            answer+="-";
        }
        if(temp>=20 && temp<=30){
            for(int j=0;j<fert;j++){
            answer+=seed;
            }
        }
        else{
            if(i==water-1) answer+=seed;
        }
    }
    return answer;
}
int main(){
    cout<<plant("#",5,1,20);
    return 0;
}