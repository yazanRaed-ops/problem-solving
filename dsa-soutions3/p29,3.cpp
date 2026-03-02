// p29,3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
enum letter{small=0,capital=1,all=2};
using namespace std;
short countLetter(string name, letter charachter) {
    short count=0;
    if (charachter == letter::all) {
        return name.length();
    }
    for (short i = 0; i < name.length(); i++)
    {
        if (charachter == letter::capital && isupper(name[i])) {
            count++;
        }
    }

     for (short i = 0; i < name.length(); i++)
     {
         if (charachter == letter::small && islower(name[i])) {
             count++;
         }
     }
     return count;

    
}
string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
short CapitalLetterCount(string word) {
    short count = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (isupper(word[i])) {
            count++;
        }
    }return count;
}
short SmallLetterCount(string word) {
    short count = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (islower(word[i])) {
            count++;
        }
    }return count;
}

int main()
{
    string word = ReadString();

    cout << "\nString length = " << word.length() << endl;
    cout << "\nCapital letters count = " << CapitalLetterCount(word);
    cout << "\nSmall letters count = " << SmallLetterCount(word);
}
