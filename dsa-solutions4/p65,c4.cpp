#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------------------- Struct ----------------------
struct Date {
    short Day;
    short Month;
    short Year;
};

// ---------------------- Split String Function ----------------------
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    // Loop to find delimiter positions
    while ((pos = S1.find(Delim)) != string::npos) {
        sWord = S1.substr(0, pos);   // Extract substring
        if (sWord != "") {
            vString.push_back(sWord); // Add to vector
        }
        S1.erase(0, pos + Delim.length()); // Remove extracted part + delimiter
    }

    // Add last part
    if (S1 != "") {
        vString.push_back(S1);
    }

    return vString;
}
string replaceWordInString(string s1 ,string orginalString, string changeTo) {
    short pos = s1.find(orginalString);
    while (pos != std::string::npos) {
        s1 = s1.replace(pos, orginalString.length(), changeTo);
        pos = s1.find(orginalString);
    }
    return s1;
}

// ---------------------- Date Conversions ----------------------
Date StringToDate(string DateString) {
    Date Date;
    vector<string> vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);    // Convert string to int
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string DateToString(Date Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
string DateFormation(Date date, string format ="dd/mm/yyyy") {
    string form = "";
    form = replaceWordInString(format, "dd", to_string(date.Day));
    form = replaceWordInString(form, "mm", to_string(date.Month));
    form = replaceWordInString(form, "yyyy", to_string(date.Year));
    return form;

}

// ---------------------- Input Function ----------------------
string ReadStringDate(string Message) {
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString); // Read line and skip leading whitespaces
    return DateString;
}

// ---------------------- Main ----------------------
int main() {
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    Date date = StringToDate(DateString);

    cout << "\n" <<DateFormation(date) << "\n";
    cout << "\n" <<DateFormation(date, "yyyy/dd/mm") << "\n";
    cout << "\n" <<DateFormation(date, "mm/dd/yyyy") << "\n";
    cout << "\n" <<DateFormation(date, "mm-dd-yyyy") << "\n";
    cout << "\n" <<DateFormation(date, "dd-mm-yyyy") << "\n";
    cout << "\n" <<DateFormation(date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");
    return 0;
}

