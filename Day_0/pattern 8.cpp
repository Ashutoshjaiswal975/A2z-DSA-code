#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter the value :";

cin>>n;
int i=1;
while (i<=n)
{
    char ch = 'a';
    int j =1;
    while (j<=n)
    {
         char ch ='a'+i-1 ;
        cout<<ch <<" ";
        j=j+1;
    }
    cout<<endl;
    i=i+1;
}

return 0;
}