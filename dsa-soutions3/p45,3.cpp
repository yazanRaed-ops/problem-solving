
#include <iostream>
#include<vector>
#include<string>
using namespace std;
struct Sclient {
    string AccountNum;
    string PinCode;
    string name;
    string PhoneNum;
    float salary;

};
Sclient ClientData() {
    Sclient client;
    cout << "please enter client data : \n\n";
    cout << "Enter account number : ";
    getline(cin,client.AccountNum);
    cout << "\nEnter pin code : ";
    getline(cin,client.PinCode);
    cout << "\nEnter name : ";
    getline(cin,client.name);
    cout << "\nEnter phone number : ";
    getline(cin,client.PhoneNum);
    cout << "\nEnter salary : ";
    cin >> client.salary;
    return client;

}
string JoinString(string delimeter, Sclient client) {
    string fill = "";
    fill = client.AccountNum + delimeter + client.PinCode + delimeter +
        client.name + delimeter + client.PhoneNum + delimeter + to_string(client.salary);

    
    return fill;
}

int main()
{
    cout<<JoinString("#//#",ClientData());
}

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

int main() {
    cout << "\nPlease Enter Client Data: \n\n";
    sClient Client = ReadNewClient();
    cout << "\n\nClient Record for Saving is: \n";
    cout << ConvertRecordToLine(Client);
    system("pause>0");
    return 0;
}
