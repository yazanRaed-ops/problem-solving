
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
            array[i][j] = randomNumber(1,100);
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
int main()
{
    srand((unsigned)time(0));
    int array[3][3];
    fillArray(array);
    printArray(array);
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

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\n The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);
    system("pause>0");
}

