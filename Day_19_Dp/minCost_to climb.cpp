#include <iostream>
#include <vector>
using namespace std;



 // int solve(vector<int> & cost, int n){
    //     if(n==0){
    //         return cost[0];
    //     }
    //     if(n==1){
    //         return cost[1];
    //     }
    //     int ans= cost[n]+ min(solve(cost, n-1), solve(cost, n-2));
    //     return ans;
    // }

/*
     int solve3(vector<int>& cost, int n) {
        // Step 1: Create a dp array
        vector<int> dp(n + 1);

        // Step 2: Base case analysis
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Step 3: Fill the dp array from index 2 to n-1
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // Return the minimum cost to reach either the last step or second last step
        return min(dp[n - 1], dp[n - 2]);
    }

    // Main function to calculate the minimum cost to climb the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve3(cost, n);
    }
    */

class Solution {
public:
    // Helper function to solve the problem recursively with memoization
    int solve2(vector<int>& cost, int n, vector<int>& dp) {
        // Base cases
        if (n == 0) {
            return cost[0];
        }
        if (n == 1) {
            return cost[1];
        }

        // If already calculated, return the stored result
        if (dp[n] != -1) {
            return dp[n];
        }

        // Calculate the minimum cost to reach step 'n'
        dp[n] = cost[n] + min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));

        return dp[n];
    }

    // Main function to calculate the minimum cost to reach the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // Create a dp array initialized with -1 for memoization
        vector<int> dp(n + 1, -1);

        // The answer will be the minimum cost to start at either the last or second-last step
        int ans = min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> cost;

    // Input the cost array
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;

    cout << "Enter the cost for each step: ";
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cost.push_back(c);
    }

    // Output the minimum cost to climb the stairs
    cout << "Minimum cost to climb the stairs: " << sol.minCostClimbingStairs(cost) << endl;

    return 0;
}
