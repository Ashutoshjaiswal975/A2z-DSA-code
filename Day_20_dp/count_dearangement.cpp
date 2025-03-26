#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// Brute Force Recursive Method
long long int DerangementsBruteForce(int n) {
    if (n == 0) return 1;  // 1 way to derange 0 items
    if (n == 1) return 0;  // 0 ways to derange 1 item

    return (n - 1) * (DerangementsBruteForce(n - 1) + DerangementsBruteForce(n - 2));
}

// Top-Down Dynamic Programming (Memoization)
long long int DerangementsMemoization(int n, vector<long long>& dp) {
    if (n == 0) return 1;  // 1 way to derange 0 items
    if (n == 1) return 0;  // 0 ways to derange 1 item
    if (dp[n] != -1) return dp[n];

    dp[n] = ((n - 1) * (DerangementsMemoization(n - 1, dp) + DerangementsMemoization(n - 2, dp)) % MOD) % MOD;
    return dp[n];
}

// Bottom-Up Dynamic Programming (Tabulation)
long long int DerangementsTabulation(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 1;  // 1 way to derange 0 items
    dp[1] = 0;  // 0 ways to derange 1 item
    dp[2] = 1;  // 1 way to derange 2 items

    for (int i = 3; i <= n; i++) {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2]) % MOD) % MOD;
    }
    
    return dp[n];
}

// Space Optimized Approach (O(1) Space)
long long int DerangementsSpaceOptimized(int n) {
    if (n == 0) return 1;  // 1 way to derange 0 items
    if (n == 1) return 0;  // 0 ways to derange 1 item
    if (n == 2) return 1;  // 1 way to derange 2 items

    long long int prev2 = 1;  // D(0)
    long long int prev1 = 0;  // D(1)
    long long int curr = 0;

    for (int i = 2; i <= n; i++) {
        curr = ((i - 1) * (prev1 + prev2) % MOD) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return curr;
}

int main() {
    int n = 5;  // Example value
    cout << "Number of derangements (Brute Force) for " << n << ": " << DerangementsBruteForce(n) << endl;

    vector<long long> dp(n + 1, -1);
    cout << "Number of derangements (Memoization) for " << n << ": " << DerangementsMemoization(n, dp) << endl;

    cout << "Number of derangements (Tabulation) for " << n << ": " << DerangementsTabulation(n) << endl;

    cout << "Number of derangements (Space Optimized) for " << n << ": " << DerangementsSpaceOptimized(n) << endl;

    return 0;
}
