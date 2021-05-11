/*

2. Write user defined functions for square matrix to calculate

    1. Left diagonal sum
    2. Right diagonal sum

*/

#include<iostream>

using namespace std;

int DiagonalSum(int matrix[][50]);

int leftDiagonalSum = 0, rightDiagonalSum = 0;

int main(){
    int matrix[50][50];
    DiagonalSum(matrix);

return 0;
}

int DiagonalSum(int matrix[][50]){

    int  rows, columns;
    cout << "Enter the number of Rows and Columns: ";
    cin >> rows >> columns;

    // Assigning values to matrix
    cout << "Enter the elements of the matrix: \n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << "Enter the element on A[" << 1 + i << "," << 1 + j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // For sum of the left Diagonal
    for(int i = 0; i < rows; i++){
        rightDiagonalSum += matrix[i][columns - i -1];
        for(int j = 0; j < columns; j++){
            if(i == j)
                leftDiagonalSum += matrix[i][j];
        }
    }

    // Displaying the sum of the left diagonal
    cout <<"\nThe sum of the Left diagonal is : " << leftDiagonalSum << endl;
    cout <<"\nThe sum of the Right diagonal is : " << rightDiagonalSum << endl;


return 0;
}