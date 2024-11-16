#include<iostream>
using namespace std;
int main(){
float x = 7, y = 54, mystery; 
if (x > y){ 
   mystery = x - y; 
} 
else{ 
   if (x < y){ 
     mystery = y / x; 
   } 
   else{ 
     mystery = x + y; 
   } 
} 
  cout << mystery; 
    return 0;
}