/*

1. Write a menu driven C++ program to do following operation on two dimensional array A of size m x n. You should use user-defined functions which accept 2-D array A, and its size m and n as arguments. The options are:

- To input elements into matrix of size m x n
- To display elements of matrix of size m x n
- Sum of all elements of matrix of size m x n
- To display row-wise sum of matrix of size m x n
- To display column-wise sum of matrix of size m x n
- To create transpose of matrix B of size n x m

*/

#include <iostream>
#include <iomanip>

using namespace std;

int Input(int A[][50], int m, int n );
int Display(int A[][50], int m, int n );
int Sum(int A[][50], int m, int n );
int SumOfRows(int A[][50], int m, int n );
int SumOfCols(int A[][50], int m, int n );
int Transpose(int A[][50], int m, int n );

int main(){
    int A[50][50],m, n;
    string choice;
    cout << "Enter the Rows and Columns: ";
    cin >> m >> n;

    // Assigning the Matrix with value '0'
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = 0;
        }
    }

    while(true){
        cout << "\nPress any Number: \n";
        cout << "1. Input the Elements.\n2. Display the Elements.\n3. Sum of All Elements of Matrix.\n4. Row wise Sum.\n5. Column wise Sum\n6. Transpose of B\n7. Exit.\n>>>> ";
        cin >> choice;
        if(choice == "1"){
            Input(A,m,n);
        }
        else if(choice == "2"){
            Display(A,m,n);
        }
        else if(choice == "3"){
            Sum(A, m, n);
        }
        else if(choice == "4"){
            SumOfRows(A, m, n);
        }
        else if(choice == "5"){
            SumOfCols(A, m, n);
        }
        else if(choice == "6"){
            Transpose(A, m, n);
        }
        else if(choice == "Exit" || choice == "exit" || choice == "E" || choice == "e" || choice == "7")
            break;

    }
}

int Input(int A[][50], int m, int n ){

    //Asking user to input the elements in the Matrix A
    cout << "Enter the elements into the matrix A: \n";
    for (int i = 0; i < m; i++ ){
        for (int j = 0; j < n; j++){
             cout << "Enter the element on A[" << 1 + i << "," << 1 + j << "]: ";
            cin >> A[i][j];
        }
        cout << endl << endl;
    }
    cout << "Done!!!\n\n"; 
return 0;
}

int Display(int A[][50], int m, int n ){

    cout << "\n\nMatrix A:\n\n";
    // Displaying the matrix
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            cout << setw(4) <<  A[i][j] << "\t";

        }
        cout << endl;
    }
return 0;
}

int Sum(int A[][50], int m, int n ){

    int sum = 0;
    // Calculating the sum of the elements of the Matrix
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            sum += A[i][j];
        }
    }

    cout <<"\n\n The Sum of the elements of the Matrix A = " << sum << endl;
    
}

int SumOfRows(int A[][50], int m, int n ){
    int sumOfRow = 0;

    // Calculating the rows wise sum
    cout << endl;
    for(int i = 0; i < m; i++ ){
        for(int j = 0; j < n; j++){
            sumOfRow += A[i][j];
        }
        cout << "The Sum of the Row no." << 1 + i << " is = " << sumOfRow;
        sumOfRow = 0;
        cout << endl;
    }
return 0;
}

int SumOfCols(int A[][50], int m, int n ){
    int x = 0, sumOfCols = 0;

    // Calculating the Columns wise sum
    cout << endl;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            sumOfCols += A[i][j];
        }
        cout << "The Sum of the Column no." << 1 + j << " is = " << sumOfCols;
        sumOfCols = 0;
        cout<<endl;
    }
return 0;

}

int Transpose(int A[][50], int m, int n ){
    int Transpose[50][50];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
         Transpose[j][i] = A[i][j];
      }

   // Printing the transpose
   cout << "\nTranspose of Matrix: " << endl;
   for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
         cout << " " << Transpose[i][j];
         if (j == n - 1)
            cout << endl
             << endl;
      }
}
