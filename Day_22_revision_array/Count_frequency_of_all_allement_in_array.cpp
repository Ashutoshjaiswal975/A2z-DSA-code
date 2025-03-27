#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Naive Approach: Using a visited array
void countFreq(int arr[], int n) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue; // Skip already processed elements

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}

// Efficient Approach: Using Unordered Map
void Frequency(int arr[], int n) {
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    // Print frequencies
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
}

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Using Naive Approach:\n";
    countFreq(arr, n);

    cout << "\nUsing HashMap Approach:\n";
    Frequency(arr, n);

    return 0;
}
