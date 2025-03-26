#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    //int mid = (start + end) / 2;// it is workonly for small integer value
    int mid=(start+ ((end-start)/2));
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        // go to right part
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        // for lleft part
        else
        {
            end = mid - 1;
        }
       // mid = (start + end) / 2;
       mid=(start+ ((end-start)/2));
    }
    return -1;
}

int main()
{
    int even[6] = {6, 8, 10, 12, 14, 16};
    int odd[5] = {3, 7, 9, 13, 19};

    int index = binarySearch(even, 6, 16);
    cout << "index of 12 is" << index << endl;
    return 0;
}