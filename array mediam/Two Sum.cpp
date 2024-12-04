/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // Stores numbers and their indices
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // The number we need to find
            
            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i}; // Return indices of the two numbers
            }
            
            // Add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        return {}; // This line is unreachable because there is guaranteed to be a solution
    }
};