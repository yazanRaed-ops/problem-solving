// p2c5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum primornot{prim =1,notprim=0};
float readnumber() {
	float number;
	do {
		cout << "plz enter positive number\n";
		cin >> number;
	} while (number < 0);
	return number;
}
 primornot primechecker(int i) {
	 
	for (int j = 2; j <= sqrt(floor(i)); j++)
	{
		if (i % j == 0) {
			return primornot::notprim;
		}

	}return primornot::prim;

}

void printtheprimenumbers(float number) {

	for (int i = 1; i <= number; i++) {
		if (primechecker(i) == primornot::prim) {
			cout << i << endl;
		}
	}
	

}
int main()
{ 
	printtheprimenumbers(readnumber());
}
