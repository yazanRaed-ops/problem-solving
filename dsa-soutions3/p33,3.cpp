
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
short NumberOfVowelInWord(string name) {
    short count = 0;
    for (int i = 0; i < name.length(); i++)
    {
        if (IsVowel(name[i])) {
            count++;
        }
    }return count;
}

int main()
{
    string name = ReadString();
    cout << "\nnumber of vowels are : " << NumberOfVowelInWord(name) << endl;
    

}
