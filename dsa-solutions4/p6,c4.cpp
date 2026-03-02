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

int numberOfDaysInMonth(short year, short month) {
    
    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return  (month == 2)? (leapYear(year) ? 29 : 28) : NumberOfDays[month-1];
}
int NumberOfHourseInaMonth(short year, short month) {
    return numberOfDaysInMonth(year, month) * 24;
}
int NumberOfMinInMonth(short year, short month) {
    return NumberOfHourseInaMonth(year, month) * 60;
}
int NumberOfSecInMonth(short year, short month) {
    return NumberOfMinInMonth(year, month) * 60;
}
short ReadMonth() {
    short month;
    do {
        cout << "please enter month to check ? \n";
        cin >> month;
    } while (month > 12 || month < 1);
    return month;
}
int main()
{
    short Year = ReadYear();
    cout << "\n\n";
    short month = ReadMonth();
    cout << "\nNumber of Days    in Month [" << month << "] is " << numberOfDaysInMonth(Year, month);
    
    system("pause>0");
    return 0;
}

