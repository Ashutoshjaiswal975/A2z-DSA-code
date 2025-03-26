#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* createList(int arr[], int size) {
    if (size == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, size);
    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
