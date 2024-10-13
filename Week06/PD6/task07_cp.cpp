#include <iostream>
#include <cmath>
using namespace std;
string checkStudentStatus(int examHour, int examMinute, int studentHour, int studentMinute)
{
    string answer;
    int remHour = studentHour - examHour;
    int remMinute = (studentMinute - examMinute);
    if (remMinute > 0)
        {
            remMinute = 60 - remMinute;
        }
    if (examHour == studentHour && examMinute == studentMinute)
    {
        answer = "On time";
    }
    else if (studentHour > examHour)
    {
        remMinute = studentMinute + examMinute;
        if (remHour == 1)
            answer = "Late\n" + to_string(abs(remMinute)) + " minutes after the start";
        else
            answer = "Late\n" + to_string(abs(remHour)) + ":" + to_string(abs(remMinute)) + " after the start";
    }
    else if (studentHour < examHour)
    {
        if (remHour == -1)
            answer = "Early\n" + to_string(abs(remMinute)) + " minutes before the start";
        else
            answer = "Early\n" + to_string(abs(remHour)) + ":" + to_string(abs(remMinute)) + " before the start";
    }
    return answer;
}
int main()
{
    int examHour, examMinute, studentHour, studentMinute;
    cout << "Enter Exam Starting time(hour) : ";
    cin >> examHour;
    cout << "Enter Exam Starting time(minutes) : ";
    cin >> examMinute;
    cout << "Enter Student hour of arrival : ";
    cin >> studentHour;
    cout << "Enter student minutes of arrival : ";
    cin >> studentMinute;
    cout << checkStudentStatus(examHour, examMinute, studentHour, studentMinute);
    return 0;
}