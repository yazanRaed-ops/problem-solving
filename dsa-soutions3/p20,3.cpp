
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

bool Isplaindrom(int array[3][3], int row, int col) {
    string pali = "", hold = "";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            pali += to_string(array[i][j]); 
        }
    }

  
    for (int i = pali.length() - 1; i >= 0; i--) {
        hold += pali[i];
    }

    
    if (hold == pali) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int array[3][3] = {
        {77,  5, 12},
        {22, 20,  6},
        {14,  3,  9}
    };

    PrintMatrix(array, 3, 3);

    if (Isplaindrom(array, 3, 3))
        cout << "\nMatrix numbers form a palindrome.\n";
    else
        cout << "\nMatrix numbers do NOT form a palindrome.\n";

    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols / 2; j++) {
            if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int Matrix1[3][3] = {
        {1, 2, 1},
        {5, 5, 5},
        {7, 3, 7}
    };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsPalindromeMatrix(Matrix1, 3, 3))
        cout << "\nYes: Matrix is Palindrome\n";
    else
        cout << "\nNo: Matrix is NOT Palindrome\n";

    system("pause>0");
    return 0;
}
