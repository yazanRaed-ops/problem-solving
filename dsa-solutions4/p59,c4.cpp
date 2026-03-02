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

bool leapYear(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
short dayInMonth(short year, short month) {
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (leapYear(year) ? 29 : 28) : days[month - 1];
}
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
bool IsPeriodOverLapping(Peroide per, Peroide per2) {
    if (IsDate1BeforeDate2(per2.EndDate, per.StartDate) || IsDate1BeforeDate2(per.EndDate, per2.StartDate)) {
        return false;
    } return true;
}

short NUmberFromTheYearBegining(short year, short month, short day) {
    short count = 0;
    for (int i = 1; i < month; i++)
    {
        count += dayInMonth(year, i);
    }
    return count + day;
}
int RestOFAyear(Date date) {
    short total = 0;
    total += leapYear(date.Year) ? 366 : 365;
    total -= NUmberFromTheYearBegining(date.Year, date.Month, date.Day);
    return total;
}
int DaysBetweenYears(Date date1, Date date2) {
    short diff = 0;
    for (short i = date1.Year + 1; i < date2.Year; i++)
    {
        diff += leapYear(i) ? 366 : 365;
    }
    return diff;
}
int DateDifference(Date date1, Date date2, bool Include = 1) {
    int Diff = 0;

    if (IsDate1BeforeDate2(date1, date2)) {
        if (date1.Year == date2.Year) {
            Diff = NUmberFromTheYearBegining(date2.Year, date2.Month, date2.Day) -
                NUmberFromTheYearBegining(date1.Year, date1.Month, date1.Day);
        }
        else {
            int YearComplementary = RestOFAyear(date1);
            int diffYears = DaysBetweenYears(date1, date2);
            Diff = NUmberFromTheYearBegining(date2.Year, date2.Month, date2.Day);
            Diff += YearComplementary + diffYears;

        }


    }
    if (Include) {

        return Diff + 1;
    }
    return Diff;


}
int PeriodLengthInDays(Peroide Period, bool IncludeEndDate = false) {
    return DateDifference(Period.StartDate, Period.EndDate, IncludeEndDate);
}

Peroide ReadPeriod() {
    Peroide Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}
int main()
{
    Peroide per = ReadPeriod();
     
    cout << "\nperoiod length is : " << PeriodLengthInDays(per) << endl;
    cout << "\nperoiod length (including end date ) : " << PeriodLengthInDays(per,true) << endl;
     
}

