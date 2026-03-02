// p39c5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void AddArrayElement(int Number, int arr[100], int& arrLength)
{

    arrLength++;

    arr[arrLength - 1] = Number;
}
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

void raedArray2(int arr[100], int arr2[100], int length, int& length2) {
    for (int i = 0; i < length; i++) {
        int count = 0;
        bool flag = false;


        for (int j = i; j < length; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }if (count > 1) {
            flag = true;
        }if (flag) { continue; }
        if (flag == false) {
            AddArrayElement(arr[i], arr2, length2);
        }
        //or better solution
       //for (int i = 0; i < length; i++) {
       //    bool alreadyExists = false;
       //
       //    // Check if arr[i] is already in arr2
       //    for (int j = 0; j < length2; j++) {
       //        if (arr[i] == arr2[j]) {
       //            alreadyExists = true;
       //            break;
       //        }
       //    }
       //
       //    if (!alreadyExists) {
       //        AddArrayElement(arr[i], arr2, length2);
       //    }
       //}



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