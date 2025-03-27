#include <iostream>
#include <vector>
using namespace std;

// Iterative Approach
void reverseString(vector<char>& s) {
    int start = 0;
    int end = s.size() - 1; // Use .size() instead of .length()

    while (start < end) {  // Loop until start crosses end
        swap(s[start], s[end]); // Swap characters
        start++;
        end--;
    }
}

// Recursive Approach
void reverseStringRecursive(vector<char>& s, int start, int end) {
    if (start >= end) return; // Base case

    swap(s[start], s[end]); // Swap characters
    reverseStringRecursive(s, start + 1, end - 1); // Recursive call
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    // Using Iterative Approach
    reverseString(s);
    cout << "Reversed (Iterative): ";
    for (char c : s) cout << c;
    cout << endl;

    // Reset vector to original order
    s = {'h', 'e', 'l', 'l', 'o'};

    // Using Recursive Approach
    reverseStringRecursive(s, 0, s.size() - 1);
    cout << "Reversed (Recursive): ";
    for (char c : s) cout << c;
    cout << endl;

    return 0;
}
