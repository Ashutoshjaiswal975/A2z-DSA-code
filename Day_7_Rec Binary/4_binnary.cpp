#include<iostream>
using namespace std;

bool BinarySearchElement(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return true;
    }
    else if (arr[mid] < key)
    {
        return BinarySearchElement(arr, mid + 1, e, key);
    }
    else
    {
        return BinarySearchElement(arr, s, mid - 1, key);
    }
}

int main()
{
    int n;
    cout << "Enter the value of size of an array: ";
    cin >> n;

    // dynamically allocate the array
    int *arr = new int[n];

    // taking input for array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // printing the elements of the array
    cout << "Your array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    // function calling
    bool ans = BinarySearchElement(arr, 0, n - 1, key);

    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // deallocate the array
    delete[] arr;

    return 0;
}
