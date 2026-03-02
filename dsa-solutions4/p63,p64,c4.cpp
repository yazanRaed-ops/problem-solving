#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------------------- Struct ----------------------
struct stDate {
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

// ---------------------- Date Conversions ----------------------
stDate StringToDate(string DateString) {
    stDate Date;
    vector<string> vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);    // Convert string to int
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string DateToString(stDate Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
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
    string DateString = ReadStringDate("\nPlease Enter Date (dd/mm/yyyy): ");
    stDate Date = StringToDate(DateString);

    // Display day, month, year separately
    cout << "\nDay: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;

   
    cout << "\nYou Entered: " << DateToString(Date) << "\n";

    system("pause>0");
    return 0;
}
