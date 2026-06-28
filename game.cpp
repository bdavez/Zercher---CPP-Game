/* 
Name: Brendan Davis
AU ID: 3616762
Date: 2024-06-28 
Program: Assignment 4 - Game Project
*/

/*
 DOCUMENTATION
  Accreditation: 
    Found at  https://cplusplus.com/forum/beginner/182128/ for the idea of use cin.clear() 
    and cin.ignore() to help flush standard input after malformed input to avoid unusal activity.

 Program Purpose:
    A choose your own adventure game

 Classes:
    Game - parent class to all offering a main function for objects setup and to be passed through
    Character - nested class of game containing character description
    Scene - nested class of game containing scene description
    Item - nested class of game containing item description
    Inventory - nested class of game containing inventory management
    Control - nested class of game containing control elements
    Action - nested class of game containing action elements

 Variables:
    tempFile - temeperary file input for reading game strings
    counter - integer iterator
    character - Character game object
    inv - Inventory game object
    control - Control game object
    name[6] - an object array of game characters 

    sceneDescription - a string describing what's going on in the location the player resides

    description - a string describing an item

    itemList[13] - an object array of items 
    usable- a boolean value to determine if the item has been picked up or not

    tempZone - temporary integer value to determine which location to move to next
    zoneID - a integer determining which zone the player is currently in
    place[6] - an object array of locations
    inv - inventory object 
    hasKey - boolean value to determine if player has the required item 

    gameActive - a boolean value to determine whether or not to continue game loop
    tempItem - a string containing player choice input
    tempDrop - a string containing player choice input
    abv- a character representation of player input for action
    itemChoice - an integer to represent player input

*/

/*
 TEST PLAN
 
 Normal case:


    You are Alice you have found that you have fallen through a rabbit hole you find yourself at: You find yourself at Wonderland Woods it looks a little creepy. 
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: p
    items available are: 
    1 : The big/small mushroom
    2 : Caterpillar’s hookah
    3 : Golden Key
    What would you like to pickup?:
    1
    Picked up: The big/small mushroom
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: i
    Your inventory contains: 
    ID: 1 : The big/small mushroom
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: d
    items available to drop are: 
    ID: 1 : The big/small mushroom
    What would you like to drop ([0] is cancel)?:
    1
    Dropped: The big/small mushroom
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: m
    Where would you like to move to? [Zones 1-5]: 5
    Missing key item - [Ace of Hearts Playing Card]
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: m
    Where would you like to move to? [Zones 1-5]: 2
    You find yourself at the Mad Hatters Tea Party, he keeps talking nonsense. 
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: p
    items available are: 
    4 : Tea cup and saucer
    5 : Tea cookies/biscuits
    6 : Mad Hatter’s Hat
    What would you like to pickup?:
    6
    Picked up: Mad Hatter’s Hat
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: q

 Bad Data case 1 (Malformed input):

    You are Alice you have found that you have fallen through a rabbit hole you find yourself at: You find yourself at Wonderland Woods it looks a little creepy. 
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: #$%#$@
    Please enter a valid choice
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: p
    items available are: 
    1 : The big/small mushroom
    2 : Caterpillar’s hookah
    3 : Golden Key
    What would you like to pickup?:
    @#$@#$@#$
    Please enter one of the given numbers above instead
    That item does not exist here
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: m
    Where would you like to move to? [Zones 1-5]: #$%#$%
    Please enter one of the given numbers above instead
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: q
 
 Bad Data case 2 (Integer instead of character/string input):


    You are Alice you have found that you have fallen through a rabbit hole you find yourself at: You find yourself at Wonderland Woods it looks a little creepy. 
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: 1234
    Please enter a valid choice
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: p
    items available are: 
    1 : The big/small mushroom
    2 : Caterpillar’s hookah
    3 : Golden Key
    What would you like to pickup?:
    ABCD
    Please enter one of the given numbers above instead
    That item does not exist here
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: q

 
 Bad Data case 3 (floating point input)


    You are Alice you have found that you have fallen through a rabbit hole you find yourself at: You find yourself at Wonderland Woods it looks a little creepy. 
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: 2.222
    Please enter a valid choice
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: p
    items available are: 
    1 : The big/small mushroom
    2 : Caterpillar’s hookah
    3 : Golden Key
    What would you like to pickup?:
    2.22
    Picked up: Caterpillar’s hookah
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: Please enter a valid choice
    What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: q
 
 Discussion:
    This program uses input from the user to navigate a choose your own adventure game
    Input is needed for an action
    Additional input may be required after an action decision is made 
 
*/

#include <iostream>
#include <fstream>

using namespace std;

void checkInput() {
    if (cin.fail()) {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter one of the given numbers above instead" << endl;
    }
}

void setupFile(string fileName, string className) {


}

class Game {
    private:
     
    public:
    void main() {
        ifstream tempFile;
        string line;
        tempFile.open("character.txt");
        Character character;
        int counter = 1;
            while(getline(tempFile,line)) {
                character.setName(counter,line);
                counter++;
            }
        tempFile.close();
        counter = 1;

        Inventory inv; 
        tempFile.open("items.txt");
            while(getline(tempFile,line)) {
                inv.usableInv(counter,line);
                counter++;
            }
        tempFile.close();
        counter = 1;

        
        Control control;
        tempFile.open("locations.txt");
        while(getline(tempFile,line)) {
            control.updateZone(counter,line);
            counter++;
        }
        tempFile.close();
        counter = 1;

        Action action(inv, control, character);
        action.decision();



    }

    class Character {
        private: 
            string name[6];
        public:
            void setName(int nameID, string name) {
                this-> name[nameID] = name;
            }
            string getName(int nameID) {
                return " You see " + name[nameID] + " looking at you.";
            }
    };
    class Scene {
        private: 
            string sceneDescription;
            int zone = 1;

        public:
            void setScene(int zones, string Description) {
                sceneDescription = Description;
                zone = zones;
            }
            string getSceneDesc() {
                return sceneDescription;
            }
            int getZoneID() {
                return zone;
            } 
    };

    class Item {
        private:
            string descrption;
            bool usable = false;
        public:
            void setItem(string desc) {
                descrption = desc;
                usable = false;
            }
            void setItemDesc(string item) {
                descrption = item;
            }
            string getDesc() {
                return descrption;
            }
            void setUsable() {
                usable = true;
            }
            void unusable() {
                usable = false;
            }
            bool checkUsable() {
                return usable;
            }
    };

    class Inventory {
        public:
        Inventory(){}
        
        private:
            Item itemList[13];
        public:
            void checkInv() {
                for(int i = 1; i < 13; i++) {
                    if(itemList[i].checkUsable()) {
                        cout << "ID: " << i << " : " << itemList[i].getDesc() << endl;
                    }
                }
            }
            void usableInv(int itemID, string desc) {
                itemList[itemID].setItem(desc);
            }

            string addInv(int itemId) {
                itemList[itemId].setUsable();
                return itemList[itemId].getDesc();
            }
            string removeInv(int itemId) {
                itemList[itemId].unusable();
                return itemList[itemId].getDesc();
            }
            void checkItem(int itemId) {
                cout << itemId << " : " << itemList[itemId].getDesc() << endl;
            }
            bool hasItem(int itemID) {
                return itemList[itemID].checkUsable();
            }
    };

    class Control {
        public:
            Control(){};
        private:
            int tempZone;
            int zoneID = 1;
            Scene place[6];
            Inventory inv;
            bool hasKey = false;
        public:
            void move() {
                cout << "Where would you like to move to? [Zones 1-5]: " << ends;
                cin >> tempZone;
                checkInput();
                switch (tempZone)
                {
                case 1:
                    zoneID = 1;
                    cout << place[1].getSceneDesc() << endl;
                    break;
                case 2:
                    zoneID = 2;
                    cout << place[2].getSceneDesc() << endl;
                    break;
                case 3:
                    zoneID = 3;
                    cout << place[3].getSceneDesc() << endl;
                    break;
                case 4:
                    zoneID = 4;
                    cout << place[4].getSceneDesc() << endl;
                    break;
                case 5:
                    if(hasKey == true) {
                        zoneID = 5;
                        cout<< place[5].getSceneDesc() << endl;
                        cout << "Story Completed!" << endl;
                    }
                    else {
                        cout << "Missing key item - [Ace of Hearts Playing Card]" << endl;
                    }
                    break;
                default:
                    cout << "That location does not exist" << endl;
                    break;
                }
            }
            void updateZone(int zoneID, string desc) {
                place[zoneID].setScene(zoneID, desc);
            }
            int getCurrentZone() {
                return zoneID;
            }
            string getSceneDesc(int zoneID) {
                return place[zoneID].getSceneDesc();
            }
            void removeLock() {
                hasKey = true;
            }
            void addLock() {
                hasKey = false;
            }
        };


    class Action {
        public:
        Action(Inventory inv, Control move, Character character) {
            this->inv = inv;
            this->move = move;
            this->character = character;
        }
        private:
            bool gameActive = true;
            int tempItem, tempDrop;
            char abv;
            int itemChoice;
            string choice;
            Control move;
            Scene location;
            Inventory inv;
            Character character;

        public: 
            void decision() {
                cout << "You are Alice you have found that you have fallen through a rabbit hole you find yourself at: " << move.getSceneDesc(move.getCurrentZone()) << endl;
                while(gameActive) {
                cout << "What would you like to do?[Available actions are: (p)ickup, (d)rop, (i)nventory, (m)ove, (w)here, (q)uit]: " << ends;
                cin >> choice;
                abv = choice[0];
                tolower(abv);
                switch (abv)
                {
                case 'p': 
                    cout << "items available are: " << endl;
                    switch (move.getCurrentZone())
                    {
                    case 1:
                        inv.checkItem(1);
                        inv.checkItem(2);
                        inv.checkItem(3);
                        break;
                    case 2: 
                        inv.checkItem(4);
                        inv.checkItem(5);
                        inv.checkItem(6);
                        break;
                    case 3:
                        inv.checkItem(7);
                        inv.checkItem(8);
                        inv.checkItem(9);
                        break;
                    case 4:
                        inv.checkItem(10);
                        inv.checkItem(11);
                        inv.checkItem(12);
                        break;
                    case 5:
                        cout << "No items" << endl;
                    default:
                        break;
                    }
                    cout << "What would you like to pickup?:" << endl;
                    cin >> tempItem;
                    checkInput();
                    switch(move.getCurrentZone())
                    {
                        case 1:
                            if(tempItem == 1 || tempItem == 2 || tempItem == 3) {
                                cout << "Picked up: " << inv.addInv(tempItem) << endl;
                            }
                            else {
                                cout << "That item does not exist here" << endl;
                            }
                            break;
                        case 2:
                            if(tempItem == 4 || tempItem == 5 || tempItem == 6) {
                                cout << "Picked up: " << inv.addInv(tempItem) << endl;
                            }
                            else {
                                cout << "That item does not exist here, please pick a number from the options above" << endl;
                            }
                            break;
                        case 3:
                            if(tempItem == 7 || tempItem == 8 || tempItem == 9) {
                                cout << "Picked up: " << inv.addInv(tempItem) << endl;
                                if(tempItem == 9) {
                                    move.removeLock();
                                }
                            }
                            else {
                                cout << "That item does not exist here" << endl;
                            }
                            break;
                        case 4:
                            if(tempItem == 10 || tempItem == 11 || tempItem == 12) {
                                cout << "Picked up: " << inv.addInv(tempItem) << endl;
                            }
                            else {
                                cout << "That item does not exist here" << endl;
                            }
                            break;
                        case 5:
                            cout << "There are no items to pickup here, you already beat the game" << endl;
                            break;
                        default:
                            cout << "No Items have been picked up" << endl;
                    }
                    break;
                
                case 'd': 
                    cout << "items available to drop are: " << endl;
                    inv.checkInv();
                    cout << "What would you like to drop ([0] is cancel)?:" << endl;
                    cin >> tempDrop;
                    checkInput();
                    if(tempDrop == 0) {
                        break;
                    } else if (tempDrop == 9) {
                        move.addLock();
                    }
                    cout << "Dropped: " << inv.removeInv(tempDrop) << endl;
                    break;

                case 'q':
                    gameActive = false;
                    break;

                case 'i':
                    cout << "Your inventory contains: " << endl; 
                    inv.checkInv();
                    break;

                case 'm':
                    move.move();
                    break;
                case 'w': 
                    cout << move.getCurrentZone() << ends;
                    cout << " - " << move.getSceneDesc(move.getCurrentZone()) << character.getName(move.getCurrentZone()) << endl;
                    break;        
                default:
                    cout << "Please enter a valid choice" << endl;
                    break;
                }
            }
        }
 
    };

};



int main () 
{
    Game wonderland;
    wonderland.main();

}