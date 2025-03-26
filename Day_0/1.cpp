#include<iostream>
using namespace std;
 int i=1;
 void name(int n){
    if(i<=n){
        cout<<i;
        name(i++);

    }
 }
 int main(){

    name(5);
    return 0;
 }
 