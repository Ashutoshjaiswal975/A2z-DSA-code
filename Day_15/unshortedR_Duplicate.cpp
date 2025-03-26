#include <iostream>
#include <unordered_set>
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

    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (seen.find(curr->data) != seen.end()) {
            // Duplicate found, remove it
            prev->next = curr->next;
            delete curr;
        } else {
            // Not a duplicate, add to seen set
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
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
    int arr[] = {3, 5, 8, 5, 10, 2, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, size);
    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
