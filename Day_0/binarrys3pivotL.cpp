#include <iostream>
using namespace std;

int getPivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
         mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{

    int arrr[6] = {11 , 12, 1, 5,7};
    int index=getPivot(arrr, 6);
    cout << "pivot is " << index << endl;

    return 0;
}