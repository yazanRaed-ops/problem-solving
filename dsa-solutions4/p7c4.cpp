#include <iostream>
using namespace std;

enum Days { sun, mon, tue, wed, thu, fri, sat };

short readDay() {
    short day;
    do {
        cout << "please enter a day ? ";
        cin >> day;
    } while (day < 1 || day > 31);
    return day;
}

short readYear() {
    short year;
    do {
        cout << "please enter a year ? ";
        cin >> year;
    } while (year < 1); // or (year < 1 || year > 2025) if you want a cap
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

short dayOrder(short year, short month, short day) {
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;

    short d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d;
}

void DateFormate(short year, short month, short day) {
    cout << "Date : " << day << "/" << month << "/" << year << endl;
}

void DayOrder(short D) {
    cout << "day order : " << D << endl;
}

void DayName(Days day) {
    switch (day) {
    case Days::sun: cout << "Sunday"; break;
    case Days::mon: cout << "Monday"; break;
    case Days::tue: cout << "Tuesday"; break;
    case Days::wed: cout << "Wednesday"; break;
    case Days::thu: cout << "Thursday"; break;
    case Days::fri: cout << "Friday"; break;
    case Days::sat: cout << "Saturday"; break;
    default: cout << "Invalid day"; break;
    }
}

int main() {
    short year = readYear();
    short month = readMonth();
    short day = readDay();

    short D = dayOrder(year, month, day);

    DateFormate(year, month, day);
    DayOrder(D);
    DayName(Days(D));
}
#include <iostream>
using namespace std;

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
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}

int main() {
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    cout << "\nDate      :" << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
