#include<iostream>
using namespace std;

class Animal{
public: 
int age;
int weight;

public:
void Bark(){
    cout<<"bhau bhau"<<endl;
}


};

class Human
{
public:

string color;

public:
void speak(){
    cout<<"speaking"<<endl;
}
};

//multiple inheritence
class Hybrid: public Animal, public Human{

};

int main()
{
    Hybrid H;
    H.speak();
    H.Bark();
    cout<<H.age<<endl;
       
    return 0;
}