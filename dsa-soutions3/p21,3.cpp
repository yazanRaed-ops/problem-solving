

#include <iostream>
using namespace std;
void fibonacciSeries(short number) {
	int p1 = 0, p2 = 0 ,t=0;

	for (int i = 1; i <=number; i++)
	{
		if (i == 1) {
			t = i;
			cout << t<<"  ";
			p2 = t;
		}
		else {
			t = p1 + p2;
			cout << t<<"  ";
			p1 = p2;
			p2 = t;
		}
	}
}
int main()
{
	fibonacciSeries(10);
}
#include<iostream>
using namespace std;

void PrintFibonacciUsingLoop(short Number) {
	int FebNumber = 0;
	int Prev2 = 0, Prev1 = 1;

	cout << "1   ";
	for (short i = 2; i <= Number; ++i) {
		FebNumber = Prev1 + Prev2;
		cout << FebNumber << "    ";
		Prev2 = Prev1;
		Prev1 = FebNumber;
	}
}

int main() {
	PrintFibonacciUsingLoop(10);
	system("pause>0");
