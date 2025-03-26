#include<iostream>
#include<array>

using namespace std;
int main(){
    int basic[3]={1,2,3};
array<int, 4> a={1,2,3,4};
int size=a.size();
for(int i=0;i<size;i++){
    cout<<a[i]<<endl;
}
cout<<"element at 2nd index :"<<a.at(2) <<endl;
cout<<"array is empty :"<<a.empty() <<endl;
cout<<"element at first position : "<<a.front() <<endl;
cout<<"element at first position : "<<a.back()<<endl;
}