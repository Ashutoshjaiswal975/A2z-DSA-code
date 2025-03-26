#include <iostream>
#define MOD 1000000007

// Function to add two numbers under modulo
int add(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

// Function to multiply two numbers under modulo
int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

// Recursive function to solve the problem
int solve(int n, int k) {
    // Base cases
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));

    // Recursive relation
    int ans = add(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1));
    return ans;
}

// Function to calculate the number of ways
int numberOfWays(int n, int k) {
    return solve(n, k);
}

/*
int solve(int n, int k, std::vector<int>& dp) {
    // Base cases
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));
    
    // Check if the result is already calculated
    if (dp[n] != -1)
        return dp[n];

    // Recursive relation with memoization
    dp[n] = add(mul(solve(n - 2, k, dp), k - 1), mul(solve(n - 1, k, dp), k - 1));
    return dp[n];
}

// Function to calculate the number of ways
int numberOfWays(int n, int k) {
    // Memoization array initialized to -1
    std::vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}
*/

int main() {
    int n, k;
    std::cout << "Enter n and k: ";
    std::cin >> n >> k;
    
    std::cout << "Number of ways: " << numberOfWays(n, k) << std::endl;
    return 0;
}

