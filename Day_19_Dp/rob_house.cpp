class Solution {
    // Helper function to solve the linear house robber problem
    int solveSpace(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];
        
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);
        
        for (int i = start + 2; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // No houses to rob
        if (n == 1) return nums[0];  // Only one house to rob
        
        // Rob from house 0 to house n-2 (ignore the last house)
        int option1 = solveSpace(nums, 0, n - 2);
        
        // Rob from house 1 to house n-1 (ignore the first house)
        int option2 = solveSpace(nums, 1, n - 1);
        
        // Return the maximum of the two options
        return max(option1, option2);
    }
};