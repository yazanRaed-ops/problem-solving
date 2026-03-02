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
    myfile.open("myfile.txt", ios::out|ios::app);
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


int main() {
    addClient();
}
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//using namespace std;
//
//const string ClientsFileName = "Clients.txt";
//
//struct sClient {
//    string AccountNumber;
//    string PinCode;
//    string Name;
//    string Phone;
//    double AccountBalance;
//};
//
//sClient ReadNewClient() {
//    sClient Client;
//    getline(cin >> ws, Client.AccountNumber);
//    getline(cin, Client.PinCode);
//    getline(cin, Client.Name);
//    getline(cin, Client.Phone);
//    cin >> Client.AccountBalance;
//    cin.ignore();
//    return Client;
//}
//
//string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
//    string stClientRecord = "";
//    stClientRecord += Client.AccountNumber + Seperator;
//    stClientRecord += Client.PinCode + Seperator;
//    stClientRecord += Client.Name + Seperator;
//    stClientRecord += Client.Phone + Seperator;
//    stClientRecord += to_string(Client.AccountBalance);
//    return stClientRecord;
//}
//
//void AddDataLineToFile(string FileName, string stDataLine) {
//    fstream MyFile;
//    MyFile.open(FileName, ios::out | ios::app);
//    if (MyFile.is_open()) {
//        MyFile << stDataLine << endl;
//        MyFile.close();
//    }
//}
//
//void AddNewClient() {
//    sClient Client = ReadNewClient();
//    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
//}
//
//void AddClients() {
//    char AddMore = 'Y';
//    do {
//        cout << "Adding New Client:\n\n";
//        AddNewClient();
//        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
//        cin >> AddMore;
//        cin.ignore();
//    } while (toupper(AddMore) == 'Y');
//}
//
//int main() {
//    AddClients();
//    return 0;
//}
