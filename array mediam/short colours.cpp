/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, i = 0;
        
        while (i <= high) {
            if (nums[i] == 0) { // Red
                swap(nums[i], nums[low]);
                low++;
                i++;
            } else if (nums[i] == 2) { // Blue
                swap(nums[i], nums[high]);
                high--;
            } else { // White
                i++;
            }
        }
    }
};