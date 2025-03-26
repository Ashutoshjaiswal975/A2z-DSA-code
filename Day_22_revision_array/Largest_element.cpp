#include<iostream>
#include<vector>

// #include <bits/stdc++.h> 
using namespace std;

int largestElement(vector<int> & arr, int n) {
    // sort(arr.begin(), arr.end());
    // return arr[n-1];

    int max = arr[0];
    for(int i = 0; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxElement = largestElement(arr, n);
    cout << "The largest element in the array is: " << maxElement << endl;

    return 0;
}
