#include<iostream>
using namespace std;
string calcuateGrade(float average){
    if(average>=90 && average<=100) return "A+";
    else if(average>=80 && average<90) return "A";
    else if(average>=70 && average<80) return "B+";
    else if(average>=60 && average<70) return "B";
    else if(average>=50 && average<60) return "C";
    else if(average>=40 && average<50) return "D";
    else return "E";
}
float calculateAverage(float marksEnglish, float  marksMaths, float marksChemistry, float marksSciences, float marksBiology){
    return (marksEnglish + marksMaths + marksChemistry + marksSciences + marksBiology)/5;
    
}




int main(){
    float english, maths, chemistry, social_sciences, biology, name;
    cout<<"Enter the marks for English";
    cin>>english;
    cout<<"Enter the marks for Maths";
    cin>>maths;
    cout<<"Enter the marks for Chemistry";
    cin>>chemistry;
    cout<<"Enter the marks for Social Sciences";
    cin>>social_sciences;
    cout<<"Enter the marks for Biology";
    cin>>biology;
    cout<<"Enter your  name";
    cin>>name;
    cout<<"Grade : "<<calcuateGrade(calculateAverage(english,maths,chemistry,social_sciences,biology))<<endl;
    cout<<"Percentage : "<<calculateAverage(english,maths,chemistry,social_sciences,biology)<<"%";
    return 0;
}