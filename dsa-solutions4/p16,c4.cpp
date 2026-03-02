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
bool LastDayOfMonth(short year, short month, short day) {
    return dayInMonth(year, month) == day;
}
bool LastMonthOfYear(short month) {
    return month == 12;
}
Date AddOneDay(short year , short month ,short day) {
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    if (day !=dayInMonth(year,month) ) {
        date.day++;
        return date;
    }
    if (day == dayInMonth(year, month)) {
        if (month != 12) {
            date.day = 1; date.month++;
            return date;
        }
        else {
            date.day = 1; date.month=1;
        }
    }
    
    date.year++;
    date.month = 1; date.day = 1;
    return date;

}
void printDate(Date date) {
    cout << date.day << "/" << date.month << "/" << date.year << endl;
}
int main()
{
    Date date;
    short day = readDay();
    short month = readMonth();
    short year = readYear();
    date = AddOneDay(year, month, day);
    cout << "Date after Adding one day is : ";
    printDate(date);
    
}
#include <iostream>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
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
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

int main() {
    stDate Date1 = ReadFullDate();

    Date1 = IncreaseDateByOneDay(Date1);

    cout << "\nDate after adding one day is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    system("pause>0");
    return 0;
}
