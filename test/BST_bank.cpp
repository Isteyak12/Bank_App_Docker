#include <iostream>
#include <string>
using namespace std;

struct Acc {
    string username = "";
    int password = 0;
    double balance = 0;
    Acc* left = nullptr;
    Acc* right = nullptr;

    Acc(string name, int pass) {
        username = name;
        password = pass;
    }
};

class BST {
private:
    Acc* root = nullptr;

    Acc* insertRec(Acc* node, string username, int password) {
        if (node == nullptr) {
            return new Acc(username, password);
        }

        if (username < node->username) {
            node->left = insertRec(node->left, username, password);
        } else if (username > node->username) {
            node->right = insertRec(node->right, username, password);
        }

        return node;
    }

    Acc* searchRec(Acc* node, string username) {
        if (node == nullptr || node->username == username) {
            return node;
        }

        if (username < node->username) {
            return searchRec(node->left, username);
        } else {
            return searchRec(node->right, username);
        }
    }

public:
    void insert(string username, int password) {
        root = insertRec(root, username, password);
    }

    Acc* search(string username) {
        return searchRec(root, username);
    }
};

BST accounts;

void createAcc() {
    string username;
    int password;
    double initialBalance;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    accounts.insert(username, password);
    cout << "Account created successfully!" << endl;
}

Acc* login() {
    string username;
    int password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    Acc* user = accounts.search(username);
    if (user != nullptr && user->password == password) {
        return user;
    }
    return nullptr;
}

void checkBalance(Acc* user) {
    if (user != nullptr) {
        cout << "Current balance for " << user->username << ": $" << user->balance << endl;
    } else {
        cout << "Invalid credentials. Please log in." << endl;
    }
}

int main() {
    int choice;
    Acc* currentUser = nullptr;

    do {
        cout << "\nBanking Menu\n";
        cout << "1. Create an account\n";
        cout << "2. Login\n";
        cout << "3. Check balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAcc();
                break;
            case 2:
                currentUser = login();
                if (currentUser != nullptr) {
                    cout << "Login successful! Welcome, " << currentUser->username << "!" << endl;
                } else {
                    cout << "Login failed. Invalid credentials." << endl;
                }
                break;
            case 3:
                checkBalance(currentUser);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
