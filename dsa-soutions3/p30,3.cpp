
#include <iostream>
#include <string>

using namespace std;
short countLetter(string name,char letter ,bool isMatch=true) {
    short count=0;
    
    for (short i = 0; i < name.length(); i++)
    {
        if (isMatch) {
            if (name[i] == letter) {
                count++;
            }
        }
        else {
            if (towlower(name[i]) == tolower(letter)) {
                count++;
            }
        }
    }
    return count;


}

short countinvertOfCharachter(char ch, int count,string word) {
    
    if (islower(ch)) {
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == toupper(ch)) {
                count++;
            }
        }
    }
    else {
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == tolower(ch)) {
                count++;
            }
        }

    }return count;
}
string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
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


int main()
{
    string word = ReadString();
    char ch = ReadCharacter();
    cout << "letter '" << ch << "' count = " << countLetter(word, ch)<<endl;
    cout << "letter '" << char(tolower(ch)) << "' OR '" << char(toupper(ch)) << "' count = " << countinvertOfCharachter(ch, countLetter(word, ch), word);
   
}

