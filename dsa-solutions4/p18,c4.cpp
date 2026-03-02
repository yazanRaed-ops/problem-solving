#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
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
bool LastMonthOfYear(short month) {
    return month == 12;
}
Date ReadFullDate() {
    Date date;
    date.Day = readDay();
    date.Month = readMonth();
    date.Year = readYear();
    return date;
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
Date GetCurrentDate() {
    time_t t = time(nullptr);          
    tm* now = localtime(&t);           

    Date today;
    today.Year = now->tm_year + 1900;  
    today.Month = now->tm_mon + 1;     
    today.Day = now->tm_mday;          
    return today;
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
int main()
{

    Date date1;
    Date date2;
    do {
        date1 = ReadFullDate();
        cout << endl;
        date2 = GetCurrentDate();
    } while (!IsDate1BeforeDate2(date1, date2));
    cout << "Difference is : " << DateDifference(date1, date2, false) << endl;
    cout << "\nDifference is including end day : " << DateDifference(date1, date2);



}

