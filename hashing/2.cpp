/*

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

 

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
*/

int maxFrequency(vector<int>& nums, int k)  {
    // Step 1: Sort the array to enable the sliding window approach
    sort(nums.begin(), nums.end());
    
    // Step 2: Initialize variables
    long long sum = 0; // Sum of elements in the current window
    int left = 0;      // Left pointer of the window
    int maxFreq = 0;   // Maximum frequency found

    // Step 3: Use a sliding window approach
    for (int right = 0; right < nums.size(); right++) {
        // Add the current element to the sum
        sum += nums[right];

        // Check if the current window is valid
        // The condition checks if we can make all elements in the window equal to nums[right]
        while ((long long)nums[right] * (right - left + 1) - sum > k) {
            // If not valid, reduce the window size from the left
            sum -= nums[left];
            left++;
        }

        // Update the maximum frequency found
        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq;
}