// p3c5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
float readnumbner() {
    float number;
    do {
        cout << "enter a positive number " << endl;
        cin >> number;
    } while (number < 0);
    return number;
}
int checkperfectnumber(float number) {
    int sum = 0;
    int m = floor(number);
    for (int i = 1; i < m; i++)
    {
        if (m % i == 0) {
            sum += i;
        }
    }return sum;
}
void printresult(float number) {
    if (checkperfectnumber(number) != (int)floor(number)){
        cout << number << " is not a perfecct numbre" << endl;
    }
    else {
        cout << number << " is perfect ";
    }
}
int main()
{
    printresult(readnumbner());
}
