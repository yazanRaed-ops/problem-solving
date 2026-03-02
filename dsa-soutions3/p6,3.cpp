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
            cout << arr[i][j] << "     ";
        }
        cout << "\n";
    }
}
