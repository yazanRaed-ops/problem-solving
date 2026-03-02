
#include <iostream>
using namespace std; 
int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message << endl; 
        cin >> Number;          
    } while (Number <= 0);       
    return Number;  
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void array1(int arr[100], int& length) {
    cout << "array before shuffle : " << endl;
    for (int i = 0; i < length; i++)
    {
        arr[i] = i+1;
        
    }
}
int randomnumber(int from,int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}
void shuffleArray(int length, int arr[100]) {
    for (int i = 0; i < length; i++)
    {
        swap(arr[randomnumber(1, length) - 1], arr[randomnumber(1, length) - 1]);

    }cout << endl;
    cout << "array after shuffle : " << endl;
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n"; 
}
int main()
{
    int arr[100];
    int length = ReadPositiveNumber("enter number : ");
    array1(arr, length);
    PrintArray(arr, length);
    shuffleArray(length, arr);
    PrintArray(arr, length);



}
