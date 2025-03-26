#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{

    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
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
    cout<<"your array is: ";
    for (int i = 0; i < n; i++)
    {
        int k=arr[i];
        cout <<k << " ";
    }

    cout << endl<< endl;


    // function calling
    bool ans = isSorted(arr, n);

    

    // printing the ans
    if (ans)
    {
        cout << "array is sorted" << endl;
    }
    else
    {
        cout << "array is not sorted" << endl;
    }

    delete[] arr;

    return 0;
}