/*

4. Write a user defined function named Upper-half() which takes a two dimensional array A, with size N rows and N columns as argument and prints the upper half of the array.

    e.g.,
    2 3 1 5 0                              2 3 1 5 0
    7 1 5 3 1                                1 5 3 1
    2 5 7 8 1   Output will be:                1 7 8
    0 1 5 0 1                                    0 1
    3 4 9 1 5                                      5

*/

#include <iostream>
#include <iomanip>

using namespace std;

// Delcaring i and j variables globaly
int i,j;
string space = "\t";

// Function ProtoType
int UpperHalf(int A[][20]);

int main(){
    int A[20][20];
    UpperHalf(A);

}

int UpperHalf(int A[][20]){
    int temp = 0;
    cout << "Enter: ";
    cin >> temp;
    const int userInput = temp;

    // Asking values from user
    for (int x = 0; x < userInput; x++ ){
        for (int y = 0; y < userInput; y++){
             cout << "Enter the element on A[" << 1 + x << "," << 1 + y << "]: ";
            cin >> A[x][y];
        }
    }

    cout << "\nMatrix A:\n\n";

    for(int x = 0; x < userInput; x++){
        for(int y = 0; y < userInput; y++){

            cout << setw(4) <<  A[x][y] << "\t";

            }
        cout << endl;
    }

    // Upper Half of Matrix
    cout << "\n\nResult:\n\n";
    for (i = 0; i < userInput; i++){
        for(j = i; j < userInput; j++){
            cout << setw(4) << A[i][j] << "\t";
        }
        cout << endl;
        cout << space;
        space += "\t";

    }

}