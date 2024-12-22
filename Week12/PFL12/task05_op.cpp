#include<iostream>
using namespace std;
bool checkIdentityMatrix(int rows, int cols, int **matrix){
    if(rows != cols) return false;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i == j && matrix[i][j] != 1)  return false;
            if(i != j && matrix[i][j] != 0)  return false;
        }
    }
    return true;
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
    cout<<"The matrix you entered: "<<endl;
    
    for(int row=0;row<rows;row++){
        for(int col=0;col < cols;col++){
            cout<<matrix[row][col]<<"\t";
        }
        cout<<endl;
    }
    cout<<checkIdentityMatrix(rows,cols,matrix);
    return 0;
}