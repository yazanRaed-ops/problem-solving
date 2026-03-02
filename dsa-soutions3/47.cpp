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

Cclient ReadClient() {
    Cclient client;
    cout << "\nEnter Account number: ";
    getline(cin >> ws, client.AccountNum);

    cout << "Enter Pin code: ";
    getline(cin, client.Pin);

    cout << "Enter Name: ";
    getline(cin, client.Name);

    cout << "Enter Phone: ";
    getline(cin, client.Phone);

    cout << "Enter Salary: ";
    cin >> client.salary;
    cin.ignore(); 

    return client;
}
vector<string> split(string delimeter,string line) {
    short pos = 0;
    string hold="";
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
              Client= (converLineToRecored(split("#//#", line)));
              client.push_back(Client);
          }
      } myfile.close();
      return client;

}void PrintClientRecord(Cclient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNum;
    cout << "| " << setw(10) << left << Client.Pin;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.salary;
}
void PrintAllClients(vector<Cclient> client) {
    cout << "\n\t\t\t\t\tClient List (" << client.size() << ") Client(s).";

    cout << "\n____________________________________________________________________________________";
    cout << "________________________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n____________________________________________________________________________________";
    cout << "________________________________________________________\n" << endl;
    for (Cclient& i : client) {
        PrintClientRecord(i);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}


int main() {
    vector<Cclient>clients = ReadReacoreds("myfile.txt");
    PrintAllClients(clients);
    return 0;
}
