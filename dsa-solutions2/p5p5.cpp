// p5p5.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	for (int i = num.length()-1; i>=0 ; i--){

		cout << num[i]<<endl;
	}
}
//another way to solve

void PrintDigits(int Number)
{
	int Sum = 0, Remainder = 0; // Initialize variables. Although 'Sum' is declared, it is not used in this function.

	// Continue looping while there are digits left in Number.
	while (Number > 0)
	{
		Remainder = Number % 10; // Extract the last digit of Number.
		Number = Number / 10;    // Remove the last digit from Number.
		cout << Remainder << endl;  // Print the extracted digit on a new line.
	}
}
int main()
{
	reverseInNumber(readnumber());
}
