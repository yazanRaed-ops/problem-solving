
#include <iostream>
#include <string>

using namespace std;
char ReadCharacter() {
    char c;
    cout << "\nPlease enter a character:\n ";
    cin >> ws;
    cin.get(c);
    return c;
}
bool IsVowel(char ch) {
    if (ch == 'a' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'e') {
        return true;;
    }
    else {
        return false;
    }
}


int main()
{
    char ch = ReadCharacter();
    if (IsVowel(ch)) {
        cout << "Yes letter '" << ch << "' is vowel /n";
    }
    else {
        cout << "No letter '" << ch << "' is not vowel \n";
    }

}
