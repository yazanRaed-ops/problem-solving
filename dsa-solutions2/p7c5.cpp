
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
	cout << "the number in reverse is : " << endl;
	for (int i = num.length() - 1; i >= 0; i--) {

		cout << int(num[i]-'0');
		//or : cout <<num[i] ;
	}
}
int ReverseNumber(int Number)
{
	int Remainder = 0;  // Variable to store the last digit extracted from the number.
	int Number2 = 0;    // Variable to accumulate the reversed number.

	// Loop until there are no more digits left in Number.
	while (Number > 0)
	{
		Remainder = Number % 10;   // Extract the last digit of Number.
		Number = Number / 10;      // Remove the last digit from Number.
		Number2 = Number2 * 10 + Remainder;  // Append the digit to Number2 by shifting left and adding Remainder.
	}

	return Number2;  // Return the reversed number.
}
int main()
{
	reverseInNumber(readnumber());
}
