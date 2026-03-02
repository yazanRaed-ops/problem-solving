// p6c5.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	int sum = 0;
	for (int i = num.length()-1; i >= 0; i--) {

		sum += int(num[i]-'0');
	}cout << sum;
}
int main()
{
	reverseInNumber(readnumber());
}
