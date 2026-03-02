#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient ReadNewClient() {
    sClient Client;

    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
void addClient() {
    fstream myfile;
    myfile.open("myfile.txt", ios::out | ios::app);
    if (myfile.is_open()) {
        char ch;
        do {
            cout << "\n=== Add New Client ===\n\n";
            sClient client = ReadNewClient();

            myfile << ConvertRecordToLine(client) << endl;

            cout << "\nClient added successfully! Do you want to add more clients (y/n)? ";
            cin >> ch;
            cin.ignore();

        } while (ch == 'y' || ch == 'Y');

        myfile.close();
    }


}
sClient converLineToRecored(vector<string>vec) {
    sClient client;
    client.AccountNumber = vec[0];
    client.PinCode = vec[1];
    client.Name = vec[2];
    client.Phone = vec[3];
    client.AccountBalance = stoi(vec[4]);
    return client;
}
void printFilecontent() {
    fstream myfile;
    myfile.open("myfile.txt", ios::in);
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            cout << line << endl;
        }
    }
}


int main() {
    addClient();
}