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
bool isIdentical(int array[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j && array[i][j] != 1) {
                return false;
            }
            else if (i != j && array[i][j] != 0) {
                return false;
            }
        }
    }return true;
}



int main() {
    
    int array[3][3] = { {1,0,0}
    ,{0,1,0},{0,0,1}};
   
    cout << "matrix  : " << endl;
    printArray(array);
    cout << endl;
    if (isIdentical(array)) {
        cout << "yes matrix is identical .";
    }
    else {
        cout << "no matrix is not identical .";
    }
   
    
    return 0;
}