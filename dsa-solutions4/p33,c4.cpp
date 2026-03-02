
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
bool FisrtDayInAyear(Date date) {
    return (date.day == 1 && date.month == 1);
}
bool FirstMonthOfTheYear(Date date) {
    return date.month == 1 ? true : false;
}
bool FirstDayOfMonth(Date date) {
    return date.day == 1;
}
Date subtractByOneDay(Date &date) {
    if (FirstDayOfMonth(date)) {
        if (FisrtDayInAyear(date)) {
            date.month = 12;
            date.day = 31;
            date.year -= 1;
        }
        else {
            date.month -= 1;
            date.day = dayInMonth(date.year, date.month);
        }
        return date;
    }
    date.day--;
    return date;
    

}
Date subtractDaysByXDays(short Days, Date date) {
    
    while (Days > 0) {
        date = subtractByOneDay(date);
        Days--;
    }
    return date;
}
Date subtractDateByOneWeek(Date &date) {
    for (short i = 0; i < 7; i++)
    {
        date = subtractByOneDay(date);
    }return date;
}
Date subtractDateByXWeek(Date& date,short Weeks) {
    for (short i = 0; i < Weeks; i++)
    {
        date = subtractDateByOneWeek(date);
    }return date;
}
Date subtractByOneMonth(Date &date ) {
    if (date.month == 1) {
        date.month=12;
        date.year -= 1;
        if (date.day > dayInMonth(date.year, date.month)) {
            date.day = dayInMonth(date.year, date.month);
        }
        
    }
    else {
        if (FisrtDayInAyear(date) && LastDayOfMonth(date)) {
            date.month = 12;
            date.year -= 1;
            date.day = dayInMonth(date.year, date.month);
        }
        else if (LastDayOfMonth(date)) {
            date.month -= 1;
            date.day = dayInMonth(date.year, date.month);
        }
        else if (date.day > dayInMonth(date.year, date.month - 1)) {
            date.month -= 1;
            date.day = dayInMonth(date.year, date.month);
        }
        else {
            date.month--;
        }
    }
    
    return date;
}
Date subtractByOneMonth(Date& date) {
    if (date.month == 1) {  // January
        date.year -= 1;
        date.month = 12;
        if (date.day > dayInMonth(date.year, date.month)) {
            date.day = dayInMonth(date.year, date.month);
        }
    }
    else {
        date.month -= 1;
        if (date.day > dayInMonth(date.year, date.month)) {
            date.day = dayInMonth(date.year, date.month);
        }
    }
    return date;
}

Date subtractByXMonth(Date& date , short Months) {
    while (Months > 0) {
        date = subtractByOneMonth(date);
        Months--;
    }
    return date;
}
Date subtractByOneYear(Date &date) {
    date.year - 1;
    return date;
}
Date subtractByXYear(Date& date, short Years) {
    while (Years > 0) {
        date = subtractByOneYear(date);
        Years--;
    }
    return date;
}
Date subtractByXYearFaster(Date& date, short Years) {
    date.year -= Years;
    return date;
}
Date subtractByOneDecade(Date& date) {
    date.year -= 10;
    return date;
}
Date  subtractByOneDecade(Date& date,short Deacads) {
    while (Deacads > 0) {
        date = subtractByOneDecade(date);
        Deacads--;
    }
    return date;
}
Date  subtractByOneDecadeFaster(Date& date, short Deacads) {
    date.year -= (10 * Deacads);
    return date;
}
Date subtractByOneCentury(Date& date) {
    date.year -= 100;
    return date;
}
Date subtractByOneMillennium(Date& date) {
    date.year -= 1000;
    return date;
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
int main()
{
    Date date = ReadFullDate();
    cout << "Initial date: ";
    printDate(date);

    // 1. Add one day
    date = subtractByOneDay(date);
    cout << "Date after sub one day: ";
    printDate(date);
}
