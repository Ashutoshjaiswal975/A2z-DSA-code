#include<iostream>
#include<vector>
using namespace std;


void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i=0, j=0;
    int k=0; 
    while (i<n && j<m){
    if(arr1[i]<arr2[j])
    {
        arr3[k] =arr1[i];
        k++;
        i++;
    }
    else{
         arr3[k] =arr2[j];
         k++;
         j++;
    }
   
    
    
    }
     while (i<n)
    {
        arr3[k]=arr1[i];
        k++;
        i++;
    }

 
     while (j<m)
    {
        arr3[k]=arr2[j];
        k++;
        j++;
    }
    

}




 void print(int ans[], int n )
 {
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 }




int main(){
int arr1[5]={5, 6,8,9,13};
int arr2[3]={ 7,10,11};
 int arr3[8]={0};

 merge(arr1, 5, arr2, 3, arr3);
 print(arr3, 8);
return 0;
}