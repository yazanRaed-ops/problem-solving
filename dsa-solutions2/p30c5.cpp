
#include <iostream>
using namespace std;
int randomnumber(int from , int to) {
	int number = rand() % (to - from + 1) + from;
	return number;
}
int Arraylength() {
	int length;
	do {
		cout << "enter array length : " << endl;
		cin >> length;
	} while (length < 0);
	return length;
}
void array1(int arr[100], int& length) {
	for (int i = 0; i < length; i++)
	{
		arr[i] = randomnumber(1, 100);
	}
}
void array2(int arr2[100], int length) {
	for (int i = 0; i < length; i++)
	{
		arr2[i] = randomnumber(1, 100);
	}
}
void printarray(int array[100],int length) {
	cout << "array element are : " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}cout << endl;
}
void sumOfarray(int arr[100], int arr2[100], int sumArray[100], int length) {
	cout << "sum of array1 and array2 elements are : " << endl;
	for (int i = 0; i < length; i++)
	{
		sumArray[i] = arr[i] + arr2[i];
		cout << sumArray[i] << " ";
	}
}
int main()
{
	
}
