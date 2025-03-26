#include <iostream>
#include <exception>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Class to represent two stacks using a single linked list
class TwoStack {
private:
    Node* top1;       // Pointer to the top of stack1
    Node* top2;       // Pointer to the top of stack2
    int size1;        // Size of stack1
    int size2;        // Size of stack2

public:
    // Constructor to initialize stacks
    TwoStack() : top1(nullptr), top2(nullptr), size1(0), size2(0) {}

    // Push an element into stack1
    void push1(int value) {
        Node* newNode = new Node(value);
        if (top1 == nullptr) {
            top1 = newNode;
        } else {
            newNode->next = top1;
            top1 = newNode;
        }
        size1++;
    }

    // Push an element into stack2
    void push2(int value) {
        Node* newNode = new Node(value);
        if (top2 == nullptr) {
            top2 = newNode;
        } else {
            newNode->next = top2;
            top2 = newNode;
        }
        size2++;
    }

    // Pop an element from stack1
    int pop1() {
        if (top1 == nullptr) {
            throw underflow_error("Stack 1 Underflow");
        }
        Node* temp = top1;
        int value = top1->data;
        top1 = top1->next;
        delete temp;
        size1--;
        return value;
    }

    // Pop an element from stack2
    int pop2() {
        if (top2 == nullptr) {
            throw underflow_error("Stack 2 Underflow");
        }
        Node* temp = top2;
        int value = top2->data;
        top2 = top2->next;
        delete temp;
        size2--;
        return value;
    }

    // Merge the two stacks into a single linked list
    Node* mergeStacks() {
        Node* mergedHead = nullptr;
        Node* mergedTail = nullptr;

        // Merge stack1
        Node* current = top1;
        while (current != nullptr) {
            Node* newNode = new Node(current->data);
            if (mergedHead == nullptr) {
                mergedHead = newNode;
                mergedTail = newNode;
            } else {
                mergedTail->next = newNode;
                mergedTail = newNode;
            }
            current = current->next;
        }

        // Merge stack2
        current = top2;
        while (current != nullptr) {
            Node* newNode = new Node(current->data);
            if (mergedHead == nullptr) {
                mergedHead = newNode;
                mergedTail = newNode;
            } else {
                mergedTail->next = newNode;
                mergedTail = newNode;
            }
            current = current->next;
        }

        return mergedHead;
    }

    // Destructor to clean up allocated nodes
    ~TwoStack() {
        while (top1 != nullptr) {
            Node* temp = top1;
            top1 = top1->next;
            delete temp;
        }
        while (top2 != nullptr) {
            Node* temp = top2;
            top2 = top2->next;
            delete temp;
        }
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    try {
        TwoStack ts; // Create a TwoStack instance

        // Push elements to stack1
        ts.push1(5);
        ts.push1(10);
        ts.push1(15);

        // Push elements to stack2
        ts.push2(20);
        ts.push2(25);
        ts.push2(30);

        // Merge stacks into a single linked list
        Node* mergedList = ts.mergeStacks();

        // Print the merged list
        cout << "Merged linked list: ";
        printList(mergedList);

        // Clean up the merged list
        while (mergedList != nullptr) {
            Node* temp = mergedList;
            mergedList = mergedList->next;
            delete temp;
        }

    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}
