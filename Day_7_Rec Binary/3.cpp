#include <iostream>
using namespace std;

bool searchElement(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {

        return searchElement(arr + 1, size - 1, key);
    }
}

int main()
{
    int n;
    cout << "enter the value of size of an array: ";
    cin >> n;

    // for addresing size to the array
    int *arr = new int[n];

    // taking input for array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // printing output of element of an array
    cout << "your array is: ";
    for (int i = 0; i < n; i++)
    {
        int k = arr[i];
        cout << k << " ";
    }
    cout << endl;
    int key;
    cout << "enter the element for search: ";
    cin >> key;

    cout << endl
         << endl;

    // function calling
    int ans = searchElement(arr, n, key);
    // for printing output
    if (ans)
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    
    delete[] arr;

    return 0;
}