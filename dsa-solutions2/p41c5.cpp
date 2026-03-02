// p39c5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


//void AddArrayElement(int Number, int arr[100], int& arrLength)
//{
//
//    arrLength++;
//
//    arr[arrLength - 1] = Number;
//}
void readarray(int arr[100], int& length) {
    cout << "\nEnter number of elements:\n";
    cin >> length;
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[100], int length) {
    cout << "array elements " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
}
bool Ispalindrome(int arr[100], int length) {
    for (int i = 0; i < length; i++)
    {
        if (arr[i] != arr[length -i- 1]) {
            
            return false;
        }

    }return true;
}


int main()
{
    int arr[100];
    int length = 0;
    readarray(arr, length);
    cout << "\nArray Elements:\n";
    printArray(arr, length);

    
    if (Ispalindrome(arr, length))
        cout << "\nYes array is Palindrome\n";
    else
        cout << "\nNO array is NOT Palindrome\n";

    return 0; 
    
    
    
}