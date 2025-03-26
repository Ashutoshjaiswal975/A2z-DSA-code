#include<iostream>
#include<cstring>
// #include"Hero.cpp"
using namespace std;

class Hero{
private:
    //properties
    char* name;
 
    int health;
public:
    char level;
   

   

    Hero(){
        cout<<" constrocter called"<<endl;
        name= new char[100];
    }


    Hero(int helth)
    {
        cout<<"this->"<<this<<endl;
        this->health=health;
    }

    Hero(int health, int level)
    {
        cout<<"this->"<<this<<endl;
        this->health=health;
        this->level=level;
    }

    Hero(const Hero& temp){
        char* ch= new char[strlen(temp.name)+1];
        strcpy(name, temp.name);
        this->name=ch;
        this->level= temp.level;
        this->health=temp.health;
    }


    void Print(){
        cout<<"health "<<this->health<<endl;
        cout<<"level :"<<this->level<<endl;
     
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health=h;
    }

    void setLevel(char ch){
        level =ch;
    }



};


class Ashu{
    char ch;
    char ab;
    int a;
    int j;
    double t;

};


int main()
{


Hero bhai(70,'c');
bhai.Print();

Hero bahen(bhai);
bahen.Print();







    /*
//object created statically
cout<<"hi"<<endl;

Hero raja(10);
cout<<"address of raja: "<<&raja<<endl;
cout<<"hemlo"<<endl;





 creation of an object.............level 1.............
    Hero ramesh;
    ramesh.health=10;
    ramesh.level='b';
    cout<<"heatlth is: "<<ramesh.health<<endl;
    cout<<"level is: "<<ramesh.level<<endl;

    cout<<"size : "<<sizeof(ramesh)<<endl;
......it give size of whole class...............

//.............level 2..........................
//static allocation
Hero raju;
raju.setHealth(80);
raju.setLevel('2');
cout<<"level in static: "<<raju.level<<endl;
cout<<"health in static; "<<raju.getHealth()<<endl;


cout<<"size : "<<sizeof(raju)<<endl;

cout<<"......................."<<endl;
// dynamically 
Hero *b= new Hero;
b->setHealth(20);
b->setLevel('1');

cout<<"level in dynamic: "<<(*b).level<<endl;
cout<<"health in dynamic; "<<(*b).getHealth()<<endl;
// another way
cout<<"level in dynamic: "<<b->level<<endl;
cout<<"health in dynamic; "<<b->getHealth()<<endl;

raju.setHealth(70);
cout<<"health of raju: "<<raju.getHealth()<<endl;
//............................
cout<<"........................."<<endl;
Ashu a1;
cout<<"size : "<<sizeof(a1)<<endl;
//............................*/

    return 0;
}