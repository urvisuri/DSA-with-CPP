#include<iostream>
using namespace std;

struct node {
    int info;
    struct node *next;
};

class list {
public:
    node *start;
    list() {
        start = NULL;
    }
    node *createnode(int value);
    void insertpos();
    void display();
};

// Function to create a new node
node *list::createnode(int value) {
    node *temp = new node;
    temp->info = value;
    temp->next = NULL;
    return temp;
}

// Function to insert at a specific position in the list
void list::insertpos() {
    int value, pos;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter position to insert the value: ";
    cin >> pos;
    
    node *temp = createnode(value);
    if (pos == 1) {  // Inserting at the beginning
        temp->next = start;
        start = temp;
    } else {
        node *s = start;
        for (int i = 1; i < pos - 1; i++) {
            if (s == NULL) {
                cout << "Position out of range" << endl;
                return;
            }
            s = s->next;
        }
        temp->next = s->next;  // Link new node to the next node
        s->next = temp;        // Link previous node to the new node
    }
    cout << "Element inserted at position " << pos << endl;
}

// Function to display the linked list
void list::display() {
    node *s = start;
    if (s == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "Linked list: ";
    while (s != NULL) {
        cout << s->info << " -> ";
        s = s->next;
    }
    cout << "NULL" << endl;
}

int main() {
    list l;
    l.insertpos();
    l.insertpos();
    l.display();
    return 0;
}