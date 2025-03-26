#include<iostream>
using namespace std;
int main(){

    int arr[100]={2,5};
    int n=100;
    for(int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }
   int arrSize= sizeof(arr)/sizeof(int);
   cout<<endl<<arrSize;
    return 0;
}
