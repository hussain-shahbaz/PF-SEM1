#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x,int y){
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printUET(){
    system("cls");
    cout<<"=============================================================="<<endl;
    cout<<"            UET, Lahore ADMISSION MANAGEMENT SYSTEM           "<<endl;
    cout<<"=============================================================="<<endl;

    cout<<"Enter 1 to calculate aggregate \nEnter 2 to compare marks \n Enter 3 to exit code";

}
void footer(){
    cout<<endl<<endl<<endl;
    cout<<"                                                                    Copyright UET@2024"<<endl;
    cout<<"                                                                    All rights reserved"<<endl;
}
void calculateAggregate(string name, float matric, float inter, float ecat){
    float agg = (matric/1100)*30 + (inter/540)*30 + (ecat/400)*40;
    cout<<name<<" has aggregate = "<<agg<<"%"<<endl;
}
void compareAGG(string std1, int e1, string std2, int e2, string std3, int e3){
    if(e1>e2){
        if(e1>e3){
            cout<<std1<<" has the highest aggregate"<<endl;
        }
        else{
            cout<<std3<<" has the highest aggregate"<<endl;
        }
    }
    else if(e2>e1){
        if(e2>e3){
            cout<<std2<<" has the highest aggregate"<<endl;
        }
        else{
            cout<<std3<<" has the highest aggregate"<<endl;
        }
    }
}

main(){
    printUET();

    while(true){
        int input;
        cin>>input;
        if(input == 3){
            break;
        }
        if(input == 1){
            int matric, inter, ecat;
            string name;
            cout<<"Enter your name"<<endl;
            cin>>name;
            cout<<"Enter your Matric marks(out of 1100)"<<endl;
            cin>>matric;
            cout<<"Enter your Inter First Year(out of 550)"<<endl;
            cin>>inter;
            cout<<"Enter your ecat(out of 400)"<<endl;
            cin>>ecat;
            calculateAggregate(name,matric, inter,ecat);
            cout<<endl<<endl;
            
        }
        else if(input == 2){
            string std1 , std2, std3;
            float  e1,e2,e3;
            cout<<"enter first student name"<<endl;
            cin>>std1;
            cout<<"enter "<<std1<<"'s Ecat number"<<endl;
            cin>>e1;
            cout<<"enter first student name"<<endl;
            cin>>std2;
            cout<<"enter "<<std2<<"'s Ecat name"<<endl;
            cin>>e2;
            cout<<"enter first student name"<<endl;
            cin>>std3;
            cout<<"enter "<<std3<<"'s Ecat name"<<endl;
            cin>>e3;
            cout<<"press 3 to exit"<<endl;
            compareAGG(std1,e1,std2,e2,std3,e3);
            cout<<endl<<endl;


        }
        
        else{
            cout<<"please enter a valid input"<<endl;
        }

    }
    footer();
}