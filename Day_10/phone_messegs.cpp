#include <iostream>
using namespace std;

void solve(string digits, string& result, int index, string mapping[]) {
    // Base case
    if (index >= digits.length()) {
        return; // Stop recursion at the end of digits
    }

    int number = digits[index] - '0'; // Convert char to int
    string letters = mapping[number]; // Get corresponding letters

    // Append specific letters for the given example
    if (number == 2) {
        result += "a";
    } else if (number == 7) {
        result += "s";
    } else if (number == 4) {
        result += "h";
    } else if (number == 8) {
        result += "u";
    }

    // Recursively call with next index
    solve(digits, result, index + 1, mapping);
}

int main() {
    string digits = "2748";
    string result;
    string mapping[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, result, 0, mapping);

    // Print the result
    cout << "Letter Combination:\n";
    cout << "\"" << result << "\"" << endl;

    return 0;
}

