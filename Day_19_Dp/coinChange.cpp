#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    // Recursive helper function
    int solveRec(vector<int>& coins, int amount) {
        // Base case 1: If amount becomes 0, no coins are needed
        if (amount == 0) {
            return 0;
        }
        
        // Base case 2: If amount becomes negative, it's an invalid case
        if (amount < 0) {
            return INT_MAX;
        }
        
        // Initialize the minimum number of coins to a large value (INT_MAX)
        int minimum = INT_MAX;
        
        // Try every coin in the coins vector
        for (int i = 0; i < coins.size(); i++) {
            // Recursive call: try to solve for amount reduced by coins[i]
            int ans = solveRec(coins, amount - coins[i]);
            
            // If the result from the recursive call is not INT_MAX, update minimum
            if (ans != INT_MAX) {
                minimum = min(minimum, 1 + ans);  // Add 1 to account for the current coin used
            }
        }
        
        // Return the minimum number of coins needed for the current amount
        return minimum;
    }

    /*
    int solveMemory(vector<int>& coin, int a , vector<int>& dp){
        if(a==0){
            return 0;
        }
        if(a<0){
            return INT_MAX;
        }

        if(dp[a] != -1){
            return dp[a];
        }
        int minimum=INT_MAX;
        for(int i=0; i<coin.size(); i++){
            int ans= solveMemory(coin,a-coin[i], dp);
            if(ans != INT_MAX){
                minimum=min(minimum,1+ans);
            }
        }
        dp[a]= minimum;
        return minimum;
    }
    */

public:
    // Main function to solve the coin change problem
    int coinChange(vector<int>& coins, int amount) {
        // Call the recursive helper function
        int ans = solveRec(coins, amount);
        
        // If ans is INT_MAX, return -1 to indicate no solution; otherwise, return ans
        return ans == INT_MAX ? -1 : ans;
    }

    /*
     vector<int> dp(amount+1, -1);
    int ans= solveMemory(coins, amount, dp);
    if(ans==INT_MAX){
        return  -1;
    }
    else

       return ans;
    }
    */
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};  // Example coin denominations
    int amount = 11;                // Example amount
    
    int result = sol.coinChange(coins, amount);
    if (result == -1) {
        cout << "It is not possible to make the amount with the given coins." << endl;
    } else {
        cout << "Minimum number of coins required: " << result << endl;
    }
    
    return 0;
}
