#include <iostream>
using namespace std;

int main(){
    int num=5;
    double d= 4.3;

    cout<<num<<endl;
    //adress of operator= &

    cout<<"adress of num is "<<&num<<endl;
    int *ptr=&num;
    double *p2=&d;
//it showws address stored on ptr
    cout<<"the value is : "<<ptr<<endl;
    // its shows value stored on that adddress
    cout<<"the value is : "<<*ptr<<endl;

    cout<<"size of num is: "<<sizeof(num)<<endl;
    cout<<"size of ptr is: "<<sizeof(ptr)<<endl;
    cout<<"size of p2 is: "<<sizeof(p2)<<endl;
/*..................................................*/
//pointer to int is created, and pointing to some garbage value
// int *p=0;
// cout<<*p<<endl;

int i=5;
int *p=&i;
// same as
int *p=0;
p=&i;
///// important concept


    return 0;

}