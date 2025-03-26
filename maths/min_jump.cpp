/*
Given an array arr[] of non-negative integers. Each array element represents the maximum length of the jumps that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x. Find the minimum number of jumps to reach the end of the array starting from the first element. If an element is 0, then you cannot move through that element.

Note:  Return -1 if you can't reach the end of the array.

Examples : 

Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Output: 3 
Explanation: First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 
*/

class Solution {
  public:
    int minJumps(vector<int>& arr) {
          int n = arr.size();
        
        // Edge case: if the array has only one element, no jumps are needed.
        if (n <= 1) {
            return 0;
        }
        
        // If the first element is 0, we cannot move anywhere.
        if (arr[0] == 0) {
            return -1;
        }
        
        // Variables to track the maximum reach, steps in the current range, and jump count.
        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;
        
        for (int i = 1; i < n; i++) {
            // Check if we've reached the end of the array.
            if (i == n - 1) {
                return jumps;
            }
            
            // Update the maximum reach.
            maxReach = std::max(maxReach, i + arr[i]);
            
            // Decrease the step count.
            steps--;
            
            // If no more steps are left:
            if (steps == 0) {
                jumps++;
                
                // Check if we can still move forward.
                if (i >= maxReach) {
                    return -1;  // We can't reach further.
                }
                
                // Re-initialize the steps to the number of steps to reach `maxReach` from `i`.
                steps = maxReach - i;
            }
        }
        
        return -1;  // If the end isn't reachable.
    }
};