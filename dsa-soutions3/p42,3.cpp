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

string SwapWords(string word1, string word2, string name) {
    vector<string> vec = SplitString(name, " ");
    string fill = "";

    for (short i = 0; i < vec.size(); i++) {
        if (vec[i] == word1) vec[i] = word2;
        
        fill += vec[i] + " ";
    }

    
    return fill.substr(0,fill.length()-1);
}
string replaceWords(string name, string worldToReplace, string replaceTo) {
    short pos = name.find(worldToReplace);
    while (pos != std::string::npos) {
        name.replace(pos, worldToReplace.length(), replaceTo);
        name.find(worldToReplace);
    }
    return name;
}

int main() {
    string name = ReadString();
    cout << SwapWords("yazan", "raed", name) << endl;
}
