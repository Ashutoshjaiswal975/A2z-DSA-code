#include<iostream>
using namespace std;
int main(){
  int n;
cout<<"enter the value :";
cin>>n;
int i=1;
 char ch='a';
while (i<=n)
{
    int j=1;
    // char ch='a';
    while (j<=i)
    {
        cout<<ch;
        ch=ch+1;
        j=j+1;

    }
cout<<endl;
i=i+1;
    
}

return 0;
}