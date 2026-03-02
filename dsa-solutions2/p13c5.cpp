
#include <iostream>
using namespace std;
int raednumber() {
    int number;
    do {
        cout << "plz enter positive number" << endl;
        cin >> number;

    } while (number < 0);
    return number;
}
void printnumber(int number) {
    for (int i = 0; i<=number;i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }cout << endl;
    }
}
int main()
{
    printnumber(raednumber());
}
