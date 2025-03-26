#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, vector<bool>& visited) {
        // Base case: if the current permutation is complete
        if (output.size() == nums.size()) {
            ans.push_back(output);
            return;
        }

        // Try each number in nums that hasn't been used yet
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                // Choose the number nums[i]
                visited[i] = true;
                output.push_back(nums[i]);

                // Recurse with the chosen number
                solve(nums, ans, output, visited);

                // Backtrack by unchoosing the number nums[i]
                visited[i] = false;
                output.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<bool> visited(nums.size(), false);  // To keep track of visited elements
        solve(nums, ans, output, visited);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    // Print the results
    cout << "Permutations:\n";
    for (const auto& permutation : result) {
        cout << "{ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
