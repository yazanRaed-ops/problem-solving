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
short maxNumInMatrix(int array[3][3], short row, short col) {
	short number = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (array[i][j] > number) {
				number = array[i][j];
			}
		}
	}return number;
}
short minNumInMatrix(int array[3][3], short row, short col) {
	short minNumber=array[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (array[i][j] <= minNumber) {
				minNumber = array[i][j];
			}
		}
	}return minNumber;
}
int main()
{
	int array[3][3] = {
	{77,  5, 12},
	{22, 20,  6},
	{14,  3,  9}
	};
	PrintMatrix(array, 3, 3);
	cout << endl;
	cout << "min number is : " << endl;
	cout<<minNumInMatrix(array, 3, 3);
	cout << endl;
	cout << "max number is : " << endl;
	cout<<maxNumInMatrix(array, 3, 3);
   
}

