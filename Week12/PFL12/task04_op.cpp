#include<iostream>
using namespace std;
int cols;
int getSum(int rows,const int cols,int **matrix){
    int sum = 0;
    for(int row=0;row<rows;row++){
        for(int col=0;col < cols;col++){
            sum += matrix[row][col];
        }
    }
    return sum;
}

int main(){
    int rows, cols;
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>cols;
    // Dynamically allocating a 2d Array
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    for(int row=0;row<rows;row++){
        for(int col=0;col < cols;col++){
            cout<<"Enter Element ["<<row+1<<"]["<<col+1<<"]: ";
            cin>>matrix[row][col];
        }
    }
    for(int row=0;row<rows;row++){
        for(int col=0;col < cols;col++){
            cout<<matrix[row][col]<<"\t";
        }
        cout<<endl;
    }
    cout<<"The total sum is: "<<getSum(rows,cols,matrix);
    return 0;
}