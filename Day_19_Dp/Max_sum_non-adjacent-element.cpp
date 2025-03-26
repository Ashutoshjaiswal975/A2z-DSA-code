#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



/*
#include <bits/stdc++.h>

int solveSpace(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;  // Handle edge case: no elements
    if (n == 1) return nums[0];  // Handle edge case: only one element
    
    // Initialize two variables to store the results of the last two computations
    int prev2 = nums[0];  // This stores dp[i-2]
    int prev1 = max(nums[0], nums[1]);  // This stores dp[i-1]
    
    // Iterate through the array, starting from the 2nd index
    for (int i = 2; i < n; i++) {
        int curr = max(prev1, prev2 + nums[i]);  // Compute current dp value
        prev2 = prev1;  // Update prev2 to the previous dp[i-1]
        prev1 = curr;  // Update prev1 to the current dp value
    }

    return prev1;  // The final result is stored in prev1
}


int solveTab(vector<int> &nums ){
    int n= nums.size();
    if (n == 0) return 0;  // Handle edge case where nums is empty
    if (n == 1) return nums[0]; 
    vector<int>  dp(n, 0);
    dp[0]=nums[0];

    for(int i=1; i<=n; i++){
        int incl= dp[i-2]+nums[i];
        int excl = dp[i-1]+0;
        dp[i]=max(incl, excl);
    }
    return dp[n-1];
    

}



int solveMemo(vector<int> &nums , int n, vector<int> & dp){
 if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    if(dp[n]  != -1){
        return dp[n];
    }

     int incl= solveMemo(nums, n-2, dp)+nums[n];
    int excl= solveMemo(nums, n-1, dp)+0;

    dp[n]=max(incl, excl);
    return dp[n];

}






int solve(vector<int> &nums , int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    int incl= solve(nums, n-2)+nums[n];
    int excl= solve(nums, n-1)+0;
    return max(incl, excl);
    
}
int maximumNonAdjacentSum(vector<int> &nums){
    return solveSpace(nums);
    // return solveTab(nums);

    /*
    int n=nums.size();
    vector<int> dp(n, -1);
    int ans= solveMemo(nums, n-1, dp);
    return ans;
    */
    
    /*
    int n= nums.size();
    int ans= solve(nums, n-1);
    return ans;
    
}

*/



// Helper function to solve the problem using recursion with memoization
int solve(vector<int>& nums, int n, vector<int>& dp) {
    if (n < 0) {
        return 0; // No element to take
    }
    if (n == 0) {
        return nums[0]; // Only one element, so return it
    }
    if (dp[n] != -1) {
        return dp[n]; // Return cached result if already calculated
    }

    // Calculate the max sum by either including or excluding the current element
    int incl = solve(nums, n - 2, dp) + nums[n];  // Include the current element and skip the adjacent
    int excl = solve(nums, n - 1, dp);  // Exclude the current element

    dp[n] = max(incl, excl);  // Store the result in the dp array
    return dp[n];
}

int maximumNonAdjacentSum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0; // No elements, return 0
    vector<int> dp(n, -1); // Memoization array to store results
    return solve(nums, n - 1, dp);
}

int main() {
    vector<int> nums = {3, 2, 7, 10};  // Example input
    cout << "Maximum Non-Adjacent Sum: " << maximumNonAdjacentSum(nums) << endl;
    return 0;
}
