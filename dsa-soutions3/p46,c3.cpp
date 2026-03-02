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
vector<string> splitString(string delimeter, string name) {
    vector<string> vec;
    short pos = 0;
    string hold = "";
    while ((pos = name.find(delimeter)) != std::string::npos) {
        hold = name.substr(0, pos);
        if (hold != "") {
            vec.push_back(hold);
        }
        name.erase(0, pos + delimeter.length());

    }
    if (name != ""){
        vec.push_back(name);
    }
    return vec;
}
void PrintClientRecord(Sclient Client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccount Number : " << Client.AccountNum;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.name;
    cout << "\nPhone          : " << Client.PhoneNum;
    cout << "\nAccount Balance: " << Client.salary;
}
Sclient converLineToRecored(vector<string>vec) {
    Sclient client;
    client.AccountNum = vec[0];
    client.PinCode = vec[1];
    client.name = vec[2];
    client.PhoneNum = vec[3];
    client.salary = stoi(vec[4]);
    return client;
}



int main()
{
    cout << "Line recored is : \n";
    string recored = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
    cout << recored << endl;
    PrintClientRecord(converLineToRecored(splitString("#//#", recored)));


}
