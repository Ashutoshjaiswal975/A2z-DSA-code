#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr  = next;
    }
    return prev;
}

void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* temp = new Node();

    temp->data = val;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail= temp;
    }
}

Node* add(Node* a, Node* b) {
    int carry = 0;
    Node* ansHead = nullptr;
    Node* ansTail = nullptr;

    while (a != nullptr || b != nullptr || carry != 0) {
        int sum = carry;
        if (a != nullptr) {
            sum += a->data;
            a = a->next;
        }
        if (b != nullptr) {
            sum += b->data;
            b = b->next;
        }
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    return ansHead;
}

Node* addTwoLists(Node* first, Node* second)
 {
    Node* a = reverse(first);
    Node* b = reverse(second);
    Node* ans = add(a, b);
    ans = reverse(ans);
    return ans;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data;
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create two linked lists representing numbers
    Node* num1 = new Node();
    num1->data = 7;
    num1->next = new Node();
    num1->next->data = 1;
    num1->next->next = new Node();
    num1->next->next->data = 6;

    Node* num2 = new Node();
    num2->data = 5;
    num2->next = new Node();
    num2->next->data = 9;
    num2->next->next = new Node();
    num2->next->next->data = 2;

    // Add the two numbers
    Node* result = addTwoLists(num1, num2);

    // Print the result
    printList(result);

    return 0;
}