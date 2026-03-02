
#include <iostream>
#include<string>
#include<vector>
using namespace std;

string ReadString() {
    cout << "plz enter your string : " << endl;
    string name;
    getline(cin, name);
    return name;
}
vector<string> SplitString(string name,string delimeter) {
    short pos = 0;
    string word = "";
    vector<string> vec;
    while ((pos = name.find(delimeter)) != std::string::npos) {
        word = name.substr(0, pos);
        if (word != " ") {
            vec.push_back(word);
        }
        name.erase(0, pos + delimeter.length());

    }
    if (name != " ") {
        vec.push_back(name);
    }
    return vec;
}
string PrintStringInReverse(vector<string>vec, string delimeter) {
    cout << "\nstring after reversing the word :  \n";
    string fill = "";
    for (short i = vec.size() - 1; i >= 0; i--)
    {
        if (i != 0) {
            fill += vec[i] + delimeter;
        }
        else {
            fill += vec[i];
        }

    }return fill;
}
string rverceWordsInString(string name) {
    vector <string>vec;
    string S2 = "";
    vec = SplitString(name, " ");
    vector<string>::iterator iter = vec.end();
    while (iter != vec.begin()) {
        iter--;
        S2 += *iter + " ";
    }
    return S2.substr(0, S2.length() - 1);
}
int main()
{
    string name = ReadString();
    cout << PrintStringInReverse(SplitString(name, " "), " ") << endl;
    cout << rverceWordsInString(name);
}

