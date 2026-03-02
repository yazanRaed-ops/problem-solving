
#include <iostream>
#include<cctype>
#include <string>
using namespace std;
string ReadString() {
    cout << "plz enter your string \n";
    string name;
    getline(cin, name);
    return name;
}
string RemovePancuation(string sentance) {
    for (short i = 0; i < sentance.length(); i++)
    {
        if (ispunct(sentance[i])) {
            sentance.erase(i, 1);
            i--;
        }
    }
    return sentance;
}
string removepunctuation(string name) {
    string name2 = "";
    for (short i = 0; i < name.length(); i++)
    {
        if (!ispunct(name[i])) {
            name2 += name[i];
        }
    }
    return name2;
}
int main()
{
    string name = ReadString();
    cout << "\n the original line is : \n" << name << endl;
    cout << "\n the no pancuation line is : \n" << RemovePancuation(name) << endl;
    cout << "\n the no pancuation line is : \n" << removepunctuation(name) << endl;

}
