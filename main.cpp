/*
Colin Bottrill
Professor Vermilyer
Program 1

    This program is an airplane seating chart that allows the user to updated their desired amount of seats and rows,
    and allows them to book seats on the plane and display the updated seating chart.


*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

 vector<vector<char>> createSeatingArrangement(int rows, int seatsPerRow) // function return either rows/seats
 {
    vector<vector<char>> seating(rows, vector<char>(seatsPerRow, '0')); // 2d vector of chars
    return seating;

}

 void displaySeats(const vector<vector<char>>& seats, int rows, int seat) /* does not return any value because void, const is a function parameter 2d vector of chars, int rows/seats
 also a function parameter */
 {
     cout << "  ";
     for (int j = 0; j < seat; j++) { // loop counter
        cout << char('A' + j) << " "; // int to character
    }
    cout << endl;
    for (int i = 0; i < rows; i++) { // goes through each start from row from 0
        cout << i + 1 << " ";   // printing number or rows at the start, column header
        for (int j = 0; j < seat; j++) { // goes through each seat from 0
            cout << seats[i][j] << " ";  // first loop is row, one row at a time, second row is seats outputing the seat at i,j;
        }
        cout << endl;
 } // making sure that seats/vector cant be modified, passing by ref &
 }





int main()
{

    int rows, seats;



    cout << "How many seats per row:"; // lets user enter number
    cin >> seats; //input

    cout << "How many rows:"; // lets user enter number
    cin >> rows; //input



    vector<vector<char>> seating = createSeatingArrangement(rows, seats); /* calls the create seating method from the main method
    passing rows in seats, taking rows and seats creating the vector and int it with all zeros and return it. */
    string seatOrder; // keep track of the order of selection



    char flag = 'Y';
    while (flag== 'Y' || flag == 'y')  {
        displaySeats(seating, rows, seats); // pass by ref


    int seatStatus=0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < seats; j++){
            if (seating[i][j] == 'X'){ // check seat status
            seatStatus++; // increment count


            }
        }
    }

    cout << " The amount of seats left is:" << rows * seats - seatStatus<< endl; // number * number subtracted by 1



        try {


        int row;
        char seat;

            cout << " What row would you like? ";
            cin >> row;

            if (row < 1 || row >rows){
                throw runtime_error("Row is outside of the range");
            }
            cout << " What seat would you like? ";
            cin >> seat;

            seat = toupper(seat); // makes user input uppercase automatically

            int seatint = seat - 'A'; // converting char seat into an integer number

            if (seatint < 0 || seatint > seats){
                throw runtime_error("seat is outside of the range");
            }

             seating[row -1][seatint] = 'X';// mark as taken

             seatOrder += to_string(row) + string(1,seat) + " ,"; // to_string is the number row, 1,seat is the letter of seat
        } catch(const runtime_error& e){

        cout << " Error!" << e.what() << endl;
        }



        cout << "Want to book another seat? (Y/N): ";
        cin >> flag;

        cout << endl;
        cout << "X = Taken, 0 = Open" << endl;

        cout << "Order of seats taken:" << seatOrder << endl;

        }







 return 0;

}

