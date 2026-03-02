
#include <iostream>
#include <string>
#include<cctype>
using namespace std;


string firstLetter(string &word) {

    cout << "String after conversion : \n";
       word[0]=toupper(word[0]);

    for (int i = 0; i < word.length() - 1; i++) {
        if (word[i] == ' ' && word[i + 1] != ' ') {
            word[i + 1] = toupper(word[i + 1]);
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