#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;


int **arr= new int*[n];

for(int i=0; i<n; i++){
    arr[i]= new int[n];
}
//creation done;

cout<<"enter the elements"<<endl;
//taking input of element
for (int i = 0; i <n; i++)
{
    for (int j = 0;j<n; j++)
    {
        cin>>arr[i][j];
    }
    
}

//for output
cout<<endl;
for (int i = 0; i <n; i++)
{
    for (int j = 0;j<n; j++)
    {
        cout<<arr[i][j]<<" ";
    }cout<<endl;
    
}




    return 0;
}
