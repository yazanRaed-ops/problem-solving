#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Cclient {
    string AccountNum;
    string Pin;
    string Name;
    string Phone;
    float salary;
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

Cclient converLineToRecored(vector<string> vec) {
    Cclient client;
    client.AccountNum = vec[0];
    client.Pin = vec[1];
    client.Name = vec[2];
    client.Phone = vec[3];
    client.salary = stof(vec[4]);
    return client;
}

vector<Cclient> ReadReacoreds(string file) {
    fstream myfile;
    vector<Cclient> client;
    myfile.open(file, ios::in);
    if (myfile.is_open()) {
        string line;
        Cclient Client;
        while (getline(myfile, line)) {
            Client = converLineToRecored(split("#//#", line));
            client.push_back(Client);
        }
    }
    myfile.close();
    return client;
}

string ConvertRecordToLine(Cclient Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNum + Seperator;
    stClientRecord += Client.Pin + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.salary);
    return stClientRecord;
}

string EnterAccountnumber() {
    cout << "plz enter your Account number : ";
    string AcccountNumber;
    getline(cin, AcccountNumber);
    return AcccountNumber;
}

bool checkClient(Cclient client, string AccountNum) {
    return client.AccountNum == AccountNum;
}

void PrintClientCard(Cclient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "Account Number  : " << Client.AccountNum << endl;
    cout << "Pin Code        : " << Client.Pin << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.salary << endl;
}

vector<Cclient> removeClientFromVector(vector<Cclient>& vec, Cclient client) {
    vector<Cclient> newVec;
    for (Cclient& i : vec) {
        if (i.AccountNum != client.AccountNum) {
            newVec.push_back(i);
        }
    }
    return newVec;
}

void DeletClient(vector<Cclient>& vec) {
    string hold = EnterAccountnumber();
    bool found = false;
    char ch;
    for (Cclient& i : vec) {
        if (checkClient(i, hold)) {
            PrintClientCard(i);
            found = true;
            cout << "\n\nare you sure you want to delete this client?(y/n) ? ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                vec = removeClientFromVector(vec, i);
                cout << "\n\nClient deleted successfully.";
            }
            break;
        }
    }
    if (found == false) {
        cout << "\nClient with Account Number (" << hold << ") is Not Found!" << endl;
    }
}

void FileAfterDeleting(string file, vector<Cclient>& vec) {
    fstream myfile;
    myfile.open(file, ios::out);
    if (myfile.is_open()) {
        for (Cclient& i : vec) {
            myfile << ConvertRecordToLine(i, "#//#") << endl;
        }
    }
    myfile.close();
}

int main() {
    vector<Cclient> clients = ReadReacoreds("myfile.txt");
    DeletClient(clients);
    FileAfterDeleting("myfile.txt", clients);
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
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

vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos) {
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

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
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

vector<sClient> LoadCleintsDataFromFile(string FileName) {
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {
        string Line;
        sClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientCard(sClient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client) {
    for (sClient C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    for (sClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    if (MyFile.is_open()) {
        for (sClient C : vClients) {
            if (C.MarkForDelete == false) {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

string ReadClientAccountNumber() {
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

int main() {
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
    system("pause>0");
    return 0;
}
