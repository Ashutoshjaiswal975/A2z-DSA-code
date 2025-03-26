#include <iostream>
#include <stack>

void shortedinsert(std::stack<int>& stack, int num) {
    // Base case: if stack is empty or top element is less than num, push num
    if (stack.empty() || stack.top() < num) {
        stack.push(num);
        return;
    }

    // Recursive case: pop the top element
    int n = stack.top();
    stack.pop();

    // Recursively call shortedinsert to find the correct position for num
    shortedinsert(stack, num);

    // Push the previously popped element back onto the stack
    stack.push(n);
}

void sortStack(std::stack<int>& stack) {
    // Base case: if stack is empty, return
    if (stack.empty()) {
        return;
    }

    // Pop the top element
    int num = stack.top();
    stack.pop();

    // Recursively sort the remaining stack
    sortStack(stack);

    // Insert the popped element into the sorted stack
    shortedinsert(stack, num);
}

int main() {
    std::stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    std::cout << "Original stack: ";
    std::stack<int> temp = s;  // Create a temporary stack to display the elements
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    sortStack(s);

    std::cout << "Sorted stack: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}
