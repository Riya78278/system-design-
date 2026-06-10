#include<iostream>
using namespace std;

// making of abstract classes

//talkable
class Talkable{
    public:
    virtual void talk()=0;
};

class NormalTalk:public Talkable{
    public:
    void talk () override{
        cout<<"hi this is normaltalk"<<endl;
    }
};

class Nonnormaltalk: public Talkable{
    public:
    void talk() override{
        cout<<"hi this is for non-normal-talk"<<endl;
    }
};

// abstract class walkable

class Walkable{
    public:
    virtual void walk()=0;
};

class Normalwalk: public Walkable{
    public:
    void walk() override{
        cout<<"hi this ia normal walk"<<endl;
    }
};

class NonNormalwalk : public Walkable{
    public:
    void walk() override{
        cout<<"hi this is non-normal-walk"<<endl;
    }
};

class Flyable{
    public:
    virtual void fly()=0;
};

class NormalFly: public Flyable{
    public:
    void fly() override{
        cout<<"hi this ia normal fly"<<endl;
    }
};

class NonNormalfly : public Flyable{
    public:
    void fly() override{
        cout<<"hi this is non-normal-fly"<<endl;
    }
};

// user class

class Robot{
    private:
    Talkable* talking;
    Walkable* walking;
    Flyable* flying;

    public:
    virtual void projection()=0;

    public:
    Robot( Talkable* talking,Walkable* walking,Flyable* flying){
        this->talking=talking;
        this->walking=walking;
        this->flying=flying;

    }
    void talk(){
        talking->talk();
    }

    void walk(){
        walking->walk();

    }
    void fly(){
        flying->fly();
    }
};

class Companion : public Robot{
    public:
    Companion(Talkable* talking,Walkable* walking,Flyable* flying) 
    : Robot(talking,walking,flying){}

    void projection(){
        cout<<"hi companion projection"<<endl;
    }
};

class workablerobot : public Robot{
    public:
    workablerobot(Talkable* talking,Walkable* walking,Flyable* flying) 
    : Robot(talking,walking,flying){}

    void projection(){
        cout<<"hi workable projection"<<endl;
    }
};

int main(){
    Robot* robot1= new Companion(new NormalTalk(),new NonNormalwalk(),new NonNormalfly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

}