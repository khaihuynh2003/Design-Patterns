// STRATEGY PATTERN
#include <iostream>
using namespace std;

class flyBehavior{
    public:
        virtual void fly() = 0;
};
class flyWithWings: public flyBehavior{
    public:
        void fly(){
            cout << "I have wings and I'm flying!" << endl;
        }
};
class flyNoWay: public flyBehavior{
    public:
        void fly(){
            cout << "I can't fly bruhh!" << endl;
        }
};
class flyRocketPowered: public flyBehavior{
    public:
        void fly(){
            cout << "I'm flying with a rocket!" << endl;
        }
};

class quackBehavior{
    public:
        virtual void quack() = 0;
};
class Quack: public quackBehavior{
    public:
        void quack(){
            cout << "Quack Quack Quack!" << endl;
        }
};
class Squeak: public quackBehavior{
    public:
        void quack(){
            cout << "Squeak Squeak Squeak!" << endl;
        }
};
class MuteQuack: public quackBehavior{
    public:
        void quack(){
            cout << "I can't quack bruhh!" << endl;
        }
};

class Duck{
    protected:
        flyBehavior* flying;
        quackBehavior* quacking;
    public:
        void setFlyBehavior(flyBehavior* flying){
            this->flying = flying;
        }
        void setQuackBehavior(quackBehavior* quacking){
            this->quacking = quacking;
        }
        void performFly(){
            flying->fly();
        }
        void performQuack(){
            quacking->quack();
        } 
        void swim(){
            cout << "Kaka, I'm swimming! No one can stop me!" << endl;
        }
        virtual void display() = 0;  
};

class mallardDuck: public Duck{
    public:
        mallardDuck(){
            flying = new flyWithWings();
            quacking = new Quack();
        }
        void display(){
            cout << "I'm a real Mallard duck!" << endl;
        }
};

class modelDuck: public Duck{
    public:
        modelDuck(){
            flying = new flyNoWay();
            quacking = new Quack();
        }
        void display(){
            cout << "I'm a model duck" << endl;
        }
};

int main()
{
    // Create a mallard duck
    mallardDuck d1;
    d1.display();
    d1.performFly();
    d1.performQuack();
    d1.swim();
    
    cout << endl;

    // Create a model duck
    modelDuck d2;
    d2.display();
    d2.performFly();
    d2.setFlyBehavior(new flyRocketPowered() ); // give it a rocket!!!
    d2.performFly();
}