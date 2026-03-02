#include <iostream>
#include <iomanip>
using namespace std;
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j] << "   ";
		}
		cout << "\n";
	}
}
bool findNumber(int number, int array[3][3], short row, short col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (array[i][j] == number) {
				return true;
			}
		}
	}return false;
}
void findIntersectedNumbers(int array[3][3], int array2[3][3], short row, short col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (findNumber(array[i][j], array2, 3, 3)) {
				cout << setw(6) << array[i][j];
			}
		}
	}
}

int main()
{
	int array[3][3] = {
	{77,  5, 12},
	{22, 20,  1},
	{ 1,  0,  9}
	};

	int array2[3][3] = {
		{ 5, 80, 90},
		{22, 77,  1},
		{10,  8, 33}
	};
	PrintMatrix(array, 3, 3);
	cout << endl;
	PrintMatrix(array2, 3, 3);
	cout << endl;
	cout << "intersected number are " << endl;
	findIntersectedNumbers(array, array2, 3, 3);
}
