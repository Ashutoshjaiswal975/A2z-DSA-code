#include <bits/stdc++.h>
using namespace std;

// Brute force recursive solution (Exponential Time Complexity)
int solveBruteForce(int n, int x, int y, int z) {
    if (n == 0) return 0;      // If the length is 0, no cuts are needed
    if (n < 0) return INT_MIN; // If the length becomes negative, it's not a valid solution

    int a = solveBruteForce(n - x, x, y, z) + 1;
    int b = solveBruteForce(n - y, x, y, z) + 1;
    int c = solveBruteForce(n - z, x, y, z) + 1;

    return max(a, max(b, c));
}

// Memoization (Top-down DP with O(n) space)
int solveMemoization(int n, int x, int y, int z, vector<int> &dp) {
    if (n == 0) return 0;       // No cuts are needed if the length is zero
    if (n < 0) return INT_MIN;  // Invalid length, so return negative infinity

    if (dp[n] != -1) return dp[n]; // Return the cached result

    // Calculate the number of segments for each possible cut
    int a = solveMemoization(n - x, x, y, z, dp) + 1;
    int b = solveMemoization(n - y, x, y, z, dp) + 1;
    int c = solveMemoization(n - z, x, y, z, dp) + 1;

    // Store the maximum number of cuts in dp array
    dp[n] = max(a, max(b, c));
    return dp[n];
}

// Tabulation (Bottom-up DP with O(n) space)
int solveTabulation(int n, int x, int y, int z) {
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0; // Base case: no cuts needed for length 0

    for (int i = 1; i <= n; i++) {
        if (i - x >= 0) dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0) dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0) dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return (dp[n] < 0) ? 0 : dp[n];
}

// Space Optimization (O(1) extra space by using iterative approach)
int solveSpaceOptimized(int n, int x, int y, int z) {
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0; // Base case: no cuts needed for length 0

    // We only need the dp array to calculate the result, but no further optimizations
    for (int i = 1; i <= n; i++) {
        if (i - x >= 0) dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0) dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0) dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return (dp[n] < 0) ? 0 : dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    // Brute force approach
    // int ans = solveBruteForce(n, x, y, z);
    
    // Memoization approach
    // vector<int> dp(n + 1, -1);
    // int ans = solveMemoization(n, x, y, z, dp);

    // Tabulation approach
    // int ans = solveTabulation(n, x, y, z);

    // Space Optimized approach
    int ans = solveSpaceOptimized(n, x, y, z);

    return (ans <= 0) ? 0 : ans;
}

int main() {
    int n = 7; // Length of the rope
    int x = 2, y = 1, z = 3; // Segment lengths

    // Output the maximum number of segments the rope can be cut into
    cout << "Maximum number of segments: " << cutSegments(n, x, y, z) << endl;

    return 0;
}
