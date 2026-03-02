#include<iostream>
#include<string>
#include < iomanip>

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
short sumOfMatrixElements(int array[3][3]) {
    short sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += array[i][j];
        }
    }
    return sum;
}
bool checkequality(int array[3][3], int array2[3][3]) {
    if (sumOfMatrixElements(array) == sumOfMatrixElements(array2)) {
        return true;
    }
    else {
        return false;
    }

}

int main()
{
    srand((unsigned)time(NULL));
    int array[3][3],array2[3][3];
    fillArray(array);
    cout << endl;
    cout << "matrix 1 : " << endl;
    printArray(array);
    cout << endl;
    fillArray(array2);
    cout << endl;
    cout << "matrix 2 : " << endl;
    printArray(array2);
    cout << endl;
    if (checkequality(array, array2)) {
        cout << "yes : matrices are equal .";
    }
    else {
        cout << "no : matrices are not equal .";
    }
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
int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols) {
    int Sum = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            Sum += Matrix1[i][j];
        }
    }
    return Sum;
}
bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols) {
    return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols));
}
int main() {
    srand((unsigned)time(NULL));
    int Matrix1[3][3], Matrix2[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);
    if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
        cout << "\nYES: both matrices are equal.";
    else
        cout << "\nNo: matrices are NOT equal.";
    system("pause>0");
}
