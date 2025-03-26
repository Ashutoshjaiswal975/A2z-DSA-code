#include <iostream>
using namespace std;
int binaryS(int arr[],int size,int target,bool isFirst){
    int ans=-1;
    int start=0;
    int end=size-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]>target) {end=mid-1;}
        else if(arr[mid]<target){ start=mid+1;ans=mid;}
        else{
            ans=mid;
            if(isFirst) end=mid-1;
            else start=mid+1;
        }
    }
    return ans;
}
int main()
{
    int arr[6] = {1, 1, 1,1,1,5};
    int index1=binaryS(arr,6,1,true);
    int index2=binaryS(arr,6,1,false);
    cout << "first occurence of 1 is "<< index1<<endl;
    cout << "last occurence of 1 is "<< index2<<endl;
    return 0;
}