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
int numberOfDaysInMonth(short year,short month) {
    
    if (month == 2) {
        return leapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
    
}
int NumberOfHourseInaMonth(short year,short month) {
    return numberOfDaysInMonth(year,month) * 24;
}
int NumberOfMinInMonth(short year, short month) {
    return NumberOfHourseInaMonth(year, month) * 60;
}
int NumberOfSecInYear(short year,short month) {
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
    cout << "\nNumber of Hours   in Month [" << month << "] is " << NumberOfHourseInaMonth(Year, month);
    cout << "\nNumber of Minutes in Month [" << month << "] is " << NumberOfMinInMonth(Year, month);
    cout << "\nNumber of Seconds in Month [" << month << "] is " << NumberOfSecInYear(Year, month);
    system("pause>0");
    return 0;
}

