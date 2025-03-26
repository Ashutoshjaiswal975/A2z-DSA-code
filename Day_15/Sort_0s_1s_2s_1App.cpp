#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to sort the linked list of 0s, 1s, and 2s
Node* sortList(Node* head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) {
            zeroCount++;
        } else if (temp->data == 1) {
            oneCount++;
        } else if (temp->data == 2) {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (zeroCount != 0) {
            temp->data = 0;
            zeroCount--;
        } else if (oneCount != 0) {
            temp->data = 1;
            oneCount--;
        } else if (twoCount != 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

// Helper function to create a linked list from an array
Node* createLinkedList(int arr[], int size) {
    if (size == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 1, 0, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* head = createLinkedList(arr, size);

    cout << "Original list: ";
    printLinkedList(head);

    head = sortList(head);

    cout << "Sorted list: ";
    printLinkedList(head);

    return 0;
}
