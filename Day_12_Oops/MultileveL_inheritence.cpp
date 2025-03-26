#include<iostream>
using namespace std;

class Animal{
public: 
int age;
int weight;

public:
void speak(){
    cout<<"speaking"<<endl;
}


};

class Dog: public Animal
{

};

class Pug: public Dog{

};



int main()
{
    Pug d;
    d.speak();
    cout<<d.age<<endl;
       
    return 0;
}