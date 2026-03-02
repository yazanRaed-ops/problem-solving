#include <iostream>
#include <string>
#include<vector>
using namespace std;
string ReadString() {
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

vector<string> splitstring(string word,string delimeter) {
    vector<string> vec;
    short pos = 0;
    string sword;
    
    while ((pos = word.find(delimeter)) != std::string::npos) {
        sword = word.substr(0, pos);
        if (sword != "") {
            vec.push_back(sword);
        }
        word.erase(0, pos + delimeter.length());

    }
    if (word != "") {
        vec.push_back(word);
    }
    return vec;
}
short countTokens(vector<string>vec) {
    short count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        count++;
    }return count;
}
void printvector(vector<string> vec) {
    for (string& i : vec) {
        cout << i << endl;
    }
}
int main()
{
    string name = ReadString();
    
    vector<string>vec = splitstring(name, " ");
    cout << "tokens = " << countTokens(vec) << endl;
    printvector(vec);

}