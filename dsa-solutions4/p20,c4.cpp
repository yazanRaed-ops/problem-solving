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
Date IncreaseDateByOneDay(Date &date) {
    if (LastDayOfMonth(date)) {
        if (LastMonthOfYear(date.month)) {
           date.month = 1;
           date.day = 1;
           date.year++;
        }
        else {
           date.day = 1;
           date.month++;
        }  
    }
    else {
        date.day++;
    }
    return date;
}
Date increasDateByXDays(short Days, Date& date) {
    while (Days-- > 0) {
        IncreaseDateByOneDay(date);
    }
    return date;
}
Date IncreaseDateByOneWeek(Date& date) {
    if (LastDayOfMonth(date)) {
        if (LastMonthOfYear(date.month)) {
            date.month = 1;
            date.day = 7;
            date.year++;
        }
        else {
            date.day = 7;
            date.month++;
        }
    }
    else {
        date.day++;
    }
    return date;
}
Date IncreaseDateByXWeeks(Date &date, short week) {
    while (week-- > 0) {
        IncreaseDateByOneWeek(date);
    }
    return date;

}
Date IncreaseDateByOneMonth(Date &date) {
    if (date.month==12) {
        date.month = 1;
        date.year++;
    }
    else {
        
        date.month++;
        
    }
    short maxDays = dayInMonth(date.year, date.month);
    if (date.day > maxDays) {
        date.day = maxDays;
    }
   
    return date;
}
Date IncreaseDateByXMonth(Date& date, short month) {
    while (month-- > 0) {
        IncreaseDateByOneMonth(date);
    }return date;
}
Date  IncreaseDateByOneYear(Date& date) {
    date.year++;
    return date;
}
Date  IncreaseDateByXYear(Date& date, short year) {
    while (year-- > 0) {
        IncreaseDateByOneYear(date);
    }
    return date;
}
Date  IncreaseDateByXYearFaster(Date& date, short year) {
    date.year += year;
    return date;
}
Date  IncreaseDateByOneDecade(Date& date) {
    date.year+=10;
    return date;
}
Date  IncreaseDateByXDecades(Date& date, short Decades) {
    while (Decades-- > 0) {
        IncreaseDateByOneDecade(date);
    }
    return date;
}
Date  IncreaseDateByXDecadesFaster(Date& date, short Decades) {
    date.year +=( Decades*10);
    return date;
}
Date IncreaseDateByOneCentury(Date& date) {
    date.year += 100;
    return date;
}
Date IncreaseDateByOneMillennium(Date& date) {
    date.year += 1000;
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
    // Read initial date
    Date date = ReadFullDate();

    cout << "Initial date: ";
    printDate(date);

    // 1. Add one day
    date = IncreaseDateByOneDay(date);
    cout << "Date after adding one day: ";
    printDate(date);

    // 2. Add 10 days
    date = increasDateByXDays(10, date);
    cout << "Date after adding 10 days: ";
    printDate(date);

    // 3. Add one week
    date = IncreaseDateByOneWeek(date);
    cout << "Date after adding one week: ";
    printDate(date);

    // 4. Add 10 weeks
    date = IncreaseDateByXWeeks(date, 10);
    cout << "Date after adding 10 weeks: ";
    printDate(date);

    // 5. Add one month
    date = IncreaseDateByOneMonth(date);
    cout << "Date after adding one month: ";
    printDate(date);

    // 6. Add 5 months
    date = IncreaseDateByXMonth(date, 5);
    cout << "Date after adding 5 months: ";
    printDate(date);

    // 7. Add one year
    date = IncreaseDateByOneYear(date);
    cout << "Date after adding one year: ";
    printDate(date);

    // 8. Add 10 years
    date = IncreaseDateByXYear(date, 10);
    cout << "Date after adding 10 years: ";
    printDate(date);

    // 9. Add 10 years faster
    date = IncreaseDateByXYearFaster(date, 10);
    cout << "Date after adding 10 years (faster): ";
    printDate(date);

    // 10. Add one decade
    date = IncreaseDateByOneDecade(date);
    cout << "Date after adding one decade: ";
    printDate(date);

    // 11. Add 3 decades
    date = IncreaseDateByXDecades(date, 3);
    cout << "Date after adding 3 decades: ";
    printDate(date);

    // 12. Add 5 decades faster
    date = IncreaseDateByXDecadesFaster(date, 5);
    cout << "Date after adding 5 decades (faster): ";
    printDate(date);

    // 13. Add one century
    date = IncreaseDateByOneCentury(date);
    cout << "Date after adding one century: ";
    printDate(date);

    // 14. Add one millennium
    date = IncreaseDateByOneMillennium(date);
    cout << "Date after adding one millennium: ";
    printDate(date);

    return 0;
}
