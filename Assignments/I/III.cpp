/*

3. Write a user-defined function in C++ to display the multiplication of row element of two-dimensional array A[4][6] containing integer.

*/

#include <iostream>

using namespace std;

int ProductOfRows(int A[4][6]);

int rowsProduct = 1, counter = 0;

int main(){
    int A[4][6];
    cout << "Enter the elements of the array A:\n";

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            cout << "Enter the element on A[" << 1 + i << "," << 1 + j << "]: ";
            cin >> A[i][j];
        }
    }

    ProductOfRows(A);
}

int ProductOfRows(int A[4][6]){
    cout << endl;
    cout << "\nMatrix A:\n\n";

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){

            cout << A[i][j] << "  ";

            }
        cout << endl;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){

            rowsProduct *= A[i][j];
        }
        counter++;
        cout << "The Product of the Row no." << counter << " is equal to = " << rowsProduct << endl;
        rowsProduct = 1;
    }
}