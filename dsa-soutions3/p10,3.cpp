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
int main()
{
    int array[3][3];
    fillArray(array);
    cout << endl;
    cout << "matrix 1 : " << endl;
    printArray(array);
    cout << endl;

    cout << "sum of matrix is : " << sumOfMatrixElements(array);
        


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
int main() {
    srand((unsigned)time(NULL));
    int Matrix1[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout << "\nSum of Matrix1 is: " << SumOfMatrix(Matrix1, 3, 3);
    system("pause>0");
}


