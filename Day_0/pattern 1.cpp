#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    int i=0;
    while (i <n)
    {
       int j=1;
        while(j<=n)
    {
        cout<<j;
        j=j+1;
    }
    cout<<endl;
    i=i+1;
    }
return 0;
}