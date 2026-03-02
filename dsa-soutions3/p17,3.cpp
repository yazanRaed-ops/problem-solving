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
int main()
{
	int array[3][3] = {
	{77,  5, 12},
	{22, 20,  1},
	{ 1,  0,  9}
	};
	PrintMatrix(array, 3, 3);
	int number;
	cout << "please enter the number to look for in matrix ? ";
	cin >> number;

	if (findNumber(number,array, 3, 3)) {
		cout << "Yes it is there ." << endl;
	}
	else {
		cout << "No it is not there ." << endl;
	}
}

