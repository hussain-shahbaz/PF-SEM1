#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int myStoi(string str){
    int number = 0;
    for(int i=0;str[i] != '\0';i++){
        number = number*10 + (str[i] - '0');
    }
    return number;
}

string getName(string line, int &i){
    string name = "";
    while(line[i] != ' '){
        name += line[i];
        i++;
    }
    i++;
    return name;
}
int getArraySize(string line, int &i){
    string temp = "";
    while(line[i] != ' '){
        temp += line[i];
        i++;
    }
    i++;
    return myStoi(temp);
}
vector<int> getPoints(string line, int &i){
    vector<int> points;
    string temp = "";
    i++;
    for(int itr = i; line[itr] != ']';itr++){
        if(line[itr] == '[') continue;
        if(line[itr] == ',' || line[itr] == ']'){
            points.push_back(myStoi(temp));
            temp = "";
        }
        else temp += line[itr];
    }
    return points;
}

    vector<string> names;
    vector<int> size;
    vector<vector<int>> points;
    vector<bool> eligible;
bool isEligible(vector<int> points, int N, int Y){
    int count = 0;
    int n = points.size();
    for(int i=0;i<n;i++){
        if(points[i] >= Y) count++;
    }
    
    return count >= N;
}
void getData(string fileName){
    fstream file;
    file.open(fileName, ios::in);
    string line;
    while(getline(file, line)){
        int i=0;
        names.push_back(getName(line,i));
        size.push_back(getArraySize(line,i));
        points.push_back(getPoints(line,i));
    }
    file.close();
}

void freePizza(int N, int Y){
    int n = names.size();
    cout<<"The people eligible for free pizza are: "<<endl;
    for(int i=0;i<n;i++){
        if(isEligible(points[i],N,Y)) cout<<names[i]<<endl;
    }
}

int main(){
    getData("Customers.txt");
    freePizza(5,1);
    return 0;
}