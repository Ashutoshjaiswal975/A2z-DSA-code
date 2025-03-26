#include<iostream>
using namespace std;

int factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    /*.....both the methods are correct..........


    int smallerPblm= factorial(n-1);
    int biggerPblm=n*smallerPblm;

    return biggerPblm;
    
    */
    return n* factorial(n-1);
  
    
}

int main()
{
    int n;
    cout<<"enter the value to find factorial: "<<endl;
    cin>> n;



    int ans= factorial(n);
    cout<< ans<< endl;
    return 0;
}