
#include <iostream>
using namespace std;


void printArray( int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
       // cin >> arr[i];
       cout << arr[i] << " ";
    }
    cout<<endl;
 
}

void swap(int ar[], int size)
{
    for (int i = 0; i < size; i +=2)
    {
        if (i+1< size)
        {
            swap(ar[i], ar[i + 1]);
        }
    }
}

int main()
{
    int n;
    cout << " enter the no. of element" << endl;
    cin >> n;

    int arr[10];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
   
   swap(arr, n);
   printArray(arr, n);

  // cout<< "swap the array" <<printArray(arr,n) <<endl;


    return 0;
}