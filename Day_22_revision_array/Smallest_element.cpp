#include<iostream>
#include<vector>

// #include <bits/stdc++.h> 
using namespace std;

int smallestElement(vector<int> &arr, int n) {
    int min = arr[0]; // Initialize min with the first element
    for(int i = 0; i < n; i++) {
        if(min > arr[i]) {
            min = arr[i]; // Update min if a smaller element is found
        }
    }
    return min;
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

    int minElement = smallestElement(arr, n);
    cout << "The smallest element in the array is: " << minElement << endl;

    return 0;
}
