#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to detect a loop using Floyd's Cycle-Finding Algorithm
Node* floydDetectLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast) {
            return slow; // There is a cycle
        }
    }

    return NULL; // No cycle found
}

// Function to find the starting node of the loop
Node* getStartingNode(Node* head) {
    if (head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);

    if (intersection == NULL)
        return NULL;

    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow; // Start of the loop
}

// Function to remove the loop
Node* removeLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);

    if (startOfLoop == NULL)
        return head; // No loop to remove

    Node* temp = startOfLoop;

    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL; // Remove the loop
    return head;
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

    // Creating a loop for testing
    head->next->next->next->next->next = head->next;

    // Detect loop
    if (floydDetectLoop(head) != NULL) {
        cout << "Loop detected." << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    // Remove the loop
    head = removeLoop(head);

    // Detect loop again
    if (floydDetectLoop(head) != NULL) {
        cout << "Loop detected." << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    // Print the list after removing the loop
    printList(head);

    return 0;
}
