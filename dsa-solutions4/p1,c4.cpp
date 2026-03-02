#include <iostream>
#include <string>
using namespace std;

string NumberToText(int num) {
    if (num == 0) {
        return "zero";
    }
    if (num >= 1 && num <= 19) {
        string number []= { "", "One","Two","Three","Four","Five","Six","Seven",
                        "Eight","Nine","Ten","Eleven","Twelve","Thirteen",
                        "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
        return number[num] + " ";
    }
    if (num >= 20 && num <= 99) {
        string tens[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return tens[num / 10] + " " + NumberToText(num % 10);;
    }
    if (num >= 100 && num <= 199) {
        return "one Hundred " + NumberToText(num % 100);
    }
    if (num >= 200 && num <= 999) {
        return NumberToText(num / 100) + " Hundred " + NumberToText(num % 100);
    }
    if (num >= 1000 && num <= 1999) {
        return "one thounsand " + NumberToText(num % 1000);
    }
    if (num >= 2000 && num <= 999999) {
        return NumberToText(num / 1000) + " thounsand " + NumberToText(num % 1000);
    }
    if (num >= 1000000 && num <= 1999999) {
        return "one million " + NumberToText(num % 1000000);
    }
    if (num >= 2000000 && num <= 999999999) {
        return NumberToText(num / 1000000) + " million " + NumberToText(num % 1000000);
    }
    if (num >= 1000000000 && num <= 1999999999) {
        return "one billion " + NumberToText(num % 1000000000);
    }
    return NumberToText(num / 1000000000) + " billion " + NumberToText(num % 1000000000);
}
int ReadNumber() {
    int Number;
    cout << "\nEnter a Number? ";
    cin >> Number;
    return Number;
}

int main() {
    int Number = ReadNumber();
    cout << NumberToText(Number);
    system("pause>0");
    return 0;
}
