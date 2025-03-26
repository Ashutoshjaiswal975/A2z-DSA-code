#include <iostream>
using namespace std;

void solve(string digits, string* ans, int& ansIndex, string output, int index, string mapping[]) {
    // Base case
    if (index >= digits.length()) {
        ans[ansIndex++] = output;
        return;
    }

    int number = digits[index] - '0'; // Convert char to int
    string letters = mapping[number]; // Get corresponding letters

    for (int i = 0; i < letters.length(); i++) {
        output.push_back(letters[i]);
        solve(digits, ans, ansIndex, output, index + 1, mapping); // Recursive call with next index
        output.pop_back();
    }
}

int main() {
    string digits;
    cout << "Please enter the numbers: ";
    cin >> digits;

    static string ans[1000]; // Static array to store the results
    int resultSize = 0;

    if (digits.empty()) {
        cout << "Letter Combinations:\n";
        return 0;
    }

    string output;
    int index = 0;
    int ansIndex = 0; // Index to track the number of results stored
    string mapping[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, ans, ansIndex, output, index, mapping);

    // Print the results
    cout << "Letter Combinations:\n";
    for (int i = 0; i < ansIndex; ++i) {
        cout << "\"" << ans[i] << "\"" << endl;
    }

    return 0;
}
