//food.cpp
//Kyle Zalewski
//CS202
//Programming assignment 3

#include "food.h"

//food abstract base class constructor
food::food()
{
    name = NULL;
    glutenFree = false;
    vegetarian = false;
    vegan = false;
    containsNuts = false;
    lowFat = false;
}

//food class copy constructor
food::food(const food & f)
{
    name = new char[strlen(f.name + 1)];
    strcpy(name, f.name);
    glutenFree = f.glutenFree;
    vegetarian = f.vegetarian;
    vegan = f.vegan;
    containsNuts = f.containsNuts;
    lowFat = f.lowFat;
}

//food base class display function
void food::display() const
{
    cout << "Item name: " << name << endl;
    if(glutenFree)
        cout << "Gluten Free\n";
    else
        cout << "Not Gluten Free\n";
    if(vegetarian)
        cout << "Vegetarian\n";
    else
        cout << "Not Vegetarian\n";
    if(vegan)
        cout << "Vegan\n";
    else
        cout << "Not Vegan\n";
    if(containsNuts)
        cout << "Contains Nuts\n";
    else
        cout << "Does not contain nuts\n";
    if(lowFat)
        cout << "Low Fat\n";
    else
        cout << "Not Low Fat\n";
}


//food class virtual destructor
food::~food()
{
    delete [] name;
}

//food class assignment operator overload
food & food::operator = (char * f)
{
    delete name;
    name = new char[strlen(f) + 1];
    strcpy(name, f);
    return *this;
}

//relational operator overload for food class objects
bool operator < (food & f1, food & f2)
{
    if(strcmp(f1.name, f2.name) < 0)
        return true;
    return false;
}

bool operator > (food & f1, food & f2)
{
    if(strcmp(f1.name, f2.name) > 0)
        return true;
    return false;
}

bool operator == (food & f1, food & f2)
{
    if(strcmp(f1.name, f2.name) == 0)
        return true;
    return false;
}

bool operator != (food & f1, food & f2)
{
    if(strcmp(f1.name, f2.name) != 0)
        return true;
    return false;
}

//appetizer class default constructor
appetizer::appetizer()
{
    filling = false;
}

//appetizer class output overload
ostream & operator << (ostream &out, appetizer & a)
{
    a.display();
    if(a.filling)
        out << "This appetizer is filling enough to serve as a meal\n";
    else
        out << "This appetizer is not filling enough to serve as a meal\n";

    return out;
}

//beverage class constructor
beverage::beverage()
{
    caffeinated = false;
    alcoholic = false;
}

//beverage class output overload
ostream & operator << (ostream &out, beverage & b)
{
    b.display();
    if(b.caffeinated)
        out << "This beverage is caffeinated\n";
    else
        out << "This beverage is not caffeinated\n";
    if(b.alcoholic)
        out << "This beverage is alcoholic\n";
    else
        out << "This beverage is non-alcoholic\n";

    return out;
}

//mainCourse class constructor
mainCourse::mainCourse()
{
    meatType = NULL;
}

//mainCourse copy constructor
mainCourse::mainCourse(const mainCourse & m) : food(m)
{
    meatType = new char[strlen(m.meatType) + 1];
    strcpy(meatType, m.meatType);    
}

//mainCourse class destructor
mainCourse::~mainCourse()
{
    delete [] meatType;
}

//mainCourse output operator overload
ostream & operator << (ostream &out, mainCourse & m)
{
    m.display();
    out << "The main meat used in this dish is " << m.meatType << endl;

    return out;
}

//mainCourse class assignment operator overload
mainCourse & mainCourse::operator = (const mainCourse & m)
{
    delete [] meatType;
    meatType = new char[strlen(m.meatType) + 1];
    strcpy(meatType, m.meatType);
    return *this;
}

//client interface main menu function
int mainMenu()
{

    int choice = 0;

    cout << "Welcome to the meal information system.\n";
    cout << "Please make a selection:\n";
    cout << "1) View all food in catalog\n";
    cout << "2) Add a new item to catalog\n";
    cout << "3) Exit the program\n";

    cin >> choice;
    cin.ignore(100, '\n');

    while(choice > 3 || !cin)
    {
        cout << "Invalid choice. Please try again.\n";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> choice;
    }

    return choice;
}

//food type selection menu
int typeMenu()
{
    int choice = 0;
    cout << "Please select the type of food you would like to enter\n";
    cout << "1) Appetizer\n";
    cout << "2) Beverage\n";
    cout << "3) Main Course\n";

    cin >> choice;
    cin.ignore(100,'\n');

    while(choice > 3 || !cin)
    {
        cout << "Invalid choice. Please try again.\n";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> choice;
    }

    return choice;
}

//add food name function
void enterName(food * item)
{
    cout << "Please enter name of dish to add\n";
    char temp[100];
    cin.getline(temp, 100);
    char * name = new char[strlen(temp) + 1];
    strcpy(name, temp);
    *item = name;
    delete name;
}
