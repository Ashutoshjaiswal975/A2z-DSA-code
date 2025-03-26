#include<iostream>
using namespace std;

int binarySearch(int n)
{
    int s=0;
    int e=n;
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int sqr=mid*mid;
        if(sqr==n)
        {
            return mid;
        }
        if(sqr<n)
        {
            ans=mid;
            s=mid+1;

        }
        else
        {
            e=mid-1;
        }
        

    }
    return ans;
}


double morePrecision(int n, int precision, int tempsol)
{
double factor=1;
double ans=tempsol;
for (int i = 0; i < precision ; i++)
{
    factor=factor/10;
    for (double j = ans; j*j<n; j+factor)
    {
        ans=j;
    }
    
}
return ans;

}
int main(){
    int n;

    cout<<"enter the value "<< endl;
    cin>>n;
    int tempSol=binarySearch(n);
    cout<<"ans is "<<morePrecision(n, 3, tempSol)<<endl;


return 0;
}