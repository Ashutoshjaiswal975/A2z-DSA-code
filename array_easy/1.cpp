/*
Given an array arr[]. The task is to find the largest element and return it.

Examples:

Input: arr = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.
*/

class Solution {
public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        int ans = arr[0]; // Initialize with the first element
        for (int i = 1; i < n; i++) { // Iterate through the array
            if (arr[i] > ans) { // Update if a larger element is found
                ans = arr[i];
            }
        }
        return ans; // Return the largest element
    }
};