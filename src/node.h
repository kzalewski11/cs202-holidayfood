//node.h
//Kyle Zalewski
//CS202
//Programming assignment 3

#include "food.h"

//node class
class node
{
    public:
        node();                                 //default constructor
        node(const node & n);                       //copy constructor
        node(food * f);                   //add food object to node
        ~node();                                //destructor

        void display();                         //node display (2-node only)

        node & operator = (const node & n);       //assignment operator overload
        node & operator += (food * f);              //adds food to node

        //child pointer "get" functions
        node * goChild1();                         //go to child 1
        node * goChild2();                         //go to child 2
        node * goChild3();                         //go to child 3
        node * goChild4();                         //go to child 4

        //child pointer "set" function
        void setChild(node * newChild);                        //set child

        bool noChildren();

    private:
        //child pointers
        node * child1;
        node * child2;
        node * child3;
        node * child4;

        //parent pointer
        node * parent;

        //data pointers
        food * f1;
        food * f2;
        food * f3;
};
