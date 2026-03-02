#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;



void printArray(int array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %0*d", 1, array[i][j]);
            cout << "    ";
        }
        cout << endl;
    }
}
bool isscaler(int array[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        int firstnum = array[0][0];
        for (int j = 0; j < 3; j++)
        {
            if (i == j && array[i][j] != firstnum) {
                return false;
            }
            else if (i != j && array[i][j] != 0) {
                return false;
            }
        }
    }return true;
}



int main() {

    int array[3][3] = { {2,0,0}
    ,{0,2,0},{0,0,2} };

    cout << "matrix  : " << endl;
    printArray(array);
    cout << endl;
    if (isscaler(array)) {
        cout << "yes matrix is sclaer .";
    }
    else {
        cout << "no matrix is not scaler .";
    }


    return 0;
}