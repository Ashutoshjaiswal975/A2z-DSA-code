#include<iostream>
using namespace std;

int getPivot(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (mid < e && arr[mid] > arr[mid + 1]) {
            return mid + 1;
        }
        if (mid > s && arr[mid] < arr[mid - 1]) {
            return mid;
        }
        if (arr[mid] >= arr[s]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return s;
}

int binarySearch(int arr[], int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int findPosition(int arr[], int n, int k) {
    int pivot = getPivot(arr, n);

    if (arr[pivot] == k) {
        return pivot;
    }
    if (arr[0] <= k) {
        return binarySearch(arr, 0, pivot - 1, k);
    }
    return binarySearch(arr, pivot, n - 1, k);
}

int main() {
    int arr[5] = {7, 9, 1, 2, 3};
    int key;
    cout << "Enter the value of key to find: " << endl;
    cin >> key;

    int position = findPosition(arr, 5, key);

    cout << "The position of key is: " << position << endl;
    return 0;
}

