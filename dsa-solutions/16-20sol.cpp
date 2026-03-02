 // 16-20sol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//void read(float& a, float& d) {
//    cout << "enter the side area \n";
//    cin >> a;
//    cout << "enter the diagonal\n";
//    cin >> d;
//}
//float calcractangleAreaBysideanddiagonal(float a, float d) {
//    float area = a * sqrt(pow(d, 2) - pow(a, 2));
//    return area;
//}
//void printArea(float area) {
//    cout << "the area is : " << area << endl;
//}
//void read(float& a, float& h) {
//    cout << "enter the base " << endl;
//    cin >> a;
//    cout << "enter the hight" << endl;
//    cin >> h;
//}
//float calcTriangleArea(float a, float h) {
//    float area = 0.5 * a * h;
//    return area;
//}
//void printArea(float area) {
//    cout << "the triangle area is : " << area;
//    cout << endl;
//}
//float readRadious() {
//    cout << "enter Radious" << endl;
//    float R;
//    cin >> R;
//    return R;
//}
//float CirccleArea(float R) {
//    const float PI = 3.14;
//    float area = PI * pow(R, 2);
//    return area;
//}
//void printArea(float area) {
//    cout << "the area of the circle is : " << area << endl;
//
//}
//float readDiameter() {
//    float Diameter;
//    cout << "plz enter Diameter " << endl;
//    cin >> Diameter;
//    return Diameter;
//
//}
//float CircleAreaByDiameter(float Diameter) {
//    const float PI = 3.14;
//    float area = (PI * pow(Diameter, 2)) / 4;
//    return area;
//
//}
//void prinArea(float area) {
//    cout << "the circle area by Diameter is : " << area;
//
//}
float readSquareSide() {
    float A;
    cout << "plz enter the square side length "<< endl;
    cin >> A;
    return A;
}
float CalcAreaOfCircleInSquare(float A) {
    const float PI = 3.14;
    float area = PI * pow((A / 2), 2);
    return area;

}
void printArea(float area) {
    cout << "the area is : " << area;
}

    
int main()
{
    //float a, b;
    //read(a, b);
    //printArea(calcractangleAreaBysideanddiagonal(a, b));
    //float a, h;
    //read(a, h);
    //printArea(calcTriangleArea(a, h));
    //----------------------------------
    //printArea(CirccleArea(readRadious()));
    //------------------------------------
    //prinArea(CircleAreaByDiameter(readDiameter()));
    //-----------------------------------------------
  //printArea(CalcAreaOfCircleInSquare(readSquareSide()));


}   

