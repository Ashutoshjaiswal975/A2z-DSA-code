/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for (int i = 0; i < nums.size(); i++) { // Start from index 0
            if (nums[i] == 1) {
                count++; // Increment count for consecutive 1s
                maxCount = max(maxCount, count); // Update maximum
            } else {
                count = 0; // Reset count on encountering 0
            }
        }
        return maxCount; // Return the maximum count
    }
};