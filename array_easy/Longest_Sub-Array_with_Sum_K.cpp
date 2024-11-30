/*
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. It is guaranteed that a valid subarray exists.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, 9], k = 15
Output: 4
Explanation: The subarray [5, 2, 7, 1] has a sum of 15 and length 4.
*/
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumMap; // Stores prefix sum and its first occurrence index
    int sum = 0; // Running sum
    int maxCount = 0;

    prefixSumMap[0] = -1; // Base case: sum = 0 at index -1

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Calculate running sum

        // Check if there's a subarray with sum <= k
        if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
            maxCount = max(maxCount, i - prefixSumMap[sum - k]);
        }

        // Store the first occurrence of the prefix sum
        if (prefixSumMap.find(sum) == prefixSumMap.end()) {
            prefixSumMap[sum] = i;
        }
    }

    return maxCount;
}