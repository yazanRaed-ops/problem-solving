#include <iostream>
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
Date ReadFullDate() { 
    Date Date;
    Date.Day = readDay();  
    Date.Month = readMonth();  
    Date.Year = readYear();
    return Date; 
}
bool IsDate1BeforeDate2(Date Date1, Date Date2) {
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ?
        (Date1.Month < Date2.Month ? true : 
            (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{
    Date date1 = ReadFullDate();
    cout << "\n";
    Date date2 = ReadFullDate();
    cout << "\n";
    if (IsDate1BeforeDate2(date1, date2)) {
        cout << "\nYes, Date1 is Less than Date2.";
    }
    else {
        cout << "\nNo, Date1 is NOT Less than Date2.";   
        system("pause>0");
        return 0;
    }
}

