#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<iomanip>
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
        }line.erase(0, pos + delimeter.length());
    }
    if (line != "") {
        vec.push_back(line);
    }return vec;
}
Cclient converLineToRecored(vector<string>vec) {
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
    vector<Cclient>client;
    myfile.open(file, ios::in);
    if (myfile.is_open()) {
        string line;
        Cclient Client;
        while (getline(myfile, line)) {
            Client = (converLineToRecored(split("#//#", line)));
            client.push_back(Client);
        }
    } myfile.close();
    return client;

}
string EnterAccountnumber() {
    cout << "plz enter your Account number : ";
    string AcccountNumber;
    getline(cin, AcccountNumber);
    return AcccountNumber;
}
bool checkClient(Cclient client,string AccountNum) {
    if (client.AccountNum == AccountNum) {
        return true;
    }
    return false;
}
void PrintClientCard(Cclient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "Account Number  : " << Client.AccountNum << endl;
    cout << "Pin Code        : " << Client.Pin << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.salary << endl;
}
void searchClient(vector<Cclient>&vec) {
    string hold = EnterAccountnumber();
    bool found = false;
    for (Cclient& i : vec) {
        if (checkClient(i, hold)) {
            PrintClientCard(i);
            found = true;
            break;
        }
        
    }if (found==false) {
        cout << "\nClient with Account Number (" << hold << ") is Not Found!" << endl;
    }
}



int main() {
    vector<Cclient>clients = ReadReacoreds("myfile.txt");
    searchClient(clients);
    return 0;
}
