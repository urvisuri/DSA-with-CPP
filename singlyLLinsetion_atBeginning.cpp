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
    void insertbeg();
    void display();
};

// Function to create a new node
node *list::createnode(int value) {
    node *temp = new node;
    temp->info = value;
    temp->next = NULL;
    return temp;
}

// Function to insert at the beginning of the list
void list::insertbeg() {
    int value;
    cout << "Enter value to insert at the beginning: ";
    cin >> value;
    node *temp = createnode(value);
    
    temp->next = start;  // Point new node to current start
    start = temp;        // Update start to the new node
    
    cout << "Element inserted at the beginning." << endl;
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
    l.insertbeg();
    l.insertbeg();
    l.display();
    return 0;
}