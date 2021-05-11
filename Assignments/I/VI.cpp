/*

6. Write a program to add two array A and B of size m x n.

*/

// Including header file 'iostream'
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    int rows, columns;
    int matrixOne[50][50], matrixTwo[50][50], finalMatrix[50][50];

    // Asking for rows and columns of the matrix
    cout << "Enter the Number of Rows and Number of Column: ";
    cin >> rows >> columns;

    // Assigning values to first matrix
    cout << "Enter the elements of first matrix: \n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << "Enter the element on A[" << i + 1 << "," << j + 1 << "]: ";
            cin >> matrixOne[i][j];

            }
    }

    // Assigning values to second matrix
    cout << "Enter the elements of second matrix: \n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << "Enter the element on B[" << i + 1 << "," << j + 1 << "]: ";
            cin >> matrixTwo[i][j];

            }
    }

    // Adding both Matrixs
     for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){

            // Adding element of matrix A and B
            // And Storing it in finalMatrix
            finalMatrix[i][j] = matrixOne[i][j] + matrixTwo[i][j];

        }
    }

    //Displaying matrix A:
    cout << "\nMatrix A:\n\n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){

            cout << setw(4) <<  matrixOne[i][j] << "  ";

            }
        cout << endl;
    }
    
    
    //Displaying matrix B:
    cout << "\nMatrix B:\n\n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){

            cout << setw(4) <<  matrixTwo[i][j] << "  ";

            }
        cout << endl;
    }

    
    // Displaying the finalMatrix
    cout << "\nHere is the result of A+B: \n\n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){

            cout << setw(4) <<  finalMatrix[i][j] << "  ";

            }
        cout << endl;
    }

    

}

