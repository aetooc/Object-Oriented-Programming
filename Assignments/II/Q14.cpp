/*

Q 14.   (Airplane Seating Assignment) Write a program that can be used to
        assign seats for a commercial airplane. The airplane has 13 rows, with six
        seats in each row. Rows 1 and 2 are first class, rows 3 through 7 are business
        class, and rows 8 through 13 are economy class. Your program must prompt
        the user to enter the following information:
        a. Ticket type (first class, business class, or economy class)
        b. Desired seat

                    A       B       C       D       E       F

        Row 1  :    X       *       *       *       *       *    

        Row 2  :    *       X       *       *       *       *    

        Row 3  :    *       *       *       *       *       X    

        Row 4  :    *       *       *       *       *       *    

        Row 5  :    *       *       X       *       *       *    

        Row 6  :    *       *       *       *       X       *    

        Row 7  :    *       *       *       *       *       *    

        Row 8  :    *       *       *       *       *       *    

        Row 9  :    *       X       *       *       *       *    

        Row 10 :    *       *       *       *       *       *    

        Row 11 :    *       *       *       *       *       *    

        Row 12 :    *       *       *       *       X       *    

        Row 13 :    *       *       *       *       *       * 

        Here, * indicates that the seat is available; X indicates that the seat is
        occupied. Make this a menu-driven program; show the user’s choices and
        allow the user to make the appropriate choices.



*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void AirplaneSeating(string airplaneSeating[13][6]);

string airplaneSeating[13][6];
const int totalRows = 13, totalSeats = 6;

int main(){
    char temp;
    for (int i = 0; i < totalRows; i++){
        for(int j = 0; j < totalSeats; j++){

            airplaneSeating[i][j] = "*";
        }
    }
    do{
        AirplaneSeating(airplaneSeating);
        cout << "Do you want to book a seat? ( Y/N ): ";
        cin >> temp;
        if (temp == 'N' || temp == 'n'){
            cout << "\nThanks for choosing our airline!\nHave a good day!\n\n";
            break;
        }
    }
    while(true);

    
}

void AirplaneSeating(string airplaneSeating[13][6]){

        char choice, seat;
        int row, nseat;

        cout << "\nRows 1 and 2 are first class (F).\nRows 3 through 7 are business class (B).\nRows 8 through 13 are economy class (E).\n\nEnter the Ticket Type First, Business, Economic (F/B/E): ";
        cin >> choice;
        cout << "Enter the Desired Row ( 1 to 13 ): ";
        cin >> row;
        cout << "Enter the Desired Seat ( A to F ): ";
        cin >> seat;

        if (seat == 'A') nseat = 0;
        else if (seat == 'B') nseat = 1;
        else if (seat == 'C') nseat = 2;
        else if (seat == 'D') nseat = 3;
        else if (seat == 'E') nseat = 4;
        else if (seat == 'F') nseat = 5; 

        if (choice == 'F' && (row > 0 && row < 3)){
            airplaneSeating[row - 1][nseat] = "X";
        }

        else if (choice == 'B' && (row > 2 && row < 8)){
            airplaneSeating[row - 1][nseat] = "X";
        }

        else if (choice == 'E' && (row > 7 && row < 14)){
            airplaneSeating[row - 1][nseat] = "X";
        }

        cout <<"\n            A       B       C       D       E       F\n\n";
        for (int i = 0; i < totalRows; i++){

            cout <<  "Row " << left << setw(3) << i + 1  << ": ";
            for(int j = 0; j < totalSeats; j++){

                cout.width(4);
                cout << right << airplaneSeating[i][j] << "    ";
            }
            cout << endl << endl;
        }
    
}