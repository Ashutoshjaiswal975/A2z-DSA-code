/*
Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is: 
4 . 
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubArrayWithSumK(vector<int>& arr, int K) {
    unordered_map<int, int> prefixSumMap; // To store prefix sums and their indices
    int currentSum = 0;                  // Running sum of elements
    int maxLength = 0;                   // Length of the longest subarray

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i]; // Update the current sum

        // If the current sum equals K, update maxLength
        if (currentSum == K) {
            maxLength = i + 1;
        }

        // Check if the difference between currentSum and K exists in the map
        if (prefixSumMap.find(currentSum - K) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[currentSum - K]);
        }

        // Store the current sum in the map if it doesn't already exist
        if (prefixSumMap.find(currentSum) == prefixSumMap.end()) {
            prefixSumMap[currentSum] = i;
        }
    }

    return maxLength;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, K;
        cin >> n >> K; // Array size and target sum
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << longestSubArrayWithSumK(arr, K) << endl;
    }

    return 0;
}
