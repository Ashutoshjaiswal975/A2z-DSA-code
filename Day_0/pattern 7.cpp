#include<iostream>
using namespace std;
int main(){
int n;
cout<<" enter the value of :";
cin>>n;
int i=1;

while (i<=n)
{
    int j=1;
    int v = i;
    while (j<=i)
    {
        cout<<v;
        v=v+1;
        j=j+1; 
    }
    
    cout<<endl;
    i=i+1;
}
return 0;
}