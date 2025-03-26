#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value=this-> data;
        if (next!=NULL)
        {
            delete next;
            next= NULL;
        }
        cout<<"memory free from node with data:"<<value<<endl;
    }
};
//......................................................................
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//......................................................................
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}
//......................................................................
void InsertAtHead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
//.....................................................................
void InsertAtTail(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
//.....................................................................
void InsertAtPosition(Node*& head, Node*& tail, int position, int d) {
    // Insert at start
    if (position == 1) {
        InsertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the position
    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Inserting at last position
    if (temp->next == NULL) {
        InsertAtTail(head, tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
//...................................................................
void deleteNode(int position, Node *&head)
{
    // deleting 1st node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any posion or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
//....................................................................
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout << "Length: " << getLength(head) << endl;

    InsertAtHead(head, tail, 5);
    print(head);
    cout << "Length: " << getLength(head) << endl;

    InsertAtTail(head, tail, 15);
    print(head);
    cout << "Length: " << getLength(head) << endl;

    InsertAtPosition(head, tail, 2, 25);
    print(head);
    cout << "Length: " << getLength(head) << endl;
    InsertAtPosition(head, tail, 4, 25);
    print(head);
    deleteNode(4, head);
    print(head);

    return 0;
}
