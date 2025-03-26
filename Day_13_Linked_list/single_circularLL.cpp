#include <iostream>
using namespace std;

//--------------------------------------------------------------------
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // Memory free
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

//-------------------------------------------------------------------
void InsertNode(Node*& head, int element, int d) {
    // Empty list
    if (head == NULL) {
        Node* newNode = new Node(d);
        head = newNode;
        newNode->next = newNode;
    } else {
        // Non-empty list
        Node* curr = head;
        while (curr->data != element) {
            curr = curr->next;
            // If we looped back to the head, the element does not exist
            if (curr == head) {
                cout << "Element " << element << " not found in the list." << endl;
                return;
            }
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

//--------------------------------------------------------------------
void InsertAtTail(Node*& head, int d) {
    // Empty list
    if (head == NULL) {
        InsertNode(head, 0, d); // Inserting the first node in the list
    } else {
        // Non-empty list
        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        Node* temp = new Node(d);
        curr->next = temp;
        temp->next = head;
    }
}

//--------------------------------------------------------------------
void deleteNode(Node*& head, int position) {
    // Deleting the first node
    if (position == 1) {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* nodeToDelete = head;
        temp->next = head->next;
        head = head->next;
        nodeToDelete->next = NULL;
        delete nodeToDelete;
    } else {
        // Deleting any position or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//--------------------------------------------------------------------
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

//--------------------------------------------------
int main() {
    Node* head = NULL;

    InsertNode(head, 0, 10); // Inserting the first node in the list
    print(head);

    InsertAtTail(head, 20);
    print(head);

    InsertAtTail(head, 30);
    print(head);

    InsertNode(head, 20, 25); // Inserting 25 after 20
    print(head);

    deleteNode(head, 1); // Deleting the first node
    print(head);

    deleteNode(head, 3); // Deleting the third node
    print(head);

    return 0;
}
