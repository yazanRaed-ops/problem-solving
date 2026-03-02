#include <iostream>
#include <string>
using namespace std;
long long int readnumber() {
	long long int number;
	do {
		cout << "enter positive number" << endl;
		cin >> number;
	} while (number < 0);
	return number;
}

void reverseInNumber(long long int number) {
	string num = to_string(number);
	int sum = 0;

	for (int i = 0; i < num.length(); i++) {
		bool flag = false;
		for (int k = 0; k < i; k++)
		{
			if (num[i] == num[k]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}
		for (int j = 0; j < num.length(); j++)
		{
			if (num[i] == num[j]) {
				sum += 1;
				
			}
		}cout << int(num[i]-'0') << " frequancy is : " << sum << endl;
		sum = 0;

	}
}
//#include <iostream>
//using namespace std;
//
//int ReadPositiveNumber(string Message)
//{
//    int Number = 0;
//    do
//    {
//        cout << Message << endl;
//        cin >> Number;
//    } while (Number <= 0);
//
//    return Number;
//}
//
//int CountDigitFrequency(short DigitToCheck, int Number)
//{
//    int Freq = 0;
//    int Remainder = 0;
//
//    while (Number > 0)
//    {
//        Remainder = Number % 10;
//        Number = Number / 10;
//
//        if (DigitToCheck == Remainder)
//        {
//            Freq++;
//        }
//    }
//    return Freq;
//}
//
//void PrintAllDigitsFrequencey(int Number)
//{
//    cout << endl;
//
//    for (int i = 0; i < 10; i++)
//    {
//        short DigitFrequency = 0;
//        DigitFrequency = CountDigitFrequency(i, Number);
//
//        if (DigitFrequency > 0)
//        {
//            cout << "Digit " << i << " Frequencey is "
//                << DigitFrequency << " Time(s).\n";
//        }
//    }
//}
//
//int main()
//{
//    int Number = ReadPositiveNumber("Please enter the a number?");
//    PrintAllDigitsFrequencey(Number);
//
//    return 0;
//}

int main() {
	reverseInNumber(readnumber());
}