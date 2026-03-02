// primenumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum PrimNotPrime { prime = 1, notprime = 0 };
float readpositivenumber(string message) {
    float number;
    do {
        cout << message << endl;
        cin >> number;
    } while (number < 0);
    return number;
}
PrimNotPrime checkPrime(int number) {
    int num = round(number);
    for (int i = 2; i <=sqrt(num); i++)
    {
        if (num % i == 0) {
            return PrimNotPrime::notprime;
        }

    }
    return PrimNotPrime::prime;
    
}
void printnumbertype(int number) {
    if (checkPrime(number) == PrimNotPrime::prime) {
        cout << " the number : " << number << " is prime";

    }
    else {
        cout << " the number : " << number << " is not prime";
    }
}
int main()
{
   printnumbertype(readpositivenumber("PLZ ENTER POSITIVE NUMBER : "));
    
}
