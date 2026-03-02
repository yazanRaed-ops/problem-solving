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
int numberOfDaysInAyear(short year) {
    return leapYear(year) ? 366 : 365;
}
int NumberOfHourseInaYear(short year) {
    return numberOfDaysInAyear(year) * 24;
}
int NumberOfMinInYear(short year) {
    return NumberOfHourseInaYear(year) * 60;
}
int NumberOfSecInYear(short year) {
    return NumberOfMinInYear(year) * 60;
}
int main()
{
    short year = ReadYear();
    cout << "\n\nnumber of days in year [" << year << "] is : " 
        << numberOfDaysInAyear(year);
    cout << "\nnumber of hours in year [" << year << "] is : "
        << NumberOfHourseInaYear(year);
    cout << "\nnumber of min in year [" << year << "] is : "
        << NumberOfMinInYear(year);
    cout << "\nnumber of days in year [" << year << "] is : "
        << NumberOfSecInYear(year);
    
}

