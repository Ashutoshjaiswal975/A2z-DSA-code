#include<iostream>
#include<vector>

using namespace std;
int main(){
   vector<int> v;
   cout<<"size-> "<<v.capacity()<<endl;
   v.push_back(1);
   cout<<"size-> "<<v.capacity()<<endl;
     v.push_back(3);
      cout<<"size-> "<<v.capacity()<<endl;
       v.push_back(3);
      cout<<"size-> "<<v.capacity()<<endl;
      cout<<"size="<<v.size()<<endl;

      cout<<"before pop"<<endl;
      for (int i:v)
      {
        cout<<i<<" ";
      }cout<<endl;

      
      v.pop_back();
      cout<<"after pop"<<endl;
      for (int i:v)
      {
        cout<<i<<" ";
      }cout<<endl;

      cout<<"size-> "<<v.capacity()<<endl;
      
   

}

