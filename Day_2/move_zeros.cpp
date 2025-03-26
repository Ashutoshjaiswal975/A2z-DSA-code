#include<iostream>
#include<vector>
using namespace std;

// Define the function to move zeroes
void moveZeroes(vector<int> &nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != 0) {
            swap(nums[j], nums[i]);
            i++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare the vector to hold the elements
    vector<int> arr(n);

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to move zeroes
    moveZeroes(arr);

    // Output the modified array
    cout << "Array after moving zeroes to the end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
