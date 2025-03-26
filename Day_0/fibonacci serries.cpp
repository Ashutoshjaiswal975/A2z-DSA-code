#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter the value: ";

cin>>n;
int a=0;
int b=1;

for(int i=0; i<=n; i++)
{
    int nextNumber=a+b;
    cout<<nextNumber<<" ";
    a=b;
    b=nextNumber;
     
}
return 0;
}