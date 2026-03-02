#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString() {
    cout << "plz enter your string : " << endl;
    string name;
    getline(cin, name);
    return name;
}

vector<string> SplitString(string name, string delimeter) {
    short pos = 0;
    string word = "";
    vector<string> vec;
    while ((pos = name.find(delimeter)) != string::npos) {
        word = name.substr(0, pos);
        if (!word.empty()) vec.push_back(word);
        name.erase(0, pos + delimeter.length());
    }
    if (!name.empty()) vec.push_back(name);
    return vec;
}
string JoinString(vector <string>vec, string delimeter) {
    string fill = "";
    for (short i = 0; i < vec.size(); i++)
    {
        if (i != vec.size() - 1) {
            fill += (vec[i] + delimeter);
        }
        else {
            fill += vec[i];
        }
    }
    return fill;
}
string WordToLower(string name) {
    for (short i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    return name;
}
string SwapWords(string word1, string word2, string name,bool match=true) {
    vector<string> vec = SplitString(name, " ");

    for (short i = 0; i < vec.size(); i++) {
        if (match) {
            if (vec[i] == word1) vec[i] = word2;
        }
        else if(WordToLower(vec[i]) == WordToLower(word1)) {
            vec[i] = word2;
        }
        
    }
    return JoinString(vec, " ");
   
}
int main() {
    string name = ReadString();
    cout << SwapWords("yazan", "raed", name) << endl;
    cout << "\n no case match : \n";
    cout << SwapWords("yazan", "raed", name, false);
}
