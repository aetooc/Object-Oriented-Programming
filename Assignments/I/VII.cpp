
/*

7. Write a program to multiply array A and B of order NxL and LxM

*/

#include <iostream>
using namespace std;
int main()
{
int A[10][10],B[10][10],mul[10][10],rows,cols,p,j,k;

cout<<" Enter the number of printing the rows=";
cin>>rows;
cout<<"Enter the number of printing the column=";
cin>>cols;

cout<<"Enter the first matrix of element=\n";
for(p=0;p < rows; p++){
    for(j=0;j < cols; j++){
        cin>>A[p][j];
    }
    }
cout<<"Enter the second matrix of element=\n";
    for(p=0;p<rows;p++){
        for(j=0;j<cols;j++){
            cin>>B[p][j];
    }
        }
cout<<"multiply of the matrix=\n";
for(p=0;p<rows;p++){
    for(j=0;j<cols;j++){
        mul[p][j]=0;
        for(k=0;k<cols;k++){
            mul[p][j]+=A[p][k]*B[k][j];
        }
    }
}
for(p=0;p<rows;p++){
    for(j=0;j<cols;j++){
        cout<<mul[p][j]<<" ";
    }
        cout<<"\n";
}
return 0;
}