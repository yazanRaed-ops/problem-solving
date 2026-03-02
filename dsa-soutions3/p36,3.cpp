#include <iostream>
#include <string>

using namespace std;
string ReadString() {
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

short PrintWordFromString1(string word) {
    string delimeter = " ";
    short pos = 0;
    string sword;
    short count = 0;
    while ((pos = word.find(delimeter)) != std::string::npos) {
        sword = word.substr(0, pos);
        if (sword != ""){
            count++;
        }
        word.erase(0, pos + delimeter.length());

    }
    if (word != "") {
        count++;
    }
    return count;
}
int main()
{
    string name = ReadString();
   cout<<"the number of words in the string is : "<< PrintWordFromString1(name);


}