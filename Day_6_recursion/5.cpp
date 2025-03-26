#include<iostream>
using namespace std;

int count(long long n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans= count(n-1)+count(n-2);
    return ans;
}
int main()
{
int n;
cout<<"enter the value: ";
cin>>n;

cout<<count(n)<<endl;
return 0;
}