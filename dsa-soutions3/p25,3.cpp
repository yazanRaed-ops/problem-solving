#include <iostream>
#include <string>
#include<cctype>
using namespace std;


string firstLetter(string& word) {

    cout << "String after conversion : \n";
    word[0] = tolower(word[0]);

    for (int i = 0; i < word.length() - 1; i++) {
        if (word[i] == ' ' && word[i + 1] != ' ') {
            word[i + 1] = tolower(word[i + 1]);
        }
    }
    return word;
}
string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

int main() {
    string text = ReadString();
    cout << firstLetter(text) << endl;

}
#include <string>
#include <iostream>
using namespace std;

string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

string LowerFirstLetterOfEachWord(string S1) {
    bool isFirstLetter = true;
    for (short i = 0; i < S1.length(); i++) {
        if (S1[i] != ' ' && isFirstLetter) {
            S1[i] = tolower(S1[i]);
        }
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}

int main() {
    string S1 = ReadString();
    cout << "\nString after conversion:\n";
    S1 = LowerFirstLetterOfEachWord(S1);
    cout << S1 << endl;
    system("pause>0");
}
