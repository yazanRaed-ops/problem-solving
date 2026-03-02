
#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{

    arrLength++;

    arr[arrLength - 1] = Number;
}
void readarray(int arr[100], int& length) {
    cout << "\nEnter number of elements:\n";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}
void printArray(int arr[100], int length) {
    cout << "array elements " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
}
void raedArray2(int arr[100], int arr2[100], int length, int &length2) {
    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 != 0) {
            AddArrayElement(arr[i], arr2, length2);
        }
       
    }
}
int main()
{
    int arr[100];
    int length = 0;
    readarray(arr, length);
    printArray(arr, length);
    cout << "   " << endl;
    int arr2[100];
    int length2 = 0;
    raedArray2(arr, arr2, length, length2);
    printArray(arr2, length2);
}
