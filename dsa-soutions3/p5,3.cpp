#include<iostream>
#include <cstdlib> 
#include <ctime> 
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
            array[i][j] = randomNumber(1, 100);
        }
    }
}
void printArray(int array[3][3]) {
    cout << "The following is a 3*3 random matrix: \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %0*d", 2, array[i][j]);
            cout << "    ";
        }cout << endl;
    }
}
void OneDimentionalArray(int arr[3], int sum, short index) {

    arr[index] = sum;

}
void printSumOFcolFromArray(int arr[3]) {
    for (int i = 0; i < 3; i++)
    {
        cout << "col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}
void sumOfcol(int array[3][3], int arr[3]) {
    cout << "the following are the sum of each row in a matrix : \n";
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += array[j][i];
        }
        OneDimentionalArray(arr, sum, i);
        sum = 0;
    }
    printSumOFcolFromArray(arr);
}


int main()
{
    srand((unsigned)time(0));
    int array[3][3];
    int arr[3];
    fillArray(array);
    printArray(array);
    sumOfcol(array, arr);
}
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << "\n";
    }
}

int ColSum(int arr[3][3], short Rows, short ColNumber) {
    int Sum = 0;
    for (short i = 0; i <= Rows - 1; i++) {
        Sum += arr[i][ColNumber];
    }
    return Sum;
}

void SumMatixColsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols) {
    for (short i = 0; i < Cols; i++) {
        arrSum[i] = ColSum(arr, Rows, i);
    }
}

void PrintColsSumArray(int arr[3], short length) {
    cout << "\nThe the following are the sum of each col in the matrix:\n";
    for (short i = 0; i < length; i++) {
        cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arrSum[3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);
    SumMatixColsInArry(arr, arrSum, 3, 3);
    PrintColsSumArray(arrSum, 3);
    system("pause>0");
}
