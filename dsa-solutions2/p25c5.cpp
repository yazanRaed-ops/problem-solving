#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
int readPositiveNumber() {
    int number;
    do {
        cout << "Please enter a positive number: ";
        cin >> number;
    } while (number < 0);
    return number;
}
void fillArray(int arr[100], int& length) {
    cout << "Enter number of elements in the array:\n";
    length = readPositiveNumber();

    for (int i = 0; i < length; i++) {
        arr[i] = RandomNumber(1, 100);

    }
}
void PrintArray(int arr[100], int arrLength)

{
    cout << "Array Elements : ";

    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}
int minnumArray(int arr[100], int length) {
    int min = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i]<min) {
            min = arr[i];
        }
    }return  min;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int length;
    fillArray(arr, length);
    PrintArray(arr, length);
    cout << "min number is : " << minnumArray(arr, length);
}
