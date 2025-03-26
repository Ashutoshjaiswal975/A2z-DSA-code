class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    int prefixSum = 0, count = 0;

    // Initialize the map to handle the case where a subarray starts from index 0
    prefixSumCount[0] = 1;

    for (int num : nums) {
        prefixSum += num;  // Update the running sum
        
        // Check if prefixSum - k exists in the map
        if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - k];  // Add the count of such subarrays
        }

        // Update the frequency of the current prefixSum in the map
        prefixSumCount[prefixSum]++;
    }

    return count;
}

};