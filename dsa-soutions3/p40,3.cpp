

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
string JoinString(string array[], short length,string delimeter) {
	string fill = "";
	for (short i = 0; i < length; i++)
	{
		if (i != length - 1) {
			fill += (array[i] + delimeter);
		}
		else {
			fill += array[i];
		}
	}
	return fill;
}
int main()
{
	vector <string>vec = { "yazan","raed","ata","alsyouri" };
	string array[] = { "yazan","raed","ata","alsyouri" };
	cout << JoinString(vec, ",")<<endl;
	cout << JoinString(array, 4, ":");
}