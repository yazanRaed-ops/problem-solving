#include <iostream>
#include <string>

using namespace std;
string ReadString() {
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
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
void PrintVowelInWord(string name) {
    char ch;
    cout << "\nvowels in a string are : ";
    for (int i = 0; i < name.length(); i++)
    {
 
            if (IsVowel(tolower(name[i]))) {
                cout << name[i] << "    ";
            }
        
    }
}

int main()
{
    string name = ReadString();
    PrintVowelInWord(name);


}
