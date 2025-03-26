#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head) {
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // Create separate lists for 0s, 1s, and 2s
    while (curr != nullptr) {
        int value = curr->data;
        if (value == 0) {
            insertAtTail(zeroTail, curr);
        } else if (value == 1) {
            insertAtTail(oneTail, curr);
        } else if (value == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // Merge the three sublists
    if (oneHead->next != nullptr) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

    // Setup the new head
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// Helper function to create a new node
Node* createNode(int data) {
    return new Node(data);
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list: 2 -> 1 -> 0 -> 2 -> 1 -> 0
    Node* head = createNode(2);
    head->next = createNode(1);
    head->next->next = createNode(0);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);
    head->next->next->next->next->next = createNode(0);

    std::cout << "Original list: ";
    printList(head);

    head = sortList(head);

    std::cout << "Sorted list: ";
    printList(head);

    return 0;
}
