
#include <iostream>   
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum; 
}
void raedArray(int arr[100], int& length) {
	cout << "enter number of elements : " << endl;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}
void printArray(int arr[100], int length) {
	cout << "array elements :" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
}
short oddChecker(int arr[100], int length) {
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i]%2 != 0) {
			counter++;
		}
	}
	return counter;
}
int main() {
	int arr[100];
	int length;
	raedArray(arr, length);
	printArray(arr, length);
	cout << "Odd number count is : " << oddChecker(arr, length);

}
