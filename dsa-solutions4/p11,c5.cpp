
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
short NUmberFromTheYearBegining(short year, short month, short day) {
    short count = 0;
    for (int i = 1; i < month; i++)
    {
        count += dayInMonth(year, i);
    }
    return count + day;
}
Date NUmberOFMonthFromDays(short year, short totalDays) {
    Date date;
    date.year = year;
    short month = 1;

    while (totalDays > dayInMonth(year, month)) {
        totalDays -= dayInMonth(year, month);
        month++;
    }

    date.month = month;
    date.day = totalDays;
    return date;
}

int main()
{
    short day = readDay();
    short month = readMonth();
    short year = readYear();
    Date date=NUmberOFMonthFromDays(year, NUmberFromTheYearBegining(year, month, day));
    cout << "number of days from the begining of the year is : " << NUmberFromTheYearBegining(year, month, day)<<endl;
    cout << "Date for [" << NUmberFromTheYearBegining(year, month, day) << "] is : " << date.day << "/" << date.month << "/" << date.year;

}

#include <iostream>
using namespace std;

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++) {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

struct sDate {
    short Year;
    short Month;
    short Day;
};

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
    sDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;
    Date.Year = Year;
    Date.Month = 1;
    while (true) {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}

int main() {
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
    cout << "\nNumber of Days from the begining of the year is " << DaysOrderInYear << "\n\n";
    sDate Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
    cout << "Date for [" << DaysOrderInYear << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    system("pause>0");
    return 0;
}
