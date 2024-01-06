#include <iostream>
#include <vector>
using namespace std;

struct Acc
{
    string username = "";
    int pass = 0;
    Acc(string name, int p)
    {
        username = name;
        pass = p;
    }
};

vector<Acc> accounts; // Store created accounts

void create_acc()
{
    string username;
    int pass;
    cout << "ENTER YOUR USERNAME: ";
    cin >> username;
    cout << "ENTER YOUR PASSWORD: ";
    cin >> pass;
    Acc new_acc(username, pass);
    accounts.push_back(new_acc); // Store the new account
}

void login() {}

void check_status() {}

void check_balance() {}

void Menu()
{
    cout << "Available Options" << endl;
    cout << "Create an Account: [1]" << endl;
    cout << "Check your Account Status: [2]" << endl;
    cout << "Check your Available Balance: [3]" << endl;
    cout << "Exit: [4]" << endl;
}

int main()
{
    int choice;
    do
    {
        Menu();
        cin >> choice;

        switch (choice)
        {
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
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
