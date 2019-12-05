//tree.h
//Kyle Zalewski
//CS202
//Programming assignment 3

#include "node.h"

//2-3-4 tree class
class tree
{
    public:
        tree();                                 //default constructor
        tree(const tree & t);                       //copy constructor
        ~tree();                                //destructor
        bool insert(food * & item);                          //insert object into tree function
        void display() const;                         //display tree wrapper (headings)

        tree * operator = (node * & n);   //assignment operator overload

    private:
        void display(node * root) const;
        node * root;                            //root pointer

};

