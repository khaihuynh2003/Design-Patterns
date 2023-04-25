// Decorator Pattern
#include <iostream>
#include <string>
using namespace std;

class Beverage{
    protected:
        string description;
    public:
        Beverage(){
            description = "Unknown Beverage";
        }
        Beverage(string description): description(description){}
        
        virtual string getDescription(){
            return description;
        }
        virtual double cost() = 0;

        virtual ~Beverage(){}
};

class CondimentDecorator: public Beverage{
    public:
        virtual string getDescription() = 0;
};

class HouseBlend: public Beverage{
    public:
        HouseBlend(){
            description = "House Blend Coffee";
        }
        double cost(){
            return 0.89;
        }
};

class DarkRoast: public Beverage{
    public:
        DarkRoast(){
            description = "Dark Roast Coffee";
        }
        double cost(){
            return 0.99;
        }
};

class Decaf: public Beverage{
    public:
        Decaf(){
            description = "Decaf Coffee";
        }
        double cost(){
            return 1.05;
        }
};

class Espresso: public Beverage{
    public:
        Espresso(){
            description = "Espresso";
        }
        double cost(){
            return 1.99;
        }
};
//
class Milk: public CondimentDecorator{
    private:
        Beverage *beverage;
    public:
        Milk(Beverage *beverage): beverage(beverage){}

        string getDescription(){
            return beverage->getDescription() + ", Milk";
        }

        double cost(){
            return 0.10 + beverage->cost();
        }
};

class Mocha: public CondimentDecorator{
    private:
        Beverage *beverage;
    public:
        Mocha(Beverage *beverage): beverage(beverage){}

        string getDescription(){
            return beverage->getDescription() + ", Mocha";
        }

        double cost(){
            return 0.20 + beverage->cost();
        }
};

class Soy: public CondimentDecorator{
    private:
        Beverage *beverage;
    public:
        Soy(Beverage *beverage): beverage(beverage){}

        string getDescription(){
            return beverage->getDescription() + ", Soy";
        }

        double cost(){
            return 0.15 + beverage->cost();
        }
};

class Whip: public CondimentDecorator{
    private:
        Beverage *beverage;
    public:
        Whip(Beverage *beverage): beverage(beverage){}

        string getDescription(){
            return beverage->getDescription() + ", Whip";
        }

        double cost(){
            return 0.10 + beverage->cost();
        }
};

int main()
{
    /*
    Starbuzz Coffee Menu
    Coffees
    House Blend      .89
    Dark Roast       .99
    Decaf            1.05
    Espresso         1.99

    Condiments
    Steamed Milk     .10
    Mocha            .20
    Soy              .15
    Whip             .10
    */

    // Order an Espresso with Milk and Mocha
    Beverage* beverage1 = new Espresso();
    beverage1 = new Milk(beverage1);
    beverage1 = new Mocha(beverage1);
    cout << beverage1->getDescription() << " $" << beverage1->cost() << endl;

    // Order a Dark Roast with Mocha and Soy
    Beverage* beverage2 = new DarkRoast();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Soy(beverage2);
    cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;

    delete beverage1;
    delete beverage2;

}

