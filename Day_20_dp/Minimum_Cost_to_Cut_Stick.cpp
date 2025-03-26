#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int j, vector<int>& cuts) {
        // Base case: if the segment is invalid (no cuts in this range)
        if (i > j) return 0;

        int mini = INT_MAX;

        // Try to cut at each possible position
        for (int ind = i; ind <= j; ind++) {
            // Calculate the cost of the current cut
            int cost = cuts[j + 1] - cuts[i - 1] + f(i, ind - 1, cuts) + f(ind + 1, j, cuts);
            // Update the minimum cost
            mini = min(mini, cost);
        }

        return mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        // Insert the ends of the stick into the cuts array
        cuts.push_back(n);  // Adding the end of the stick
        cuts.insert(cuts.begin(), 0);  // Adding the start of the stick
        
        // Sort the cuts to ensure we are cutting in the correct order
        sort(cuts.begin(), cuts.end());

        // Call the recursive function starting from 1 to c (since 0 and n are boundaries)
        return f(1, c, cuts);
    }
};

int main() {
    Solution sol;
    
    int n = 9;  // Length of the stick
    vector<int> cuts = {5, 6, 1, 4, 2};  // Positions of the cuts

    // Output the minimum cost to cut the stick
    cout << "Minimum cost to cut the stick: " << sol.minCost(n, cuts) << endl;

    return 0;
}

/*.... optimal solution.....
class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        // Base case: if the segment is invalid
        if (i > j) return 0;

        // If the result is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        // Try to cut at each possible position
        for (int ind = i; ind <= j; ind++) {
            // Calculate the cost of the current cut
            int cost = cuts[j + 1] - cuts[i - 1] + f(i, ind - 1, cuts, dp) + f(ind + 1, j, cuts, dp);
            // Update the minimum cost
            mini = min(mini, cost);
        }

        // Store the result in dp table
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        // Insert the ends of the stick into the cuts array
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        // Sort the cuts to ensure we are cutting in the right order
        sort(cuts.begin(), cuts.end());

        // Create a dp table to memoize results and avoid redundant calculations
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

        // Call the recursive function starting from 1 to c (since 0 and n are boundaries)
        return f(1, c, cuts, dp);
    }
};
*/
/*
......................more optimal

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        // Insert the ends of the stick into the cuts array
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        // Sort the cuts to ensure we are cutting in the right order
        sort(cuts.begin(), cuts.end());

        // Create a dp table to memoize results and avoid redundant calculations
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        for(int i=c; i>=1 ; i--){
            for(int j= 1; j<=c;j++){
                if(i>j) continue;
                int mini = INT_MAX;

        // Try to cut at each possible position
        for (int ind = i; ind <= j; ind++) {
            // Calculate the cost of the current cut
            int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
            // Update the minimum cost
            mini = min(mini, cost);
        }

        // Store the result in dp table
        dp[i][j] = mini;
            }
        }

        // Call the recursive function starting from 1 to c (since 0 and n are boundaries)
        return dp[1][c];
    }
};
*/
