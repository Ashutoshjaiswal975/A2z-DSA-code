#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    int arr[10] = {8, 4, 6, 5, 10, 7, 9, 3, 7, 2};
    // weather 1 is present in it or not?

    cout << "enter the element for search: " << endl;
    int key;
    cin >> key;

    bool found = search(arr, 10, key);

    if (found)
    {
        cout << "key is present" << endl;
    }
    else
    {
        cout << "the key is absent" << endl;
    }
    return 0;
}