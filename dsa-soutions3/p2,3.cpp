
#include<iostream>
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
void sumOfRow(int array[3][3]) {
    cout << "the following are the sum of each row in a matrix : \n";
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += array[i][j];
        }
        cout << "Row " << i + 1 << " Sum = " << sum << endl;
        sum = 0;
    }
}
int main()
{
    srand((unsigned)time(0));
    int array[3][3];
    fillArray(array);
    printArray(array);
    sumOfRow(array);
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

int RowSum(int arr[3][3], short RowNumber, short Cols) {
    int Sum = 0;
    for (short j = 0; j <= Cols - 1; j++) {
        Sum += arr[RowNumber][j];
    }
    return Sum;
}

void PrintEachRowSum(int arr[3][3], short Rows, short Cols) {
    cout << "\nThe the following are the sum of each row in the matrix:\n";
    for (short i = 0; i < Rows; i++) {
        cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);
    PrintEachRowSum(arr, 3, 3);
    system("pause>0");
}
