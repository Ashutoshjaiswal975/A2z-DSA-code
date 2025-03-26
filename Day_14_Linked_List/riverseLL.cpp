#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct LinkedListNode {
    int data;
    LinkedListNode* next;
    LinkedListNode(int x) : data(x), next(NULL) {}
};

// Function to reverse the linked list
LinkedListNode* reverseLinkedList(LinkedListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }

    LinkedListNode* prev = NULL;
    LinkedListNode* curr = head;
    LinkedListNode* forward = NULL;

    while (curr != NULL) 
    {
        forward = curr->next; // Save the next node
        curr->next = prev; // Reverse the current node's pointer
        prev = curr; // Move prev and curr one step forward
        curr = forward;
    }

    return prev; // prev will be the new head after the loop
}

// Function to print the linked list
void printLinkedList(LinkedListNode* head) {
    LinkedListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode* head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(3);
    head->next->next->next = new LinkedListNode(4);
    head->next->next->next->next = new LinkedListNode(5);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reversing the linked list
    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    // Clean up the memory
    while (head != NULL) {
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
