//main.cpp
//Kyle Zalewski
//CS202
//Programing assignemnt 3

#include "tree.h"

int main()
{
    //create tree object
    tree t;

    //main menu display
    int choice = mainMenu();

    //keep displaying menu until user exits
    do
    {
        //show all food items
        if(choice == 1)
            t.display();

        //add new food item
        if(choice == 2)
        {
            food * item;
            //display food type menu
            int foodChoice = typeMenu();
            //if choice is appetizer
            if(foodChoice == 1)
            {
                item = new appetizer;

            }
            //if choice is beverage
            else if (foodChoice == 2)
            {
                item = new beverage;
            }
            //if choice is main course
            else
            {
                item = new mainCourse;
            }

            //user input name
            enterName(item);
            
            bool success = t.insert(item);
            if(success)
                cout << "Food successfully added to catalog.\n";
        }
    
        //if exit has been chosen
        if(choice == 3)
        {
            cout << "Thank you for using the food catalog. Goodbye.\n";
            return 0;
        }

        //check user choice again
        choice = mainMenu();
    }while(choice > 0 && choice < 3);

    
    //trivial return
    return 0;
}
