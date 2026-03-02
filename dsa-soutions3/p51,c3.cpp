#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Client {
    string AccountNum;
    string Pin;
    string Name;
    string Phone;
    float Salary;
};


vector<string> split(string delimeter, string line) {
    short pos = 0;
    string hold = "";
    vector<string> vec;
    while ((pos = line.find(delimeter)) != std::string::npos) {
        hold = line.substr(0, pos);
        if (hold != "") {
            vec.push_back(hold);
        }
        line.erase(0, pos + delimeter.length());
    }
    if (line != "") {
        vec.push_back(line);
    }
    return vec;
}

Client convertLineToRecord(vector<string> vec) {
    Client client;
    client.AccountNum = vec[0];
    client.Pin = vec[1];
    client.Name = vec[2];
    client.Phone = vec[3];
    client.Salary = stof(vec[4]);
    return client;
}

vector<Client> ReadRecords(string file) {
    fstream myfile;
    vector<Client> clients;
    myfile.open(file, ios::in);
    if (myfile.is_open()) {
        string line;
        Client client;
        while (getline(myfile, line)) {
            client = convertLineToRecord(split("#//#", line));
            clients.push_back(client);
        }
    }
    myfile.close();
    return clients;
}

string ConvertRecordToLine(Client client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += client.AccountNum + Seperator;
    stClientRecord += client.Pin + Seperator;
    stClientRecord += client.Name + Seperator;
    stClientRecord += client.Phone + Seperator;
    stClientRecord += to_string(client.Salary);
    return stClientRecord;
}

string EnterAccountNumber() {
    cout << "Please enter your Account number : ";
    string AccountNumber;
    getline(cin, AccountNumber);
    return AccountNumber;
}

bool checkClient(Client client, string AccountNum) {
    return client.AccountNum == AccountNum;
}

void PrintClientCard(Client client) {
    cout << "\nThe following are the client details:\n";
    cout << "Account Number  : " << client.AccountNum << endl;
    cout << "Pin Code        : " << client.Pin << endl;
    cout << "Name            : " << client.Name << endl;
    cout << "Phone           : " << client.Phone << endl;
    cout << "Account Balance : " << client.Salary << endl;
}

void changeInfo(Client& client) {
    cout << "Enter PinCode? ";
    getline(cin, client.Pin);

    cout << "Enter Name? ";
    getline(cin, client.Name);

    cout << "Enter Phone? ";
    getline(cin, client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> client.Salary;
    cin.ignore(); 
}

void changeClientInfo(vector<Client>& vec) {
    string accountNum = EnterAccountNumber();
    bool found = false;
    char ch;

    for (Client& client : vec) {
        if (checkClient(client, accountNum)) {
            PrintClientCard(client);
            found = true;

            cout << "\n\nAre you sure you want to update this client? (y/n) : ";
            cin >> ch;
            cin.ignore();

            if (ch == 'y' || ch == 'Y') {
                changeInfo(client);  
                cout << "\n\nClient updated successfully.";
            }
            break;
        }
    }

    if (!found) {
        cout << "\nClient with Account Number (" << accountNum << ") is not found!" << endl;
    }
}

void FileAfterUpdating(string file, vector<Client>& vec) {
    fstream myfile;
    myfile.open(file, ios::out);
    if (myfile.is_open()) {
        for (Client& client : vec) {
            myfile << ConvertRecordToLine(client, "#//#") << endl;
        }
    }
    myfile.close();
}

int main() {
    vector<Client> clients = ReadRecords("myfile.txt");
    changeClientInfo(clients);
    FileAfterUpdating("myfile.txt", clients);
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

// Split string by delimiter
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}

// Convert line from file to sClient
sClient ConvertLineToRecord(string Line, string Seperator = "#//#") {
    sClient Client;
    vector<string> vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

// Convert sClient to line for file
string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

// Load clients from file
vector<sClient> LoadClientsDataFromFile(string FileName) {
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {
        string Line;
        sClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

// Print client details
void PrintClientCard(sClient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

// Find client by account number
bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client) {
    for (sClient C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

// Change client record
sClient ChangeClientRecord(string AccountNumber) {
    sClient Client;
    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

// Save clients to file
vector<sClient> SaveClientsDataToFile(string FileName, vector<sClient> vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite file

    if (MyFile.is_open()) {
        for (sClient C : vClients) {
            if (!C.MarkForDelete) { // write only non-deleted records
                string DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

// Update client by account number
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            for (sClient& C : vClients) {
                if (C.AccountNumber == AccountNumber) {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
    return false;
}


string ReadClientAccountNumber() {
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}


int main() {
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

    system("pause>0");
    return 0;
}
