
#include <iostream>
#include <string>
using namespace std;
string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

void firstLetter( string word) {
    

    cout << word[0] << endl;  

    for (int i = 0; i < word.length() - 1; i++) {
        if (word[i] == ' ' && word[i + 1] != ' ') {
            cout << word[i + 1] << endl;
        }
    }
}

int main() {
    
    firstLetter(ReadString());
}
#include<string>
#include<iostream>
using namespace std;

string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

void PrintFirstLetterOfEachWord(string S1) {
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string: \n";
    for (short i = 0; i < S1.length(); i++) {
        if (S1[i] != ' ' && isFirstLetter) {
            cout << S1[i] << endl;
        }
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
}

int main() {
    PrintFirstLetterOfEachWord(ReadString());
    system("pause>0");
}

