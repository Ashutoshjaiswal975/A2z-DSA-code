#include<iostream>
#include <stack>
#include <string>
using namespace std;

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isValidParenthesis(const std::string &s) {
    std::stack<char> ch;

    for (int i = 0; i < s.length(); ++i) { // Full for-loop condition
        char c = s[i];

        // If opening bracket, push to stack
        if (c == '(' || c == '{' || c == '[') {
            ch.push(c);
        } else {
            // For closing bracket, stack must not be empty and should match the top of the stack
            if (ch.empty() || !matches(ch.top(), c)) {
                return false;
            } else {
                ch.pop();
            }
        }
    }

    // Stack should be empty if all brackets are valid and matched
    return ch.empty();
}

int main() {
    // Test cases
    std::string test1 = "()";
    std::string test2 = "()[]{}";
    std::string test3 = "(]";
    std::string test4 = "([)]";
    std::string test5 = "{[]}";

    // Running tests
    std::cout << "Test 1: " << isValidParenthesis(test1) << std::endl; // Expected: 1 (true)
    std::cout << "Test 2: " << isValidParenthesis(test2) << std::endl; // Expected: 1 (true)
    std::cout << "Test 3: " << isValidParenthesis(test3) << std::endl; // Expected: 0 (false)
    std::cout << "Test 4: " << isValidParenthesis(test4) << std::endl; // Expected: 0 (false)
    std::cout << "Test 5: " << isValidParenthesis(test5) << std::endl; // Expected: 1 (true)

    return 0;
}
