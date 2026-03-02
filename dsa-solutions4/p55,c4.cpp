
#pragma warning(disable: 4996)
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

struct Date {
    short Year;
    short Month;
    short Day;
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
    return dayInMonth(date.Year, date.Month) == date.Day;
}

void printDate(Date date) {
    cout << date.Day << "/" << date.Month << "/" << date.Year << endl;
}

Date ReadFullDate() {
    Date date;
    date.Day = readDay();
    date.Month = readMonth();
    date.Year = readYear();
    return date;
}


short DayOfWeekOrder(Date date) {
    short a, y, m;
    a = (14 - date.Month) / 12;
    y = date.Year - a;
    m = date.Month + (12 * a) - 2;

    return (date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
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
    return dayInMonth(date.Year, date.Month) - date.Day;
}

short DaysFromTheStartOfTHeYear(Date date) {
    short result = 0;
    for (int i = 1; i < date.Month; i++)
        result += dayInMonth(date.Year, i);
    result += date.Day;
    return result;
}

short DaysUntilTheEndOfTheYear(Date date) {
    short diff = (leaoYear(date.Year) ? 366 : 365) - DaysFromTheStartOfTHeYear(date);
    return diff;
}
string DayShortName(short dayOfWeekOrder) {
    static const string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return arrDayNames[dayOfWeekOrder];
}
short NUmberFromTheYearBegining(short year, short month, short day) {
    short count = 0;
    for (int i = 1; i < month; i++)
    {
        count += dayInMonth(year, i);
    }
    return count + day;
}
bool IsDate1BeforeDate2(Date Date1, Date Date2) {
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ?
        (Date1.Month < Date2.Month ? true :
            (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
int RestOFAyear(Date date) {
    short total = 0;
    total += leaoYear(date.Year) ? 366 : 365;
    total -= NUmberFromTheYearBegining(date.Year, date.Month, date.Day);
    return total;
}
int DaysBetweenYears(Date date1, Date date2) {
    short diff = 0;
    for (short i = date1.Year + 1; i < date2.Year; i++)
    {
        diff += leaoYear(i) ? 366 : 365;
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
bool LastMonthOfYear(short month) {
    return month == 12;
}
Date IncreaseDateByOneDay(Date& date) {
    if (LastDayOfMonth(date)) {
        if (LastMonthOfYear(date.Month)) {
            date.Month = 1;
            date.Day = 1;
            date.Year++;
        }
        else {
            date.Day = 1;
            date.Month++;
        }
    }
    else {
        date.Day++;
    }
    return date;
}
int ReadVecationDays() {
    int vacationDays;
    cout << "please enter vecation days" << endl;
    cin >> vacationDays;
    return vacationDays;

}
int vacationDays(Date start, Date end) {
    int businessDays = 0;
    int totalDays = DateDifference(start, end, true);

    for (int i = 0; i < totalDays; i++) {
        if (!IsWeekEnd(start)) {
            businessDays++;
        }
        start = IncreaseDateByOneDay(start);
    }
    return businessDays;
}
Date returnDateFromVacation(Date date, short vacationDays) {
    while (vacationDays > 0) {
        date = IncreaseDateByOneDay(date);

        if (!IsWeekEnd(date)) {  
            vacationDays--;
        }
    }
    return date;
}



int main() {
    cout << "\nVacation Starts: ";
    Date DateFrom = ReadFullDate();

    Date DateReturn = returnDateFromVacation(DateFrom, ReadVecationDays());
    cout << "\n\nReturn Date: " << DayShortName(DayOfWeekOrder(DateReturn)) << " , "
        << DateReturn.Day << "/" << DateReturn.Month << "/" << DateReturn.Year << endl;
   


}