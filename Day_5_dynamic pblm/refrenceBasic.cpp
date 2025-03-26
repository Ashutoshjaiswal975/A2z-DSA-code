#include <iostream>
using namespace std;


/* dangerous practice....return of reference..it has 
drawbacks...it canot acces the memory
int& update(int n){
    int a=10;
    int &ans=a;
    return ans;
}
*/

//refrence variable
void update2(int &n){
    n++;
}


//normal function
void update1(int n){
    n++;
}

int main()
{
  /*  int i = 5;
    // create refrence variable
    int &j = i;

    cout << i << " " << j << endl;

    i++;
    cout << j << endl;
    j++;
    cout << i << endl;
    */

   int n=5;
   cout << n<<endl;

  // it calls normal function
   update1(n);
   cout<<"after: "<<n<<endl;

   // it calls refrence variable function
    update2(n);
   cout<<"after: "<<n<<endl;

    return 0;
}