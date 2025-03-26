/*
Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400] , k = 2
Output: 700
Explanation: arr3  + arr4 = 700, which is maximum.
*/

class Solution {
public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int i = 0, j = 0; // Window start and end
        int sum = 0, mx = INT_MIN; // Sliding window sum and maximum sum

        while (j < arr.size()) {
            // Add current element to the window
            sum += arr[j];

            // Check if the window size is `k`
            if (j - i + 1 == k) {
                // Update the maximum sum
                mx = max(mx, sum);
                // Slide the window forward
                sum -= arr[i]; // Remove the element going out of the window
                i++;
            }
            j++;
        }
        return mx;
    }
};
