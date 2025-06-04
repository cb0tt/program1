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
    int rows, seats;

    cout << "How many seats per row:";
    cin >> seats;

    cout << "How many rows:";
    cin >> rows;

    vector<vector<char>> seating = createSeatingArrangement(rows, seats);
    string seatOrder;

    char flag = 'Y';
    while (flag == 'Y' || flag == 'y') {
        displaySeats(seating, rows, seats);

        int totalSeats = rows * seats;
        int seatStatus = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++) {
                if (seating[i][j] == 'X') {
                    seatStatus++;
                }
            }
        }


        if (seatStatus >= totalSeats) {
            cout << "Event is booked! No more available seats." << endl;
            break; 
        }

        cout << " The amount of seats left is:" << rows * seats - seatStatus << endl;

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

            int seatint = seat - 'A';

            if (seatint < 0 || seatint > seats) {
                throw runtime_error("seat is outside of the range");
            }

            if (seating[row - 1][seatint] == 'X') {
                cout << "You have already booked this seat" << endl;
            } else {
                seating[row - 1][seatint] = 'X';
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

