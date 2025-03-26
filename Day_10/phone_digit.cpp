#include <iostream>
using namespace std;

class Solution {
private:
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

public:
    string* letterCombinations(string digits, int& resultSize) {
        static string ans[1000]; // Static array to store the results
        if (digits.empty()) {
            resultSize = 0;
            return ans; // Return empty result if digits is empty
        }

        string output;
        int index = 0;
        int ansIndex = 0; // Index to track the number of results stored
        string mapping[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, ansIndex, output, index, mapping);
        resultSize = ansIndex; // Set the size of the result array
        return ans;
    }
};

int main() {
    string digits;
    cout << "Please enter the numbers: ";
    cin >> digits;

    Solution sol;
    int resultSize = 0;

    // Get the letter combinations
    string* result = sol.letterCombinations(digits, resultSize);

    // Print the results
    cout << "Letter Combinations:\n";
    for (int i = 0; i < resultSize; ++i) {
        cout << "\"" << result[i] << "\"" << endl;
    }

    return 0;
}
