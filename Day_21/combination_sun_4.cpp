#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find the number of ways with memoization
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

int findWays(vector<int> &num, int tar) {
    // Create a memoization table initialized with -1
    vector<int> dp(tar + 1, -1);
    return solve(num, tar, dp);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    cout << "Number of ways to get the target: " << findWays(num, target) << endl;

    return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find the number of ways to reach the target
int solve(const vector<int> &num, int tar) {
    // Base cases
    if (tar < 0)
        return 0; // No valid solution for negative target

    if (tar == 0)
        return 1; // One valid way to achieve target 0 (by selecting no numbers)

    int ans = 0;
    // Explore all possibilities by trying each number in the array
    for (int i = 0; i < num.size(); i++) {
        ans += solve(num, tar - num[i]);
    }

    return ans;
}

int findWays(vector<int> &num, int tar) {
    return solve(num, tar);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i
*/

/* 
#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of ways to reach the target using bottom-up DP
int findWays(vector<int> &num, int tar) {
    // Create a dp array to store the number of ways to achieve each target from 0 to tar
    vector<int> dp(tar + 1, 0);

    // Base case: there's exactly 1 way to achieve target 0 (by selecting no numbers)
    dp[0] = 1;

    // Iterate over all possible targets from 1 to tar
    for (int t = 1; t <= tar; t++) {
        // For each target, explore all numbers in the array
        for (int i = 0; i < num.size(); i++) {
            if (t >= num[i]) { // Only proceed if the number can contribute to the current target
                dp[t] += dp[t - num[i]]; // Add the number of ways to achieve the reduced target
            }
        }
    }

    // The final answer will be in dp[tar], which contains the number of ways to achieve target `tar`
    return dp[tar];
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    cout << "Number of ways to get the target: " << findWays(num, target) << endl;

    return 0;
}

*/
