/*
Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The elements of the array are 1 4 3 2 6 5. After reversing the
 array, the first element goes to the last position, the second element goes to the 
 second last position and so on. Hence, the answer is 5 6 2 3 4 1.
*/

void reverseArray(std::vector<int>& arr, int start, int end) {
    // Base case: stop recursion if start index is greater than or equal to end index
    if (start >= end) {
        return;
    }

    // Swap the elements at the start and end positions
    std::swap(arr[start], arr[end]);

    // Recursive call to reverse the rest of the array
    reverseArray(arr, start + 1, end - 1);
}
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
    reverseArray(arr, 0, n - 1); 
    }


