#include <iostream>
using namespace std;
float ReadNumber()
{
    float Number;

    cout << "Please enter a number? ";
    cin >> Number;

    return Number;
}
int myceil(float number) {
    if (number == int(number)) {
        return number;
    }
    if (number >= 0) {
        return int(number)+1;
    }
    else {
        return int(number) ;
    }
}
int main()
{
    float Number = ReadNumber();


    cout << "My MyFloor Result : " << myceil(Number) << endl;


    cout << "C++ floor Result  : " << ceil(Number) << endl;

    return 0;
}
