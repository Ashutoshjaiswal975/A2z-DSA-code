#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximumZeroes(vector<int>& arr) {
        int n = arr.size();
        int totalZeroes = 0;

        // Edge case: if the array is empty
        if (n == 0) return 0;

        // Count total zeroes in the original array
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                totalZeroes++;
            }
        }

        // Edge case: if all elements are zero, return the total number of zeroes minus one
        if (totalZeroes == n) return totalZeroes - 1;

        // We will use Kadane's Algorithm-like approach to find the best subarray to flip
        int maxDiff = 0;  // This will store the maximum difference between flipped and unflipped segments
        int currentDiff = 0;

        // Traverse the array and compute the effect of flipping each element
        for (int i = 0; i < n; ++i) {
            // If arr[i] is 1, flipping it to 0 increases zero count (+1),
            // If arr[i] is 0, flipping it to 1 decreases zero count (-1).
            int valueToConsider = (arr[i] == 0) ? -1 : 1;
            currentDiff += valueToConsider;

            // If the current subarray sum (currentDiff) becomes negative, reset it
            if (currentDiff < 0) {
                currentDiff = 0;
            }

            // Keep track of the maximum possible difference we can achieve by flipping a subarray
            maxDiff = max(maxDiff, currentDiff);
        }

        // Maximum zeroes we can get is totalZeroes + maxDiff
        return totalZeroes + maxDiff;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5 , 2 , 5, 9, 3,5};

    int result = sol.findMaximumZeroes(arr);
    cout << "Maximum number of zeroes after flipping a subarray: " << result << endl;

    return 0;
}
