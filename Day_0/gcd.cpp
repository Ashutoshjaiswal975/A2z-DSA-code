#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a==0)
    return b;
    if(b==0)
    return a;

    while(a!=b)
    {
        if(a>b)
        {
        a=a-b;
        }
        else{
           b= b-a;
        }
    }
    return a;
}

int main(){
int a, b;
cout<<"enter the value of a: "<<endl;
cin>>a;
cout<<"enter the value of b: "<<endl;
cin>>b;

int ans=gcd(a,b);
cout<<"the gcd between a and b is: "<<ans<<endl;
return 0;
}