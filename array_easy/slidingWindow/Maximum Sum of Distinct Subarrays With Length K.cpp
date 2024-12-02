/*
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // Tracks the frequency of numbers
        int start = 0;
        long long sum = 0, maxSum = 0;

        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];  // Add current number to the sum
            freq[nums[end]]++; // Increase its frequency

            // If the window is too large, shrink it
            if (end - start + 1 > k) {
                sum -= nums[start];          // Remove the number at `start`
                freq[nums[start]]--;         // Decrease its frequency
                if (freq[nums[start]] == 0)  // If frequency is 0, remove it from map
                    freq.erase(nums[start]);
                start++;                     // Move the window forward
            }

            // Check if the current window is valid
            if (end - start + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, sum); // Update maximum sum
            }
        }

        return maxSum;
    }
};