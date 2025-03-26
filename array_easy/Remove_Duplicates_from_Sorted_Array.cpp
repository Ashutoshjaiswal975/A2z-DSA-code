/*

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:
 */

 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Handle empty array

        int k = 1; // Tracks the position of the next unique element
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) { // Check if the current element is unique
                nums[k] = nums[i]; // Move the unique element to position `k`
                k++; // Increment the position
            }
        }
        return k; // Return the count of unique elements
    }
};
