#include<iostream>
using namespace std;
int main(){
int n;
cout<<" enter : ";
cin>>n;
int i=1;

while (i<=n)
{ 
    int first=5;
    // first=n-i+1
    while (first<=i)

    {
        cout<<first;
        first=first-1;
    }
    
      

        
        
    


     int star1=i-1;
    while (star1)

    {
        cout<<"*";
        star1=star1-1;
    }

    int star2=i-1;
    while (star2)

    {
        cout<<"*";
        star2=star2-1;
    }
    

  int last=n-i+1;
  while (last)
  {
    cout<<last;
    last=last-1;
  }
  
    
    cout<<endl;
    i=i+1;
}

return 0;
}