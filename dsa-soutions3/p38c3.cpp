#include <iostream>
#include <string>
using namespace std;

string readString() {
    cout << "plz enter string : \n";
    string name;
    getline(cin, name);
    return name;
}

string TrimLeft(string name) {
    for (short i = 0; i < name.length(); i++) {
        if (name[i] != ' ') {
            name.erase(0, i);
            return name;
        }
    }
    return ""; 
}

string TrimRight(string name) {
    for (short i = name.length() - 1; i >= 0; i--) {
        if (name[i] != ' ') {
            name.erase(i + 1);
            return name;
        }
    }
    return ""; 
}

string Trim(string name) {
    return TrimLeft(TrimRight(name));
}

int main() {
    string name = readString();
    cout << "[" << Trim(name) << "]" << endl; 
}
#include <string>
#include <iostream>
using namespace std;

string TrimLeft(string S1) {
    for (short i = 0; i < S1.length(); i++) {
        if (S1[i] != ' ') {
            return S1.substr(i, S1.length() - i);
        }
    }
    return "";
}

string TrimRight(string S1) {
    for (short i = S1.length() - 1; i >= 0; i--) {
        if (S1[i] != ' ') {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}

string Trim(string S1) {
    return (TrimLeft(TrimRight(S1)));
}

int main() {
    string S1 = "      Mohammed Abu-Hahdoud      ";
    cout << "\nString     = " << S1;
    cout << "\n\nTrim Left  = " << TrimLeft(S1);
    cout << "\nTrim Right = " << TrimRight(S1);
    cout << "\nTrim       = " << Trim(S1);
    system("pause>0");
}

