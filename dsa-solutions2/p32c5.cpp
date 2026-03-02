
#include <iostream>
using namespace std;
int randomnumber(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void array1(int arr[100], int& length) {
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        arr[i] = randomnumber(1, 100);

    }cout << endl;
}
void array2copy1reverse(int arr[100], int arr2[100], int arrLength) {
    int j = 0;
    cout << "array after reverse :" << endl;
    for (int i = arrLength - 1; i >= 0; i--)
    {
        arr2[j] = arr[i];
        j++;
       
    }cout << endl;
}
int main()
{
    int arr[100];
    int length=ReadPositiveNumber("enter positive number : ");
    array1(arr, length);
    PrintArray(arr, length);
    int arr2[100];
    array2copy1reverse(arr, arr2, length);
    PrintArray(arr2, length);


}
