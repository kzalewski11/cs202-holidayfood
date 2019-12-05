//tree.cpp
//Kyle Zalewski
//CS202
//Programming assignment 3

#include "tree.h"

//tree constructor
tree::tree()
{
    //set root to null
    root = NULL;
}

//tree copy constructor
tree::tree(const tree & t)
{   
    root = t.root;
}

//tree destructor
tree::~tree()
{
    delete root;
}

//insert node into list function
bool tree::insert(food * & item)
{
    //if list is empty
    if(!root)
    {
        node * newNode = new node(item);
        root = newNode;
        return true;
    }

    //if list has contents
    *root += item;

    //if no node was added (trivial)
    return false;
}

//display tree in sorted order
void tree::display() const
{
    cout << "Current catalog entries:\n";
    cout << "________________________\n\n";
    display(root);
    cout << endl << endl;
}

//display tree recursively
void tree::display(node * root) const
{
    //if tree is empty
    if(!root)
    {
        cout << "No items added to list.\n";
        return;
    }

    //if tree only has a single 2-node
    if(root->noChildren())
    {
        root->display();
        return;
    }

    //otherwise
    root->goChild1()->display();
    root->goChild2()->display();
    root->goChild3()->display();
    root->goChild4()->display();
}

//assignment operator overload
tree * tree::operator = (node * & n)
{
    root = n;
    return this;
}

