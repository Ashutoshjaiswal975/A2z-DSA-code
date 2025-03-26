#include <iostream>
using namespace std;
//--------------------------------------------------------------------
class Node
{

public:
    int data;
    Node *next;
    // construkter
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free  for node with data" << value << endl;
    }
};

//-------------------------------------------------------------------

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
//--------------------------------------------------------------------
void InsertAtTail(Node *&tail, int f)
{
    Node *temp = new Node(f);
    tail->next = temp;
    tail = temp;
}
//--------------------------------------------------------------------
void InsertAtPosition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        InsertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

     // creating node for data
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    // inserting at last posion
    if (temp->next == NULL)
    {
        InsertAtTail(head, data);
        return;
    }
}
//---------------------------------------------------------------------

void deleteNode(int position, Node *&head)
{
    // deleting 1st node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
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
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
//-------------------------------------------------
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//--------------------------------------------------
int main()
{

    // create a new node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout<<node1-> next<<endl;
    // head pointed  to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);

    InsertAtHead(head, 12);
    print(head);
    InsertAtTail(tail, 15);
    print(head);

    InsertAtPosition(tail, head, 4, 2);
    print(head);

    deleteNode(4, head);
    print(head);

    return 0;
}
