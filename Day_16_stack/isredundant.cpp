#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else if (ch == ')') {
            bool isRedundant = true;
            
            // Process the stack until we find the corresponding '('
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
            }
            
            // Pop the '('
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            
            // If no operator was found within the parentheses, it's redundant
            if (isRedundant) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s = "((a+b))";
    if (findRedundantBrackets(s)) {
        cout << "Redundant brackets found\n";
    } else {
        cout << "No redundant brackets\n";
    }
    return 0;
}
