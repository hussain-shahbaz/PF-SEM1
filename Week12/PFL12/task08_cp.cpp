#include<iostream>
using namespace std;
int getLargestColumn(int rows,int cols,int matrix[][10]){
    int k=0;
    int maxCol = 0;
    for(int i=0;i<cols;i++){
        int colSum = 0;
        for(int j=0;j<rows;j++){
            colSum += matrix[j][i];
        }
        if(colSum > maxCol){
            maxCol = colSum;
            k = i;
        }
    }
    return k;
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void replaceColumns(int col1,int col2, int matrix[][10], int rowSize){
    for(int i=0;i<rowSize;i++){
        swap(matrix[i][col1] , matrix[i][col2]);
    }
}
int main(){
     int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    int matrix[10][10];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    int largestCol = getLargestColumn(rows, cols, matrix);
    replaceColumns(0, largestCol, matrix, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}