#include <iostream>
using namespace std;
float ReadNumber()
{
    float Number;

    cout << "Please enter a number? ";
    cin >> Number;

    return Number;
}
float Mysqrt(float number) {
    if (number > 0) {
        return pow(number, 0.5);
   }
}
int main()
{
    float Number = ReadNumber();


    cout << "My MyFloor Result : " << Mysqrt(Number) << endl;


    cout << "C++ floor Result  : " << sqrt(Number) << endl;

    return 0;
}
