#include <iostream>
#include <vector>
using namespace std;
/*
int climb(int n, vector<int> &memo){
    if(n<=1){
        return 1;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    memo[n]=climb(n-1, memo)+climb(n-2, memo);
    return memo[n];
}
*/


class Solution {
public:
    int climbStairs(int n) {



         /*
       if(n==0|| n==1){
        return 1;
       } 
   
       return  climbStairs(n-1)+climbStairs(n-2);
       */
    /*
       vector<int> memo(n+1, -1);
       return climb(n, memo);
     */
        // Base case: if there are 0 or 1 steps, there is only one way to climb
        if (n <= 1) {
            return 1;
        }

        // Create a dp array to store the number of ways to reach each step
        vector<int> dp(n + 1);

        // Initialize the base cases
        dp[0] = 1; // 1 way to stay at the ground (0th step)
        dp[1] = 1; // 1 way to reach the 1st step

        // Fill the dp array for all steps from 2 to n
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2]; // sum of ways from (i-1) and (i-2)
        }

        // The result is the number of ways to reach the nth step
        return dp[n];
    }
};

int main() {
    Solution sol;
    int n;

    // Input the number of steps
    cout << "Enter the number of steps: ";
    cin >> n;

    // Output the number of ways to climb the stairs
    cout << "Ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;

    return 0;
}
