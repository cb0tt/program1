#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

vector<vector<char>> createSeatingArrangement(int rows, int seatsPerRow) {
    vector<vector<char>> seating(rows, vector<char>(seatsPerRow, '0'));
    return seating;
}

void displaySeats(const vector<vector<char>>& seats, int rows, int seat) {
    cout << "  ";
    for (int j = 0; j < seat; j++) {
        cout << char('A' + j) << " ";
    }
    cout << endl;
    for (int i = 0; i < rows; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < seat; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, columns;

    cout << "How many seats per row:";
    cin >> columns;

    cout << "How many rows:";
    cin >> rows;

    vector<vector<char>> seating = createSeatingArrangement(rows, columns);
    string seatOrder;

    char flag = 'Y';
    while (flag == 'Y' || flag == 'y') {
        displaySeats(seating, rows, columns);

        int totalSeats = rows * columns;
        int bookedSeats = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (seating[i][j] == 'X') {
                    bookedSeats++;
                }
            }
        }

        if (bookedSeats >= totalSeats) {
            cout << "Event is booked! No more available seats." << endl;
            break; 
        }

        cout << " The amount of seats left is:" << totalSeats - bookedSeats << endl;

        try {
            int row;
            char seat;

            cout << " What row would you like? ";
            cin >> row;

            if (row < 1 || row > rows) {
                throw runtime_error("Row is outside of the range");

            }
            cout << " What seat would you like? ";
            cin >> seat;

            seat = toupper(seat);

            int seatIndex = seat - 'A';

            if (seatIndex < 0 || seatIndex >= columns) {
                throw runtime_error("seat is outside of the range");
            }

            if (seating[row - 1][seatIndex] == 'X') {
                cout << "You have already booked this seat" << endl;
            } else {
                seating[row - 1][seatIndex] = 'X';
                seatOrder += to_string(row) + string(1, seat) + " ,";
            }
        } catch (const runtime_error& e) {
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
