#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(num);
}

void reverseStack(std::stack<int>& stack) {
    if (stack.empty()) {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    std::cout << "Original stack: ";
    std::stack<int> temp = s;  // Create a temporary stack to display the elements
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
    
    reverseStack(s);
    
    std::cout << "Reversed stack: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    
    return 0;
}
