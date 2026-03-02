

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
short dayOrder(short year, short month, short day = 1) {
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
    for (int i = 1; i <=12; i++)
    {
        calender(year, i);
        cout << endl;
    }
    
}
#include <iostream>
using namespace std;

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Day, short Month, short Year) {
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder) {
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}

short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

string MonthShortName(short MonthNumber) {
    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return Months[MonthNumber - 1];
}

void PrintMonthCalendar(short Month, short Year) {
    int NumberOfDays;
    int current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = NumberOfDaysInAMonth(Month, Year);
    printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int i;
    for (i = 0; i < current; i++)
        printf("     ");
    for (int j = 1; j <= NumberOfDays; j++) {
        printf("%5d", j);
        if (++i == 7) {
            i = 0;
            printf("\n");
        }
    }
    printf("\n  _________________________________\n");
}

void PrintYearCalendar(int Year) {
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", Year);
    printf("  _________________________________\n");
    for (int i = 1; i <= 12; i++) {
        PrintMonthCalendar(i, Year);
    }
    return;
}

short ReadYear() {
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}

int main() {
    PrintYearCalendar(ReadYear());
    system("pause>0");
    return 0;
}


