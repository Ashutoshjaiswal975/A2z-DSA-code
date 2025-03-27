#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sorting-Based Approach (Original)
void sortAndRearrange(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // Print first half in ascending order
    for (int i = 0; i < n / 2; i++) {
        cout << arr[i] << " ";
    }
    
    // Print second half in descending order
    for (int i = n - 1; i >= n / 2; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Two-Pointer Approach (Alternative Efficient Method)
void rearrangeWithoutSorting(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;

    vector<int> result;
    while (left <= right) {
        if (left != right) result.push_back(arr[left]); // First half
        result.push_back(arr[right]); // Second half
        left++;
        right--;
    }

    // Print result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {8, 7, 1, 6, 5, 9};

    cout << "Using Sorting-Based Approach:\n";
    sortAndRearrange(arr);

    cout << "\nUsing Two-Pointer Approach (Alternative):\n";
    rearrangeWithoutSorting(arr);

    return 0;
}
