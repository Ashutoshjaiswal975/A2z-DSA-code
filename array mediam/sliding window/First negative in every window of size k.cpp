/*
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window {-8, 2}: First negative integer is -8.
Window {2, 3}: No negative integers, output is 0.
Window {3, -6}: First negative integer is -6.
Window {-6, 10}: First negative integer is -6.
*/

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
        int i = 0, j = 0; // Window start and end
        deque<int> dq;    // To store indices of negative numbers
        vector<int> result; // To store the result

        while (j < arr.size()) {
            // Add the current element to the deque if it's negative
            if (arr[j] < 0) {
                dq.push_back(j);
            }

            // Check if the window size is `k`
            if (j - i + 1 == k) {
                // Add the first negative number to the result (or 0 if none exists)
                if (!dq.empty() && dq.front() >= i) {
                    result.push_back(arr[dq.front()]);
                } else {
                    result.push_back(0);
                }

                // Slide the window forward
                if (!dq.empty() && dq.front() == i) {
                    dq.pop_front(); // Remove index going out of the window
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
