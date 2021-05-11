/*


Q6. The history teacher at your school needs help in grading a True/False test.
    The students’ IDs and test answers are stored in a file. The first entry in the
    file contains answers to the test in the form:
    TFFTFFTTTTFFTFTFTFTT

    Every other entry in the file is the student ID, followed by a blank, followed
    by the student’s responses. For example, the entry:
    ABC54301 TFTFTFTT TFTFTFFTTFT

    indicates that the student ID is ABC54301 and the answer to question 1 is
    True, the answer to question 2 is False, and so on. This student did not
    answer question 9. The exam has 20 questions, and the class has more than
    150 students. Each correct answer is awarded two points, each wrong answer
    gets one point deducted, and no answer gets zero points. Write a program
    that processes the test data. The output should be the student’s ID, followed
    by the answers, followed by the test score, followed by the test grade.
    Assume the following grade scale: 90%–100% , A ; 80%–89.99% , B ;
    70%–79.99% , C ; 60%–69.99% , D ; and 0%–59.99% , F .


*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void Grades(string correctAnswer[20], string studentsAnswers[150][20]);

string line, correctAnswer[20], studentsAnswers[150][20], studentID[150];
string grades[150];
char ans;
int x = 0, totalMarks[150]; 
const int numOfStudents = 150, numOfQuestions = 20;
double percentage = 0, marks = 0, percent[150];

int main(){

    string fileName = "answers.txt";
    char choice;
    cout << "Do you want to change the default file (Y/N): ";
    cin >> choice;
    cin.ignore();

    if (choice == 'Y' || choice == 'y' ){
        cout << "Enter File Name: ";
        getline(cin, fileName);
    }

    ifstream fin;
    fin.open(fileName);

    if (fin){

        while(fin >> ans){
                correctAnswer[x++] = ans;
                if (x == 20)
                    break;
        }

        for(int i = 0; i < numOfStudents; i++){
            fin >> studentID[i];
            fin.get();
            for (int j = 0; j < numOfQuestions; j++)
                studentsAnswers[i][j] = fin.get();
        }
        
        fin.close();

        Grades(correctAnswer, studentsAnswers);
    }

    else
        // return false;
        // cout << "FileNotFoundError: No such file or directory: '" << fileName << "' " << endl;
        cout << "\n---------------------------------------------------------------------------\nFileNotFoundError                         Traceback (most recent call last) \n<ic++-input-1-4234adaa1c35> in <module>()\n ----> 23 fin.open('" << fileName << "');\n\nFileNotFoundError: [Errno 2] No such file or directory: '" << fileName << "' " << endl << endl;
}

void Grades( string correctAnswer[20], string studentsAnswers[150][20]){

    for(int i = 0; i < numOfStudents; i++){
        for(int j = 0; j < numOfQuestions; j++){
            if ( correctAnswer[j] == studentsAnswers[i][j] ){
                marks += 2;
            }
            else if (studentsAnswers[i][j] == " ")
                marks += 0;
            else
                marks--;
        }

        totalMarks[i] = marks;
        percentage = (marks / 40) * 100;
        percent[i] = percentage;

        if (percentage >= 90)
            grades[i] = 'A';
        else if(percentage >= 80 && percentage <= 89.99 )
            grades[i] = 'B';
        else if(percentage >= 70 && percentage <= 79.99 )
            grades[i] = 'C';
        else if(percentage >= 60 && percentage <= 69.99 )
            grades[i] = 'D';
        else 
            grades[i] = 'F';

        marks = 0;
        percentage = 0;
        
    }

    for(int i = 0; i < numOfStudents; i++){

        cout << "-*-*-*--*-*-*--*-*-*--*-*-*-\n\nStudent No: " << i + 1;
        cout << "\nID: " << studentID[i] << "\nAnswers: ";
        for(int j = 0; j < numOfQuestions; j++){

            cout << studentsAnswers[i][j]; 
        }
        cout << "\nTest Score: " << totalMarks[i]
             << "\nPercentage: " << percent[i]
             << "%\nGrade: " << grades[i] << endl
             << endl;
    }


}
