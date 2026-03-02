// p36c5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int ReadNumber()
{
    int Number;  // Variable to store the user's input.
    cout << "\nPlease enter a number? ";
    cin >> Number;  // Read the number from the user.
    return Number;  // Return the entered number.
}
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    
    arrLength++;
  
    arr[arrLength - 1] = Number;
}
void raedarray(int arr[100], int& length) {
    bool choose;

    do {
        
        
        AddArrayElement(ReadNumber(), arr, length);
        cout << "do u want to add more number ? [0]:no , [1]:yes? ";
        cin >> choose;
        cout << endl;

    } while (choose);

}
void printarray(int arr[100], int length) {
    cout << "array length " << length << endl;
    cout << "array elements :";

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
}
int main()
{
    int arr[100];
    int length=0;
    raedarray(arr, length);
    printarray(arr, length);
}
