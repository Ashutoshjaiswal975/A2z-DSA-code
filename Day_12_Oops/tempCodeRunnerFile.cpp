#include<iostream>
using namespace std;

class Human{
   public:
   int height;
   int weight;
   int age;

   public:
   int gatAge(){
    return this-> age;

   }
   void setWeight(int w){
    this-> weight=w;
   }

};

class Male: public Human{
public:
string color;

void sleep(){
    cout<<"male is sleep"<<endl;
}
};

int main()
{

Male object1;

cout<<"sab sahii chal raha h"<<"---"<<object1.age<<endl;
cout<<object1.height<<endl;
cout<<object1.weight<<endl;

cout<<object1.color<<"---"<<endl;
    return 0;
}