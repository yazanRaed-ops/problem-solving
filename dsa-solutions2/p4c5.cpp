// p4c5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using   namespace std;
int readnumbner() {
    int number;
    do {
        cout << "enter a positive number " << endl;
        cin >> number;
    } while (number < 0);
    return number;
}
bool checkperfectnumber(int number) {
    int sum = 0;
    
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0) {
            sum += i;
        }
    }return number==sum;
}
void printAllPerfectNumIn(int number) {
    for (int i = 1; i <= number; i++) {
        if (checkperfectnumber(i)) {
            cout << i << endl;
        }
    }
    
}
int main()
{
    printAllPerfectNumIn(readnumbner());
}

