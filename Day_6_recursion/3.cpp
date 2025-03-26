#include<iostream>
using namespace std;

int reachHome(int dest, int src)
{


    cout<<"i am at: "<<src<<" and my destita is: "<<dest<<endl;
    if (src==dest)
    {
        cout<<"reached: "<<endl;
        return 1;

    }
    //processing
    src++;

    //recursion function
    reachHome(dest, src);

    
}


int main()
{
int dest, src;
cout<<"enter the destinaton: ";
cin>>dest;

cout<<"where are u standing: ";
cin>>src;

reachHome(dest, src);

}