

#include <iostream>
using namespace std;
//string readname() {
//	cout << "plz enter your name:" << endl;
//	string name;
//	cin >> name;
//	return name;
//}
//void printname(string name) {
//	cout << "my name is :" << name;
//}
//int main()
//{
//	
//	printname(readname());
//	return 0;
//}
//enum numbertype { odd = 1,even =2 };
//int readnumber() {
//	cout << "enter the number plz" << endl;
//	int number;
//	cin >> number;
//	return number;
//
//}
//numbertype checknumbertype(int x) {
//	numbertype type;
//	if (x % 2 == 0) {
//		type = numbertype::even;
//	}
//	else {
//		type = numbertype::odd;
//	}
//	return type;
//}
//void printType(numbertype type) {
//	if (type == numbertype::even) {
//		cout << "it is even number " << endl;
//	}
//	else {
//		cout << " it is odd" << endl;
//	}
//	}
//
//int main() {
//	printType(checknumbertype(readnumber()));
//	
//}
struct statusInfo {
	short age;
	bool driverLicense;
	bool hasrecomindation;
};
statusInfo readinfo() {
	cout << "plz enter info :" << endl;
	statusInfo info;
	cin >> info.age>>info.driverLicense>>info.hasrecomindation;

	return info;
}
bool isacepted(statusInfo info) {
	if (info.hasrecomindation) {
		return true;
	}
	else {
		return (info.age > 21 && info.driverLicense == true);
	}
}
void printresult(statusInfo info) {
	if (isacepted(info)==true) {
		cout << " you are hired " << endl;
	}
	else {
		cout << "you are rejected " << endl;
	}
}
int main() {
	printresult(readinfo());

	
	return 0;
}