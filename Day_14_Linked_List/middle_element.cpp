#include <iostream>

// Definition for the Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to get the length of the linked list
int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find the middle node of the linked list
Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL; // Handle the case when the list is empty
    }

    int length = getLength(head);
    int mid = length / 2;

    Node* temp = head;
    int cnt = 0;
    while (cnt < mid) {
        temp = temp->next;
        cnt++;
    }

    return temp;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Main function to test the code
int main() {
    // Creating a simple linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original list: ";
    printList(head);

    Node* middle = findMiddle(head);
    if (middle != NULL) {
        std::cout << "Middle node value: " << middle->data << std::endl;
    } else {
        std::cout << "The list is empty." << std::endl;
    }

    // Clean up memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
