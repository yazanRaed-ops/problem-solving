// p48cc5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
float ReadNumber()
{
    float Number;  
    
    cout << "Please enter a number? ";
    cin >> Number;  

    return Number;  
}
int myfloor(float number) {
    if (number >= 0) {
        return int(number);
    }
    else {
        return int(number) - 1;
    }
}
int main()
{
    float Number = ReadNumber(); 

   
    cout << "My MyFloor Result : " << myfloor(Number) << endl;

  
    cout << "C++ floor Result  : " << floor(Number) << endl;

    return 0;
}
