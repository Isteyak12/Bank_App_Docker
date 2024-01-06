#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Acc
{
    string username = "";
    int pass = 0;
    Acc(string name, int p)
    {
        username = username;
        pass = p;
    }
};

// using vector to  collect data
// vector is like an arraylist in java
// this program is oop based

vector<Acc> accounts;

void create_acc()
{
    cout << "ENTER YOUR USERNAME: ";
    string username;
    cin >> username;
    int pass;
    cin >> pass;
    Acc new_acc(username, pass);
    accounts.push_back(new_acc);
}

vector<Acc> login()
{
    cout << "Log in using your credentials: " << endl;
    int size = accounts.size();
    string name;
    cout << "Enter your username: ";
    cin >> name;
    int pass;
    cout << "Enter your password: ";
    cin >> pass;
    for (int i; i < size; i++)
    {
        if (accounts[i].username == name && accounts[i].pass == p)
        {
            cout << "You are logged in!" << endl;
            return accounts[i];
        }
    }
    cout << "Username or Password incorrect." << endl;
}

void check_status()
{
    vector<Acc> new_acc[0] = login();
    cout << new_acc[0].username;
    cout << new_acc[0].pass;
}

void check_balance() {}

void Menu()
{
    cout << "Available Options" << endl;
    cout << "Create an Account: [1]" << endl;
    cout << "Check your Account Status: [2]" << endl;
    cout << "Check your Available Balance: [3]" << endl;
    cout << "Check your " << endl;
}

int main()
{
    Menu();
    int x;
    cin >> x;
    while (true)
    {
        switch (x)
        {
        case 1:
            // Acc x;
            create_acc();
        case 2:
            login();
        case 3:
            check_status();
        case 4:
            check_balance();
        case 5:
            cout << "EXIT!";
            break;
        }
    }

    return 0;
}