#include <iostream>
#include <vector>
using namespace std;

struct Acc {
    string username = "";
    int pass = 0;
    Acc(string name, int p) {
        username = name;
        pass = p;
    }
};

vector<Acc> accounts;

void create_acc() {
    cout << "ENTER YOUR USERNAME: ";
    string username;
    cin >> username;
    int pass;
    cin >> pass;
    Acc new_acc(username, pass);
    accounts.push_back(new_acc);
}

Acc* login() {
    cout << "Log in using your credentials: " << endl;
    int size = accounts.size();
    string name;
    cout << "Enter your username: ";
    cin >> name;
    int pass;
    cout << "Enter your password: ";
    cin >> pass;
    for (int i = 0; i < size; i++) {
        if (accounts[i].username == name && accounts[i].pass == pass) {
            cout << "You are logged in!" << endl;
            return &accounts[i];
        }
    }
    cout << "Username or Password incorrect." << endl;
    return nullptr;
}

void check_status() {
    Acc* new_acc = login();
    if (new_acc != nullptr) {
        cout << new_acc->username << endl;
        cout << new_acc->pass << endl;
    }
}

void check_balance() {}

void Menu() {
    cout << "Available Options" << endl;
    cout << "Create an Account: [1]" << endl;
    cout << "Log in: [2]" << endl;
    cout << "Check your Account Status: [3]" << endl;
    cout << "Check your Available Balance: [4]" << endl;
    cout << "Exit: [5]" << endl;
}

int main() {
    int choice;
    do {
        Menu();
        cin >> choice;
        switch (choice) {
            case 1:
                create_acc();
                break;
            case 2:
                login();
                break;
            case 3:
                check_status();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
