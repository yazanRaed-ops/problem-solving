#include <iostream>
using namespace std;
struct Date {
    short year;
    short month;
    short day;

};
short readYear() {
    short year;
    cout << "please enter a year ? ";
    cin >> year;
    return year;
}
short readMonth() {
    short Month;
    cout << "please enter a Month ? ";
    cin >> Month;
    return Month;
}
short readDay() {
    short Day;
    cout << "please enter a Day ? ";
    cin >> Day;
    return Day;
}
bool leaoYear(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
short dayInMonth(short year, short month) {

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (leaoYear(year) ? 29 : 28) : days[month - 1];
}
bool LastDayOfMonth(Date date) {
    return dayInMonth(date.year, date.month) == date.day;
}
bool LastMonthOfYear(short month) {
    return month == 12;
}
Date ReadFullDate() {
    Date date;
    date.day = readDay();
    date.month = readMonth();
date.year = readYear();
return date; }
int main()
{
    Date date = ReadFullDate();
    if (LastDayOfMonth(date)) {
        cout << "yes is the last day of the month \n";
    }
    else {
        cout << "no , it is not  the last day of the month \n";
    }
    if (LastMonthOfYear(date.month)) {
        cout << "yes is the last month of the year \n";
    }
    else {
        cout << "no , it is not  the last month of the year \n";
    }
}

