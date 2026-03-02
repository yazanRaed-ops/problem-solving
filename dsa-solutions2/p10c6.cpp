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
void palindromescheck(int number) {
	string num = to_string(number);
	string holder = "";
	for (int i = num.length()-1; i>=0; i--)
	{
		holder += num[i];
		
		
	}if (holder == num) {
		cout << num << "  is a palindrome number" << endl;
	}
	else {
		cout << "it is not" << endl;
	}
}
int main() {
	palindromescheck(readnumber());
}
