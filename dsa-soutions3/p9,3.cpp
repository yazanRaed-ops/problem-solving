#include <iostream>
using namespace std;
int randomNumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}
void fillArray(int array[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = randomNumber(1, 10);
        }
    }
}
void printArray(int array[3][3]) {

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %0*d", 2, array[i][j]);
            cout << "    ";
        }cout << endl;
    }
}
void middleRow(int array[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        if (i == 1) {
        for (int j = 0; j < 3; j++){
        
            printf(" %0*d", 2, array[i][j]);
            cout << "    ";
        }cout << endl;

        }
        
    }
}
void middlecol(int array[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        
            for (int j = 0; j < 3; j++) {
                if (j == 1) {
                    printf(" %0*d", 2, array[i][j]);
                cout << "    ";

                }
            }
    }
}
int main()
{
    int array[3][3];
    fillArray(array);
    cout << "matrix 1 :" << endl;
    printArray(array);
    cout << "middle row of the matrix is  :" << endl;
    middleRow(array);
    cout << "middle col of the matrix is  :" << endl;
    middlecol(array);


}
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            printf(" %0*d   ", 2, arr[i][j]);
        }
        cout << "\n";
    }
}

void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols) {
    short MiddleRow = Rows / 2;
    for (short j = 0; j < Cols; j++) {
        printf(" %0*d   ", 2, arr[MiddleRow][j]);
    }
    cout << "\n";
}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols) {
    short MiddleCol = Cols / 2;
    for (short i = 0; i < Rows; i++) {
        printf(" %0*d   ", 2, arr[i][MiddleCol]);
    }
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));
    int Matrix1[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout << "\nMiddle Row of Matrix1 is:\n";
    PrintMiddleRowOfMatrix(Matrix1, 3, 3);
    cout << "\nMiddle Col of Matrix1 is:\n";
    PrintMiddleColOfMatrix(Matrix1, 3, 3);
    system("pause>0");
}

