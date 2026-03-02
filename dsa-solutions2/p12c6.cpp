// p12c6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int raednumber() {
    int number;
    do {
        cout << "plz enter positive number" << endl;
        cin >> number;

    } while (number < 0);
    return number;
}
void printnumber(int number) {
    for (int i = number; i>0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }cout << endl;
    }
}
int main()
{
    printnumber(raednumber());
}
