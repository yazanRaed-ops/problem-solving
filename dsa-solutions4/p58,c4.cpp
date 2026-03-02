#pragma warning(disable: 4996)
#include <iostream>
#include <string>
using namespace std;

struct Date {
    short Year;
    short Month;
    short Day;
};

struct Peroide {
    Date EndDate;
    Date StartDate;
};

// Read functions
short readYear() {
    short year;
    cout << "Please enter a year: ";
    cin >> year;
    return year;
}

short readMonth() {
    short month;
    cout << "Please enter a month: ";
    cin >> month;
    return month;
}

short readDay() {
    short day;
    cout << "Please enter a day: ";
    cin >> day;
    return day;
}

// Leap year check
bool leapYear(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Days in month
short dayInMonth(short year, short month) {
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (leapYear(year) ? 29 : 28) : days[month - 1];
}

// Read a full date
Date ReadFullDate() {
    Date date;
    while (true) {
        date.Day = readDay();
        date.Month = readMonth();
        date.Year = readYear();
        if (date.Month >= 1 && date.Month <= 12 && date.Day >= 1 && date.Day <= dayInMonth(date.Year, date.Month))
            break;
        cout << "Invalid date. Please enter again.\n";
    }
    return date;
}

// Increase date by one day
Date IncreaseDateByOneDay(Date& date) {
    if (date.Day == dayInMonth(date.Year, date.Month)) {
        date.Day = 1;
        if (date.Month == 12) {
            date.Month = 1;
            date.Year++;
        }
        else {
            date.Month++;
        }
    }
    else {
        date.Day++;
    }
    return date;
}

// Date comparisons
bool IsDate1BeforeDate2(Date d1, Date d2) {
    return (d1.Year < d2.Year) ||
        (d1.Year == d2.Year && d1.Month < d2.Month) ||
        (d1.Year == d2.Year && d1.Month == d2.Month && d1.Day < d2.Day);
}

bool IsDate1EqualDate2(Date d1, Date d2) {
    return (d1.Year == d2.Year && d1.Month == d2.Month && d1.Day == d2.Day);
}

bool IsDate1AfterDate2(Date d1, Date d2) {
    return !IsDate1BeforeDate2(d1, d2) && !IsDate1EqualDate2(d1, d2);
}

// Check if two periods overlap
bool isPeriodsOverlapping(Peroide per1, Peroide per2) {
    return !IsDate1AfterDate2(per1.StartDate, per2.EndDate) &&
        !IsDate1BeforeDate2(per1.EndDate, per2.StartDate);
}

int main() {
    cout << "Enter Period 1 Start Date:\n";
    Date start1 = ReadFullDate();
    cout << "Enter Period 1 End Date:\n";
    Date end1 = ReadFullDate();

    cout << "Enter Period 2 Start Date:\n";
    Date start2 = ReadFullDate();
    cout << "Enter Period 2 End Date:\n";
    Date end2 = ReadFullDate();

    Peroide per1{ end1, start1 };
    Peroide per2{ end2, start2 };

    if (isPeriodsOverlapping(per1, per2)) {
        cout << "The periods are overlapping.\n";
    }
    else {
        cout << "The periods are NOT overlapping.\n";
    }

    return 0;
}
