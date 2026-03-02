#include <iostream>
using namespace std;
string readletter() {
	string letter = "";
	cout << "plz enter the password" << endl;
	cin >> letter;
	return letter;
}
void printnumber(string letter) {
    
	string word = "";
	int trial = 1;
  

	for (int i = 65; i <=90;  i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{


				word += char(i);
				word += char(j);
				word += char(k);

				cout << "trail : " << trial++ << " :" << word << endl;
				//OR U COULD:
				//if (word == letter) {
				//	return true;
				//}
				//word = "";

				if (letter == word) {
					break;
				}
				word = "";
			}if (letter == word) {
				break;
			}

		}if (letter == word) {
			break;
		}
		

		}
	}

int main()
{
	printnumber(readletter());
}
