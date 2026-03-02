#include<iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;
int randomNumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}
void fillArray(int array[3][3]) {
    short increment = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            increment++;
            array[i][j] = increment;
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
void transposedMatrix(int array[3][3], int arr2[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr2[i][j] = array[j][i];
        }
    }
}




int main()
{
    srand((unsigned)time(0));
    int array[3][3],arr2[3][3];

    fillArray(array);
    cout << "The following is a 3*3 ordered matrix: \n";
    printArray(array);
    transposedMatrix(array, arr2);
    cout << "The following is a 3*3 transposed matrix: \n";
    printArray(arr2);


}
#include <iostream>
#include <string>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols) {
    short Counter = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            Counter++;
            arr[i][j] = Counter;
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << " " << arr[i][j] << "     ";
        }
        cout << "\n";
    }
}

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arrTransposed[i][j] = arr[j][i];
        }
    }
}

int main() {
    int arr[3][3], arrTransposed[3][3];
    FillMatrixWithOrderedNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintMatrix(arr, 3, 3);
    TransposeMatrix(arr, arrTransposed, 3, 3);
    cout << "\n\nThe following is the transposed matrix:\n";
    PrintMatrix(arrTransposed, 3, 3);
    system("pause>0");
}
