
#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
short readnumber() {
    short num;
    do {
        cout << "plz enter positive number " << endl;
        cin >> num;
    } while (num < 0);
    return num;
}
enum random { smallLetter = 1, CapitalLetters = 2, SpecialChar = 3, digit = 4 };
char printRandom(random result) {
    if (result == random::smallLetter) {
        return char(RandomNumber(97, 122));

    }
    if (result == random::CapitalLetters) {
        return char(RandomNumber(65, 90));

    }
    if (result == random::SpecialChar) {
        return char(RandomNumber(32, 47));

    }if (result == random::digit) {
        return char(RandomNumber(48, 57));

    }
}
void print(short number) {
    int holder = 0;
    string key = "";
    int counter = 0;
    for (int i = 1; i <= number; i++)
    {
        counter++;
        for (int j = 0; j < 19; j++)
        {
            holder = RandomNumber(1, 4);
            key += (printRandom(random(holder)));
            holder = 0;
            if (key.length() == 19) {
                cout << "key[" << counter << "] : " << key << endl;
                key = "";
                break;
            }

        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    print(readnumber());
}

