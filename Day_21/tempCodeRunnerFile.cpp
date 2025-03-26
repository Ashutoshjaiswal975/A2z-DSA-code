int solve(vector<int> &num, int tar, vector<int> &dp) {
    // Base cases
    if (tar < 0)
        return 0;

    if (tar == 0)
        return 1;

    // Check if result is already memoized
    if (dp[tar] != -1)
        return dp[tar];

    int ans = 0;
    // Explore all possible numbers to subtract from the target
    for (int i = 0; i < num.size(); i++) {
        ans += solve(num, tar - num[i], dp);
    }

    // Memoize the result
    dp[tar] = ans;
    return dp[tar];
}