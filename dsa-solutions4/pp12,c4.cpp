
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
short DaysTOAdd() {
    short num;
    cout << "plz enter how many days u want to add : ";
    cin >> num;
    return num;
}
Date addDaysToYear(int daysToAdd, short year, short day, short month) {
    Date date;

    
    int DaysOFYear = NUmberFromTheYearBegining(year, month, day);
    daysToAdd += DaysOFYear;
    while (true) {
        int DaysInAyear = leaoYear(year) ? 366 : 365;
            if (daysToAdd <= DaysInAyear) {
                break;
            }
            else {
                daysToAdd -= DaysInAyear;
                year++;
            }
    }
    date.year = year;
    date = NUmberOFMonthFromDays(year, daysToAdd);
    return date;
}

void datechange(short day,short Month,short Year) {
    short year = day /365;
    short reminder = day % 365;
    short month = reminder /30 ;


}

int main()
{
    short day = readDay();
    short month = readMonth();
    short year = readYear();
    short num = DaysTOAdd();
    short num2 = NUmberFromTheYearBegining(year, month, day);
    Date date=NUmberOFMonthFromDays(year, num2);
    Date date2 = addDaysToYear(num, year, day, month);
    cout << "number of days from the begining of the year is : " << num2<<endl;
    cout << "Date for [" << num2<< "] is : " << date.day << "/" << date.month << "/" << date.year<<endl;
    cout << "date after adding [" << num << "] days is : " << date2.day << "/" << date2.month << "/" << date2.year;

}