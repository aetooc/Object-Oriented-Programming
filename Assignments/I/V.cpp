/*

5. Write a function in C++ which accepts a 2D array of integers and its size as arguments and displays the elements of middle row and the elements of middle column.
[Assuming the 2D Array to be a square matrix with odd dimension i.e. 3x3, 5x5, 7x7 etc...]
    
    Example, if the array contents is

    3  5  4
    7  6  9
    2  1  8
*/


#include <iostream>

using namespace std;

int MiddleRowAndColumn(int matrix[][50], int matrixSize);
    
int main(){

    int temp, matrix[50][50];
    cout << "Enter: ";
    cin >> temp;
    const int matrixSize = temp;
    MiddleRowAndColumn(matrix, matrixSize);

return 0;    
}

int MiddleRowAndColumn(int matrix[][50], int matrixSize){

    int x = matrixSize / 2;

    // Assigning values to the matrix
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            cout << "Enter the element on the A[" << 1 + i << "," << 1 + j <<   "]: ";
            cin >> matrix[i][j];

        }
    }

    // Displaying the Matrix
    cout << "Matrix: \n";
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nThe Middle Row of Matrix    : \t";
    for(int j = 0; j < matrixSize; j++){
        cout << matrix[x][j] << "\t";
    }
    cout << "\nThe Middle Column of Matrix : \t";
    for(int i = 0; i < matrixSize; i++){
        cout << matrix[i][x] << "\t";
    }
    cout << endl;

return 0;
}