// solution6-10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
//struct name {
//	string firstname;
//	string lastname;
//
//};
//name readname() {
//	name info;
//	cout << "plz enter your first name" << endl;
//	cin>>info.firstname;
//	cout << "plz enter your last name" << endl;
//	cin>>info.lastname;
//	return info;
//}
//string getname(name info) {
//	string fullname = info.firstname +" "+ info.lastname;
//	return fullname;
//}
//void printname(string fullname) {
//	cout << "your full name is : " << fullname;
//}
//int readnumber() {
//	int number;
//	cout << "plz enter number" << endl;
//	cin >> number;
//	return number;
//}
//float calculatenumber(int num) {
//	float halfNum = num * 0.5;
//	return halfNum;
//}
//void printresult(int num) {
//	string result = "half of number" + to_string(num) + " is " + to_string(calculatenumber(num));
//	cout << endl << result << endl;
//}
//
//enum grade{pass = 1 ,fail=2};
//int readmark() {
//	int mark;
//	cout << "plz enter student gard" << endl;
//	cin >> mark;
//	return mark;
//
//}
//grade checkmark(int mark) {
//	if (mark >= 50) {
//		return grade::pass;
//	}
//	else {
//		return grade::fail;
//	}
//}
//void printResult(int mark) {
//	if (checkmark(mark) == grade::pass) {
//		cout << "you passes the test " << endl;
//	}
//	else {
//		cout << "so sad you failed" << endl;
//	}
//
//}
void readnumbers(int &num1,int &num2,int &num3) {
	cout << "plz enter first number" << endl;
	cin >> num1;
	cout << "plz enter seconed number" << endl;
	cin >> num2;
	cout << "plz enter third number" << endl;
	cin >> num3;
}
int sumOfThree(int num1, int num2, int num3) {
	int total = num1 + num2 + num3;
	return total;
}
float avgResult(int total) {
	
	float avg = total / 3.0;

	return avg;
}
void printresult(float avg) {
	cout << "the final sum of the three numbers are : " << avg;
}
 int main()
{
	int num1, num2, num3 ;
	readnumbers(num1, num2,  num3);
	printresult(avgResult(sumOfThree(num1, num2, num3)));
	//printname(getname(readname()));
	 //printresult(readnumber());
	// printResult(readmark());
   
}
