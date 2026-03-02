

#include <iostream>
using namespace std;
bool leapYear(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int numberOfDaysInMonth(short year, short month) {

    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return  (month == 2) ? (leapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}
short readYear() {
    short year;
    do {
        cout << "please enter a year ? ";
        cin >> year;
    } while (year < 1);
    return year;
}
short readMonth() {
    short month;
    do {
        cout << "please enter a month ? ";
        cin >> month;
    } while (month < 1 || month > 12);
    return month;
}
short dayOrder(short year, short month, short day=1) {
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;

    short d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d;
}
string DayShortName(short DayOfWeekOrder) {
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}
void calender(short year, short month) {
    string arrMonthNames[] = {
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"
    };
    int current = dayOrder(year, month);
    cout << "  ---------------" << arrMonthNames[month - 1] << "---------------\n";
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); 
    int i;
    for (i = 0; i < current; i++)          
        printf("     ");                   

    for (int j = 1; j <= numberOfDaysInMonth(year, month); j++) {
        printf("%5d", j);
        if (++i == 7) {
            i = 0;
            printf("\n");
        }
    }

    printf("\n  _________________________________\n");
}

int main()
{
    short year = readYear();
    short month = readMonth();
    calender(year, month);
}

