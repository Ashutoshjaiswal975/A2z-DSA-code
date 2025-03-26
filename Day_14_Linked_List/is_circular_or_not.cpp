#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // There is a cycle
        }
    }

    return false; // No cycle found
}

// Function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a simple linked list for testing
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Test the list without a loop
    if (isCircular(head)) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is not circular." << endl;
    }

    // Creating a loop for testing
    head->next->next->next->next->next = head->next;

    // Test the list with a loop
    if (isCircular(head)) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is not circular." << endl;
    }

    return 0;
}
