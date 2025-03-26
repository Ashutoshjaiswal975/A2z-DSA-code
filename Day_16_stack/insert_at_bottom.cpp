#include <iostream>
#include <stack>

using namespace std;

// Recursive function to insert an element at the bottom of the stack
void solve(stack<int>& s, int x) {
    // Base case: if stack is empty, push the element
    if (s.empty()) {
        s.push(x);
        return;
    }

    // Pop the top element
    int num = s.top();
    s.pop();

    // Recursive call to solve with the remaining stack
    solve(s, x);

    // Push the popped element back onto the stack
    s.push(num);
}

// Function to insert an element at the bottom of the stack
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
}

// Function to print the elements of the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    // Create a stack and push some elements onto it
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Original stack: ";
    printStack(myStack);

    // Insert 4 at the bottom of the stack
    int x = 4;
    myStack = pushAtBottom(myStack, x);

    cout << "Stack after pushing " << x << " at the bottom: ";
    printStack(myStack);

    return 0;
}
