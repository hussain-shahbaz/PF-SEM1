#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter numbers count: ";
    cin>>n;
    int inp;
    float p1=0;
    float p2=0;
    float p3=0;
    float p4=0;
    float p5=0;
    for(int i=1;i<=n;i++){
        cout<<"Enter a number: ";
        cin>>inp;
        if(inp<200) p1++;
        else if(inp>=200 && inp<400) p2++;
        else if(inp>=400 && inp<600) p3++;
        else if(inp>=600 && inp<800) p4++;
        else if(inp>=800) p5++; 
    }
    cout<<"p1: "<<(p1/n)*100<<"%"<<endl;
    cout<<"p2: "<<(p2/n)*100<<"%"<<endl;
    cout<<"p3: "<<(p3/n)*100<<"%"<<endl;
    cout<<"p4: "<<(p4/n)*100<<"%"<<endl;
    cout<<"p5: "<<(p5/n)*100<<"%"<<endl;
    
}