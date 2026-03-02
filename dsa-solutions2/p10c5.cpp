// p10c5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;
int readnumber() {
	int number;
	do {
		cout << "enter positive number" << endl;
		cin >> number;
	} while (number < 0);
	return number;
}
void reverseInNumber(int number) {
	string num = to_string(number);
	for (int i = 0; i < num.length();i++) {

		cout << num[i] << endl;
	}
}
int main()
{
	reverseInNumber(readnumber());
}
