
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
short readNumofCheckFrequancy() {
	short num;
	do {
		cout << "enter number between 0-9" << endl;
		cin >> num;
	} while (num < 0 || num > 9);
	return num;

}
void reverseInNumber(int number , short num2 ) {
	string num = to_string(number);
	int sum = 0;
	
	for (int i = num.length() - 1; i >= 0; i--) {
		if (num2 == int(num[i] - '0')) {
			sum += 1;
		}

	}cout << "the number of frequancy is " << sum;
}
int main() {
	reverseInNumber(readnumber(), readNumofCheckFrequancy());
}