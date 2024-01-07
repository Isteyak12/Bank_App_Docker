#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string name;
    int rate;
    double salary;
    Node *next;
    Node()
    {
        // default constructor
        this->name = "";
        this->rate = 0;
        this->salary = 0.0;
        next = nullptr;
    }
    Node(string name, int rate, double salary)
    {
        this->name = name;
        this->rate = rate;
        this->salary = salary;
        next = nullptr;
    }
};

void insert_back(Node *&h) {
    string name;
    int rate;
    double salary;

    cout << "ENTER THE NAME: " << endl;
    cin >> name;

    cout << "ENTER THE RATE: " << endl;
    cin >> rate;

    cout << "ENTER THE SALARY: " << endl;
    cin >> salary;

    Node *new_node = new Node(name, rate, salary);

    if (h == nullptr) {
        h = new_node;
    } else {
        Node *curr = h;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}


void print_all_rates(Node *&head)
{
    int count = 0;
    Node *curr = head;

    while (curr != nullptr)
    {
        cout << "Name: " << curr->name << " | Rate: " << curr->rate << endl;
        curr = curr->next;
        count++;
    }
    cout << "Number of data blocks: " << count << endl;
}

int main()
{
    cout << "Link List Bank App" << endl;

    int choice;
    cout << "Make a wise choice!";
    cin >> choice;
    // case-sensitive has to be initializedd with null
    Node *head=nullptr;
    do{
        switch (choice)
        {
        case 1:
            cout << "Enter a block data; " << endl;
            insert_back(head);
            break;
        case 2:
            //sort 
            break;
        case 3:
            // remove_back();
            break;
        case 4:
            print_all_rates(head);
            break;
        case 5:
            cout << "EXIT" << endl;
            break;
        }
        cin >> choice;
    } while (choice != 5);

    return 0;
}
