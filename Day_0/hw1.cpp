#include<iostream>
using namespace std;


int main()
{
    int n;
    int sum=0;

    cin >> n ;
    int arr[10];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        
        
        sum=sum+arr[i];

        // cout<<"sum of the array: "<< sum ;  
    }
  cout<<"sum of the array: "<< sum ;  

return 0;
}