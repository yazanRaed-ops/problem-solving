// P1C5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void tableheeader() {
	cout << "\n\n\t\t\tmultiplication Table from 1 to 10\n\n\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
		
	}cout << endl;
	cout << "----------------------------------------------------------------------------------"; 
	
}
string coulmnspace(int i ) {
	if (i < 10) {
		return "   |";
	}
	else {
		return "  |";
	}
}
void printtable() {
	tableheeader();
	cout << endl;
	for (int i = 1; i <= 10; i++) {

		cout << i << coulmnspace(i)<<"\t";


		for (int j = 1; j <= 10; j++) {

			cout << j * i << "\t";


		}cout << endl;

	}
}
int main()
{

	printtable();
	
}

