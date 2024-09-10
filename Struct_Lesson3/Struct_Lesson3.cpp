#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PaymentRecord {
    string firstName;
    string lastName;
    string date;
    int amount;
};

void addRecord() {
    ofstream file("List.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error when opening the file!" << endl;
        return;
    }

    PaymentRecord record;
    cout << "Enter a name: ";
    cin >> record.firstName;
    cout << "Enter last name: ";
    cin >> record.lastName;
    cout << "Enter the date (DD.MM.YYYY): ";
    cin >> record.date;
    cout << "Enter the payout amount: ";
    cin >> record.amount;

    file << record.firstName << " " << record.lastName << " "
        << record.date << " " << record.amount << endl;

    file.close();
    cout << "The record has been added to the statement." << endl;
}

void listRecords() {
    ifstream file("List.txt");
    if (!file.is_open()) {
        cerr << "Error when opening the file!" << endl;
        return;
    }

    vector<PaymentRecord> records;
    PaymentRecord record;

    while (file >> record.firstName >> record.lastName >> record.date >> record.amount) {
        records.push_back(record);
    }

    file.close();

    for (const auto& r : records) {
        cout << "Name: " << r.firstName << " " << r.lastName
            << ", Date: " << r.date
            << ", Amount: " << r.amount << " RUB" << endl;
    }
}

int main() {
    string command;
    cout << "Enter command (list/add): ";
    cin >> command;

    if (command == "list") {
        listRecords();
    }
    else if (command == "add") {
        addRecord();
    }
    else {
        cout << "Invalid command!" << endl;
    }

    return 0;
}
