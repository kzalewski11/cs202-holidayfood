//food.h
//Kyle Zalewski
//CS202
//Programming assignment 3

#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

//food abstract base class
class food
{
    public:
        food();                             //default constructor
        food(const food & f);                    //copy constructor
        void virtual display() const;                 //virtual display
        virtual ~food();                            //destructor

        virtual food & operator = (char * name);   //assignment operator overload


        //relational operator overload for food class objects
        friend bool operator < (food & f1, food & f2);
        friend bool operator > (food & f1, food & f2);
        friend bool operator == (food & f1, food & f2);
        friend bool operator != (food & f1, food & f2);

        //output operator overload


    protected:
        char * name;                        //food name
        bool glutenFree;                    //is food gluten free
        bool vegetarian;                    //is food vegetarian
        bool vegan;                         //is food vegan
        bool containsNuts;                  //does food contain nuts
        bool lowFat;                        //is food low fat

    private:

};

//appetizer derived class
class appetizer:public food
{
    public:
        appetizer();                        //default constructor
        friend ostream & operator << (ostream &out, appetizer & a);

    private:
        bool filling;                       //can the appetizer suffice as a main course
};

//beverage derived class
class beverage:public food
{
    public:
        beverage();                         //default constructor

        //output overload
        friend ostream & operator << (ostream &out, beverage & b);

    private:
        bool caffeinated;                   //does the beverage contain caffeine
        bool alcoholic;                     //does the beverage contain alcohol
};

//mainCourse derived class
class mainCourse:public food
{
    public:
        mainCourse();                       //default constructor
        mainCourse(const mainCourse & m);        //copy constructor
        ~mainCourse();                      //destructor
        
        //output overload
        friend ostream & operator << (ostream &out, mainCourse & m);

        mainCourse & operator = (const mainCourse & m);     //assignment operator overload

    private:
        char * meatType;                     //what meat does the main course contain
};

//client interface menu function
int mainMenu();

//food type selection menu
int typeMenu();

//add food name
void enterName(food * item);
