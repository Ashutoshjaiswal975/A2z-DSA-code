#include<iostream>
using namespace std;
int main(){
int n;
cout<<" enter : ";
cin>>n;
int i=1;
while (i<=n)
{ 
    //space print karlo
    int space=n-i;
    while (space)
    {
        cout<<" ";
        space=space-1;

    }
    //j print karlo
    int j=1;
    while(j<=i)
    {
        cout<<j;
        j=j+1;

    }
    //3rs star
    int k=i-1;
    while(k)
    {
        cout<<k;
        k=k-1;
    }
    cout<<endl;
    i=i+1;
}

return 0;
}