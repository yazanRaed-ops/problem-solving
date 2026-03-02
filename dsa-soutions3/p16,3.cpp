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
short countnumber(int array[3][3],int num , short row, short col) {
    int count=0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (array[i][j] == num) {
				count++;
			}
		}
	}
	return	count;
}
bool checkSparce( int array[3][3],short row, short col) {
	if (countnumber(array,0,row,col) >= ((row * col) / 2)) {
		return true ;

	}
	else {
		false;
	}
}
int main()
{
	int array[3][3] = {
	{0, 0, 12},
	{9, 9, 1},
	{0, 0, 9}
	};
	PrintMatrix(array, 3, 3);
	if (checkSparce(array, 3, 3)) {
		cout << "Yes : it is sparce " << endl;
	}
	else {
		cout << "No : it is not sparce " << endl;
	}

}

