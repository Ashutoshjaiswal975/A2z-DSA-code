#include <iostream>
using namespace std;


int firstOccurance(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans=-1;
    
    while (start <= end)
    {
      int mid = start + ((end - start) / 2);
        if (arr[mid] == key)
        {
            ans= mid;
            end=mid-1;
        }

        // for left
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int lastOccurance(int ar[], int s, int k)
{
    int start = 0;
    int end = s - 1;
    int ans=-1;
    while (start <= end)
    {
      
        int mid = start + ((end - start) / 2);
        if (ar[mid] == k)
        {
            ans= mid;
            start=mid + 1;
           
        }

        if ( ar[mid]<k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int arr[6] = {1, 2,2,1,1,5};
    int index1 = firstOccurance(arr, 6, 1);
    
    cout << "first occurence of 1 is "<< index1<<endl;
    int index2 = lastOccurance(arr, 6, 1);
    cout << "last occurence of 1 is "<< index2<<endl;
    return 0;
}