#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int> &inputStack, int count, int size) {
    // Base case: When count is equal to the middle index
    if (count == size / 2) {
        inputStack.pop();  // Remove the middle element
        return;
    }

    int num = inputStack.top(); // Store the top element
    inputStack.pop(); // Remove the top element

    // Recursive call to reach the middle of the stack
    solve(inputStack, count + 1, size);

    // Push the stored element back onto the stack
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    int size = s.size();
    deleteMiddle(s, size);

    // Print stack contents after deletion
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
