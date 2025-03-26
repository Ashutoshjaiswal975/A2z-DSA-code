#include <iostream>
#include <stack>
#include <string>

using namespace std;

int findMinimumCost(string str) {
    // Check if the length of the string is odd
    if (str.length() % 2 == 1) {
        return -1;
    }

    stack<char> s;

    // Traverse the string
    for (char ch : str) {
        if (ch == '{') {
            s.push(ch);
        } else {
            // ch is a closing brace '}'
            if (!s.empty() && s.top() == '{') {
                s.pop(); // Matched pair
            } else {
                s.push(ch); // Unmatched closing brace
            }
        }
    }

    // Stack contains unmatched braces
    int a = 0, b = 0;
    while (!s.empty()) {
        if (s.top() == '{') {
            b++; // Count unmatched opening braces
        } else {
            a++; // Count unmatched closing braces
        }
        s.pop();
    }

    // Calculate minimum cost
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main() {
    string str = "}}}}}}{{{{";
    cout << "Minimum cost to balance braces: " << findMinimumCost(str) << endl;
    return 0;
}
