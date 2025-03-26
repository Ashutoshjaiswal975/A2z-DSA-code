#include<iostream>
using namespace std;

void update(int arr[], int n)
{
cout<<"enter the function "<< endl;
arr[2]=120;
 for (int i = 0; i < 3; i++)
    {
    cout<< arr[i]<<" ";
    }
    cout<< endl;



cout<<"back to main "<< endl;
}


int main(){


    int arr[3]={3,2,4};
    update (arr, 3);
    for (int i = 0; i < 3; i++)
    {
    cout<< arr[i]<<" ";
    }cout<< endl;
    

return 0;
}