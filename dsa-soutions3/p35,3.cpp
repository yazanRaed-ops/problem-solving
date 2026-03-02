#include <iostream>
#include <string>

using namespace std;
string ReadString() {
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
void printWordFromString(string name) {
    string word = "";
    cout << "\nyour string are : \n";
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] != ' ') {
            word += name[i];
        }
        if (name[i] == ' ') {
            cout << word << endl;
            word = "";
        }
    }cout << word;
}
void PrintWordFromString(string word) {
    string delimeter = " ";
    short pos = 0;
    string sword;
    while ((pos = word.find(delimeter)) != std::string::npos) {
        if (sword != ""){
            cout<<sword<<endl;
        }
        word.erase(0, pos + delimeter.length());

    }
    if (word != "") {
        cout << word << endl;
    }
}
int main()
{
    string name = ReadString();
    printWordFromString(name);


}