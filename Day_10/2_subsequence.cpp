#include <iostream>
#include <vector>
#include <string>



using namespace std;

class Solution {
private:
    void solve(string& str, string output, int index, vector<string>& ans) {
        if (index >= str.size()) {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(str, output, index + 1, ans);

        // include
        output.push_back(str[index]);
        solve(str, output, index + 1, ans);
        output.pop_back(); // backtrack to remove the last included character
    }
public:
    vector<string> subsequences(string& str) {
        vector<string> ans;
        string output;
        int index = 0;
        solve(str, output, index, ans);
        return ans;
    }
};

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    Solution sol;
    vector<string> result = sol.subsequences(input);

    cout << "Subsequences:\n";
    for (const auto& subseq : result) {
        if (subseq.empty()) {
            cout << "{ }\n";
        } else {
            cout << "{ " << subseq << " }\n";
        }
    }

    return 0;
}



