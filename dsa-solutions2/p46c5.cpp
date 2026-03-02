
#include <iostream>
using namespace std;
float ReadNumber()
{
    float Number;

    cout << "Please enter a number? ";
    cin >> Number;
    return Number;
}
float Fracction(float number) {
    return number - (int)number;
}
int Round(float number) {
    if (Fracction(number) >= 0.5) {
        return (int)number + (1);
    }
    else {
        return int(number);
    }
}



int main()
{
    float num = ReadNumber();
    cout << Round(num);

}

#include <iostream>
using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyRound(float Number)
{
    int IntPart = int(Number);
    float FractionsPart = GetFractionPart(Number);

    if (abs(FractionsPart) >= 0.5)
    {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
    {
        return IntPart;
    }
}

float ReadNumber()
{
    float Number;
    cout << "Please enter a float number? ";
    cin >> Number;
    return Number;
}

int main()
{
    float Number = ReadNumber();
    cout << "My Round Result : " << MyRound(Number) << endl;
    cout << "C++ Round Result: " << round(Number) << endl;
    return 0;
}