#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter  the value of numbers to enter : "<<endl;
cin>>n;
int arr[n];
cout<<"enter the values: "<<endl;
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}






for (int i = 0; i <= n-1; i++)
// for round 1 to n-1
{
     for( int j = 0; j < n-i-1; j++)
     {
        if (arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
     }
     
}






cout<<"sort value of arrey:\n"<<endl;
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}


return 0;
}