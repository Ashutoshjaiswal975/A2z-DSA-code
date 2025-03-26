#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct LinkedListNode {
    int data;
    LinkedListNode* next;
    LinkedListNode(int x) : data(x), next(NULL) {}
};


void reverse(LinkedListNode* &head, LinkedListNode* curr, LinkedListNode* prev){
if(curr==NULL )
{
    head= prev;
    return;
}
LinkedListNode* forward= curr-> next;
reverse(head, forward,curr);
curr->next=prev;

}

// Function to reverse the linked list
LinkedListNode* reverseLinkedList(LinkedListNode* head) 
{
    LinkedListNode* curr= head;
    LinkedListNode* prev= NULL;
    reverse(head, curr, prev);

    return head; 
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