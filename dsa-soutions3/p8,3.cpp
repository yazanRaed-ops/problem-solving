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
void multiplyTwoArrays(int array[3][3], int array2[3][3], int arrResult[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arrResult[i][j] = array[i][j] * array2[i][j];
        }
    }
}
int main()
{
    srand((unsigned)time(0));
    int array[3][3],array2[3][3],arrResult[3][3];
    cout << "matrix 1 " << endl;
    fillArray(array);
    printArray(array);
    cout << "matrix 2 " << endl;
    fillArray(array2);
    printArray(array2);
    cout << "result " << endl;
    multiplyTwoArrays(array, array2, arrResult);
    printArray(arrResult);
    
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

void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);
    MultiplyMatrix(Matrix1, Matrix2, MatrixResults, 3, 3);
    cout << "\nResults:\n";
    PrintMatrix(MatrixResults, 3, 3);
    system("pause>0");
}
