#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {

    // sort(a.begin(), a.end());
    // return {a[n-2], a[1]};

    if (n < 2) return {-1, -1}; // Handle edge case where second order elements don't exist.

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {
        // Finding First and Second Maximum
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2 && a[i] < max1) {
            max2 = a[i];
        }

        // Finding First and Second Minimum
        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        } else if (a[i] < min2 && a[i] > min1) {
            min2 = a[i];
        }
    }

    return {max2, min2}; // Second largest and second smallest elements
}

int main() {
    vector<int> arr = {5, 1, 9, 3, 7, 2, 8};
    vector<int> result = getSecondOrderElements(arr.size(), arr);

    cout << "Second Largest: " << result[0] << "\nSecond Smallest: " << result[1] << endl;
    return 0;
}
