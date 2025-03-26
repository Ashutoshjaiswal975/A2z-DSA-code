#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;

    // for creating 2 new array
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy elements to temporary arrays
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge the two sorted arrays
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] <= second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy remaining elements, if any
    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Free allocated memory
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e) {
    // Base case
    if (s >= e) {
        return;
    }

    int mid = s + (e - s) / 2;

    // Sort the left part
    mergeSort(arr, s, mid);

    // Sort the right part
    mergeSort(arr, mid + 1, e);

    // Merge the sorted parts
    merge(arr, s, e);
}

int main() {
    int n;
    cout << "1. Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "2. Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "3. Your array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Function call to sort the array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "4. Sorted array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] arr;

    return 0;
}
