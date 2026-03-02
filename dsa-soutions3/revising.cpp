// revising.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include <string>
#include<vector>
using namespace std;
void ReadFile(const string& fileName, vector<string>&vec) {
   
    fstream myfile;
    myfile.open(fileName, ios::in); 
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            vec.push_back(line);
        }
        myfile.close();
    }
    else {
        cout << "Error: Unable to open file " << fileName << endl;
    }
   
}
void deletRecoredFromFile(string fileName,string recored,string change) {
    vector <string>vec;
      ReadFile(fileName,vec);
    for (string& i : vec) {
        if (i == recored) {
            i = change;
        }
    }
    SaveVectorToFile(fileName, vec);

}
void SaveVectorToFile(string fileName, vector<string>vec) {
    fstream myfile;
    myfile.open(fileName, ios::out );
    if (myfile.is_open()) {

        for (string& i : vec) {
            if (i != "") {
                myfile << i<<endl;

            }
           
        }
    }myfile.close();
}
void printFile(string fileName) {
    fstream myfile;
    myfile.open(fileName, ios::in);
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            cout << line << endl;
        }
    }myfile.close();
}
int main()
{
   // vector <string> vFileContenet{ "Ali","Shadi","Maher","Fadi","Lama" };
   // SaveVectorToFile("MyFile.txt", vFileContenet);

}
