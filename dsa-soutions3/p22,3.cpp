
#include <iostream>
using namespace std;
void fibonachiiReccursion(short number,int p1,int p2,int t) {
	if (number > 0) {
		cout << p1 << "  ";
		t = p1 + p2;
		p1 = p2;
		p2 = t;
		fibonachiiReccursion(number - 1, p1, p2, t);
	}
}
int main()
{
	
	fibonachiiReccursion(10, 1, 1, 0);
}

#include<iostream>
using namespace std;

void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2) {
    int FebNumber = 0;
    if (Number > 0) {
        FebNumber = Prev2 + Prev1;
        Prev2 = Prev1;
        Prev1 = FebNumber;
        cout << FebNumber << "    ";
        PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
    }
}

int main() {
    PrintFibonacciUsingRecurssion(10, 0, 1);
    system("pause>0");
}
