#include<iostream>
using namespace std;

int sumArray(int arr[], int size)
{

if (size==0)
{
    return 0;
}

if (size==1)
{
    return arr[0];

}
int ans=arr[0]+sumArray(arr+1,size-1);
return ans;
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
    int ans = sumArray(arr,  n);

    cout<<"the sum is: "<<ans<<endl;


    delete[] arr;

    return 0;
}