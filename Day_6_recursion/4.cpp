#include<iostream>
using namespace std;


int febonacci(int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }

    int ans=febonacci(n-1)+febonacci(n-2);
    return ans;
}

int main()
{
    int n;
    cout<<"enter the value of posionto find no. : ";
    cin>>n;

    int result=febonacci(n);
    cout<<"the series is : "<<result<<endl;
    return 0;
}