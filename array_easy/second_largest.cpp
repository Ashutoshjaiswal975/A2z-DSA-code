/*
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
*/


class Solution {
public:
    // Function to find the second largest element
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1; // If less than 2 elements, no second largest

        int largest = INT_MIN, second = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (arr[i] > largest) {
                second = largest; // Update second largest
                largest = arr[i]; // Update largest
            } else if (arr[i] > second && arr[i] != largest) {
                second = arr[i]; // Update second largest if it's not equal to the largest
            }
        }
        return (second == INT_MIN) ? -1 : second; // Return -1 if no second largest
    }
};