//node.cpp
//Kyle Zalewski
//CS202
//Programming assignment 3

#include "node.h"

//node constructor
node::node()
{
    //set child pointers to null
    child1 = NULL;
    child2 = NULL;
    child3 = NULL;
    child4 = NULL; 
    
    //set data pointers to null
    f1 = NULL;
    f2 = NULL;
    f3 = NULL;
}

//node copy constructor
node::node(const node & n)
{
    //copy child pointers
    child1 = n.child1;
    child2 = n.child2;
    child3 = n.child3;
    child3 = n.child4;

    //copy data pointers
    f1 = n.f1;
    f2 = n.f2;
    f3 = n.f3;
}

//add food object pointer to node
node::node(food * f)
{
    //if node has no items
    if(!f1)
    {
        f1 = f;
        return;
    }

    //if node has only one item
    if(!f2)
    {
        //if passed in item name is less than current f1
        if(f < f1)
        {
            f2 = f1;
            f1 = f;
            return;
        }
        //if passed in item name is more than current f1
        f2 = f;
             return;
    }

    //if node has 2 items
    if(!f3)
    {
        //if passed in item name is less than current f1
        if(f < f1)
        {
            f3 = f2;
            f2 = f1;
            f1 = f;
            return;
        }
        //if passed in item name is less than current f2
        if(f < f2)
        {
            f3 = f2;
            f2 = f;
            return;
        }
        //if passed in item name is greater than both
        f3 = f;
        return;
    }

    //if node is full
    if(f3)
    {
        //promote f2
        node * newLeft = new node;
        node * newRight = new node;

        newLeft->f1 = f1;
        newRight->f1 = f3;
        f1 = f2;

        child1 = newLeft;
        child1->parent = this;

        child2 = newRight;
        child2->parent = this;

        delete f2;
        delete f3;
    }
    return;
}

//node destructor
node::~node()
{
    //remove pointers
    child1 = NULL;
    child2 = NULL;
    child3 = NULL;
    child4 = NULL;

    parent = NULL;

    //delete data;
    delete f1;
    delete f2;
    delete f3;
}

//node display (2-node only)
void node::display()
{
    if(!child1)
    {
        //display f1
        food * ptr = f1;
        if(typeid(*ptr) == typeid(appetizer))
        {
            appetizer * temp = dynamic_cast<appetizer*>(ptr);
            cout << *temp;
        }
        else if(typeid(*ptr) == typeid(beverage))
        {
            beverage * temp = dynamic_cast<beverage*>(ptr);
            cout << *temp;
        }
        else
        {
            mainCourse * temp = dynamic_cast<mainCourse*>(ptr);
            cout << *temp;
        }
    }
}

//assignment operator overload
node & node::operator = (const node & n)
{
    //check for self reference
    if(this == &n)
        return * this;

    //delete data pointers if present
    if(f1) //2-node
    {
        delete f1;
        child1 = NULL;
        child2 = NULL;
    }

    if(f2) //3-node
    {
        delete f2;
        child3 = NULL;
    }

    if(f3) //4-node
    {
        delete f3;
        child4 = NULL;
    }
    
    parent = NULL;

    //assign new data pointers
    f1 = n.f1;
    f2 = n.f2;
    f3 = n.f3;

    //assign new child pointers
    child1 = n.child1;
    child2 = n.child2;
    child3 = n.child3;
    child4 = n.child4;

    //assign new parent pointer
    parent = n.parent;
    
    //return modified object;
    return * this;
}

//+= operator overload
node & node::operator += (food * f)
{
    if(!f3)
    {
        if(!f2)
        {
            if(!f1)
            {
                f1 = f;
                return *this;
            }
            f2 = f;
            return *this;
        }        
        f3 = f;
        return *this;
    }
    return *this;
}

//child pointer get functions
node * node::goChild1()
{
    return child1;
}

node * node::goChild2()
{
    return child2;
}

node * node::goChild3()
{
    return child3;
}

node * node::goChild4()
{
    return child4;
}

//child pointer set functions
void node::setChild(node * newChild)
{
    //if node has no children
    if(!child1)
    {
        child1 = newChild;
        return;
    }
    
    //if node has children
    if(!child2)
        child2 = newChild;
    else if(!child3)
        child3 = newChild;
    else
        child4 = newChild;
    return;
}

bool node::noChildren()
{
    if(!child1)
        return true;
    return false;
}

