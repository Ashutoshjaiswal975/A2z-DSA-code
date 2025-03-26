#include <iostream>
using namespace std;

bool isPresent(int arr[3][4], int target, int i, int j)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

int max(int arr[3][4]){
    int maxi = INT_MIN;
    int rowIndex=-1;
    for (int i = 0; i < 3; ++i)
    {
      int sum=0;
        for (int j = 0; j < 4; ++j)
        {
            sum=sum+arr[i][j];
           
        }

if(sum>maxi){
    maxi=sum;
    rowIndex= i;
}
}


int printSum(int arr[3][4]){
    int sum=0;
    for (int i = 0; i < 3; ++i)
    {
      
        for (int j = 0; j < 4; ++j)
        {
            sum=sum+arr[i][j];
            cout<<sum<<" ";
        }
       
       cout<<endl;
    }

}


int main()
{
    // int n, m;
    // cin>>n;
    // cin>>m;
    int arr[3][4];
    cout << "enter the values: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }





    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }







    cout << "enter the value to search: " << endl;
    int target;
    cin >> target;

    if (isPresent(arr, target, 3, 4))
    {
        cout << "element found";
    }
    else
    {
        cout << "not found";
    }

    cout<<endl;

     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << printSum(arr) << " ";
        }
        cout << endl;
    }
   
    

    return 0;
}