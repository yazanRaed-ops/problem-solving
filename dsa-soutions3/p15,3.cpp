#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;



void printArray(int array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %0*d", 1, array[i][j]);
            cout << "    ";
        }
        cout << endl;
    }
}
short countRepitationOfNumber(int array[3][3],int number) {
    short count = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[i][j] == number) {
                count++;
            }
        }
    }return count;
}



int main() {

    int array[3][3] = { {2,4,11}
    ,{9,2,2},{6,5,2} };

    cout << "matrix  : " << endl;
    printArray(array);
    cout << endl;
    cout << "enter number to check retation : " << endl;
    short number;
    cin >> number;
    cout << "\nnumber : " << number << " count in matrix is " << countRepitationOfNumber(array, number);

    return 0;
}
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << "\n";
    }
}

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols) {
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            if (Matrix1[i][j] == Number) {
                NumberCount++;
            }
        }
    }
    return NumberCount;
}

int main() {
    int Matrix1[3][3] = { {9,1,12}, {0,9,1}, {0,9,9} };
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    int Number;
    cout << "\nEnter the number to count in matrix? ";
    cin >> Number;
    cout << "\nNumber " << Number << " count in matrix is " << CountNumberInMatrix(Matrix1, Number, 3, 3);
    system("pause>0");
}
