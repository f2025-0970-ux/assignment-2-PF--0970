#include <iostream>
using namespace std;
void makeSeats(char seats[][20], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            seats[i][j] = 'O';
}
void showSeats(char seats[][20], int rows, int cols) {
    cout << "\nCinema Seat Map:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++)
            cout << seats[i][j] << " ";
        cout << endl;
    }
}
bool bookSeat(char seats[][20], int row, int col, int rows, int cols) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout << "Invalid seat location \n";
        return false;
    }
    if (seats[row][col] == 'X') {
        cout << "Seat already reserved \n";
        return false;
    }
    seats[row][col] = 'X';
    return true;
}

int main() {
    int rows, cols;
    char seats[20][20];

    cout << "Enter number of rows (max 20): ";
       cin >> rows;
    cout << "Enter number of columns (max 20): ";
       cin >> cols;

    makeSeats(seats, rows, cols);
    showSeats(seats, rows, cols);
    char choice;
    do {
        int r, c;
        cout << "\nEnter seat to reserve (row and column): ";
        cin >> r >> c;
        if (bookSeat(seats, r, c, rows, cols))
            cout << "Seat reserved successfully!\n";
        showSeats(seats, rows, cols);
        cout << "Do you want to reserve another seat? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "\nFinal Seat Map:\n";
    showSeats(seats, rows, cols);

    return 0;
}