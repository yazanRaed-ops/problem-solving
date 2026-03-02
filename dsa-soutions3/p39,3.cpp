// p39,3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
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
int main()
{
	vector <string>vec = { "yazan","raed","ata","alsyouri" };
	cout << JoinString(vec, ",");
}

#include <string>
#include <iostream>
#include <vector>
using namespace std;

string JoinString(vector<string> vString, string Delim) {
	string S1 = "";
	for (string& s : vString) {
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

int main() {
	vector<string> vString = { "Mohammed","Faid","Ali","Maher" };
	cout << "\nVector after join: \n";
	cout << JoinString(vString, " ");
	system("pause>0");
}
