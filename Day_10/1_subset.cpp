#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(nums, output, index + 1, ans);

        // include
        output.push_back(nums[index]);
        solve(nums, output, index + 1, ans);
        output.pop_back(); // backtrack to remove the last included element
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
