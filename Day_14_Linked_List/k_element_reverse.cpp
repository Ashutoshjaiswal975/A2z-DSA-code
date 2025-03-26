#include <iostream>

// Definition for the Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse every k nodes of the linked list
Node* kReverse(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    // Count the nodes in the linked list
    int totalNodes = 0;
    Node* temp = head;
    while (temp != NULL) {
        totalNodes++;
        temp = temp->next;
    }

    // Reverse the first k nodes of the linked list if there are at least k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // If there are more nodes to process and the remaining nodes are at least k
    if (next != NULL && (totalNodes - count) >= k) {
        // Recur for the list starting from next and make the rest of the list as next of the first node
        head->next = kReverse(next, k);
    } else {
        // Attach the remaining part as it is
        head->next = next;
    }

    // prev is the new head of the reversed list
    return prev;
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
    // Creating a simple linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;

    std::cout << "Original list: ";
    printList(head);

    head = kReverse(head, k);

    std::cout << "Reversed list in groups of " << k << ": ";
    printList(head);

    // Clean up memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
