/*

Q 13.   Write a program to calculate students’ average test scores and their grades.
        You may assume the following input data:
        
        Johnson 85 83 77 91 76
        Aniston 80 90 95 93 48
        Cooper 78 81 11 90 73
        Gupta 92 83 30 69 87
        Blair 23 45 96 38 59
        Clark 60 85 45 39 67
        Kennedy 77 31 52 74 83
        Bronson 93 94 89 77 97
        Sunny 79 85 28 93 82
        Smith 85 72 49 75 63

        Use three arrays: a one-dimensional array to store the students’ names, a
        (parallel) two-dimensional array to store the test scores, and a parallel one-
        dimensional array to store grades. Your program must contain at least the
        following functions: a function to read and store data into two arrays, a
        function to calculate the average test score and grade, and a function to
        output the results. Have your program also output the class average.

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void TotalStudents();
void ReadData( string studentNames[200], int studentTestScore[][200], string studentGrades[200] );
void DisplayResult(string studentNames[200], int studentTestScore[][200], string studentGrades[200]);
void Grades(int studentTestScore[][200], string studentGrades[200]);

string studentNames[200];
int studentTestScore[200][200];
string studentGrades[200];

double classAverage = 0, totalMarks = 0;
int totalStudents = 0, totalSubs = 0;

int main(){
    TotalStudents();
    ReadData(studentNames, studentTestScore, studentGrades);
    Grades(studentTestScore, studentGrades);
    DisplayResult(studentNames, studentTestScore, studentGrades);
}

void TotalStudents(){
    
    string line;
    ifstream fin;
    fin.open("input-data.txt");

    while(getline(fin, line)){
        totalStudents++;
    }

    for(int i = 0; line[i] != '\0'; i++){
        if (line[i] == ' ')
        {
            totalSubs++;
        } 		
    }

    fin.close();
}

void ReadData( string studentNames[200], int studentTestScore[][200], string studentGrades[200] ){

    // Opening file
    ifstream fin;
    fin.open("input-data.txt");
    
    // Storing data in arrays
    for(int i = 0; i < totalStudents; i++){

        fin >> studentNames[i];
        fin.get();
        for (int j = 0; j < totalSubs; j++ )
            fin >> studentTestScore[i][j];
    }

    
    fin.close();

}

void Grades(int studentTestScore[][200], string studentGrades[200]){

    double classTotal = 0, totalMarks = 0, percentage = 0; 
    for(int i = 0; i < totalStudents; i++){
        for (int j = 0; j < totalSubs; j++){
            totalMarks += studentTestScore[i][j];
        }
        percentage = totalMarks / totalSubs;
        classTotal += percentage;


        if (percentage >= 90)
            studentGrades[i] = 'A';
        else if(percentage >= 80 && percentage <= 89.99 )
            studentGrades[i] = 'B';
        else if(percentage >= 70 && percentage <= 79.99 )
            studentGrades[i] = 'C';
        else if(percentage >= 60 && percentage <= 69.99 )
            studentGrades[i] = 'D';
        else 
            studentGrades[i] = 'F';
        
        totalMarks = 0;
        percentage = 0;
    }

    classAverage = classTotal / totalStudents;

}

void DisplayResult(string studentNames[200], int studentTestScore[][200], string studentGrades[200]){

    double total = 0;
    cout << "\n\n Students      |       Marks:\n\n-*-*-*--*-*-*--*-*-*--*-*-*-\n\n";
    for(int i = 0; i < totalStudents; i++){
        cout << studentNames[i] << " = ";
        for(int j = 0; j < totalSubs; j++){
            cout << studentTestScore[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    for(int i = 0; i < totalStudents; i++){
        cout << "Student Name: " << studentNames[i] << "\nGrade: " << studentGrades[i] 
             << "\nAverage Score: ";
        for(int j = 0; j < totalSubs; j++){
            total += studentTestScore[i][j];
        }
        
        cout << total / totalSubs << endl;
        cout << "\n-*-*-*--*-*-*--*-*-*--*-*-*-\n" << endl;
        total = 0;
        
    }

    cout << "\nClass Average = " << classAverage << endl;


}