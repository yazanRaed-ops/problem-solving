
#pragma warning(disable: 4996)
#include <iostream>
#include <ctime>
#include <string>
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

void printDate(Date date) {
    cout << date.day << "/" << date.month << "/" << date.year << endl;
}

Date ReadFullDate() {
    Date date;
    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();
    return date;
}


short DayOfWeekOrder(Date date) {
    short a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + (12 * a) - 2;
   
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool IsEndOfWeek(Date date) {
    return DayOfWeekOrder(date) == 6 ? true : false;
}

bool IsWeekEnd(Date date) {
    short d = DayOfWeekOrder(date);
    return (d == 5 || d == 6) ? true : false;
}

bool IsBusinessDay(Date date) {
    short d = DayOfWeekOrder(date);
    return (d != 5 && d != 6) ? true : false;
}

short DaysUntilTheEndOfWeek(Date date) {
    return 6 - DayOfWeekOrder(date); 
}

short DaysUntilTheEndOfTheMonth(Date date) {
    return dayInMonth(date.year, date.month) - date.day;
}

short DaysFromTheStartOfTHeYear(Date date) {
    short result = 0;
    for (int i = 1; i < date.month; i++)
        result += dayInMonth(date.year, i);
    result += date.day;
    return result;
}

short DaysUntilTheEndOfTheYear(Date date) {
    short diff = (leaoYear(date.year) ? 366 : 365) - DaysFromTheStartOfTHeYear(date);
    return diff;
}

string DayShortName(short dayOfWeekOrder) {
    static const string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return arrDayNames[dayOfWeekOrder];
}

Date GetSystemDate() {
    Date date;
    time_t t = time(0);
    tm* now = localtime(&t);

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;

    return date;
}


int main() {
    
    Date today = GetSystemDate();

    
    cout << "\nToday is " << DayShortName(DayOfWeekOrder(today)) << " , ";
    printDate(today);

    cout << "\nIs it End of Week? ";
    if (IsEndOfWeek(today))
        cout << "Yes, it is Saturday." << endl;
    else
        cout << "No, it's not end of week." << endl;

    
    cout << "\nIs it Weekend? ";
    if (IsWeekEnd(today))
        cout << "Yes, it's a weekend." << endl;
    else
        cout << "No, today is " << DayShortName(DayOfWeekOrder(today)) << ", not a weekend." << endl;

    
    cout << "\nIs it Business Day? ";
    if (IsBusinessDay(today))
        cout << "Yes, it is a business day." << endl;
    else
        cout << "No, it's not a business day." << endl;

    
    cout << "\nDays until end of week: " << DaysUntilTheEndOfWeek(today) << " Day(s)." << endl;
    cout << "Days until end of month: " << DaysUntilTheEndOfTheMonth(today) << " Day(s)." << endl;
    cout << "Days until end of year: " << DaysUntilTheEndOfTheYear(today) << " Day(s)." << endl;

    return 0;
}
