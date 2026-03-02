
#include <iostream>
using namespace std;
bool leapYear(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
short ReadYear() {
    short Year;
     cout << "\nPlease enter a year to check? "; 
    cin >> Year; 
     return Year;
}
int main()
{
    short year=ReadYear();
    
    string result = "";
    result = leapYear(year) ? "leap year" : "not a leap year";
    cout << result;
}

