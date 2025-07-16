#include "Player.h"
#include <Windows.h>
#include <iostream>

using namespace std;

Player::Player() : currentRoom(nullptr) {
    currentRoom = nullptr;
    bag = new Bag(); // create a new bag
    inventory.push_back(bag); // add bag to inventory
}
void Player::startGame()
{
    cout << "\n";
    cout << "Entering World.\n";
    Sleep(600);
    system("cls");
    cout << "Entering World..\n";
    Sleep(600);
    system("cls");
    cout << "Entering World...\n";
    Sleep(600);
    system("cls");
    cout << "\n\nHello!";
    cout << "\n\nI have to find the money my father left me!\n\nHe told me I could also take some things that I need for my expedition." << endl;
    cout << "\nHe also gave me a DICTIONARY that will help me when I need it!\n\n";
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::move(const string& direction) {

    const vector<string> validDirections = { "north", "south", "east", "west", "North", "South", "West", "East" };//Cheking valid directions
    if (find(validDirections.begin(), validDirections.end(), direction) == validDirections.end()) {
        cout << "Sorry, I don't understand what direction you have said.\n";
        return;
    }

    Room* nextRoom = currentRoom->getExit(direction);
    if (nextRoom == nullptr) {
        cout << "You can't go this direction. There is a wall here!\n";
        return;
    }
    else if (nextRoom->isLocked()) {
        if (hasItem("key")) {
            cout << "You use the key to unlock the door.\n";
            nextRoom->unlock();
            currentRoom = nextRoom;
        }
        else {
            cout << "The door is locked. You need a key.\n";
        }
    }
    else {
        currentRoom = nextRoom;
        cout << "You go " << direction << ".\n";
    }
}

void Player::takeItem(string itemName) {
    auto& items = currentRoom->getItems();
    for (Item* item : items) {
        if (item->getName() == itemName) {
            inventory.push_back(item);
            currentRoom->removeItem(item);
            cout << "You take the " << itemName << ".\n";


            if (itemName == "money") {
                cout << "\nI have the money I needed! I should get going!\n";
                Sleep(1200);
                cout << "Congratulations you have finish this short game!\n";
                cout << "Press Enter to exit...\n";
                cin.ignore();
                cin.get();  // Wait for Enter
                exit(0);
            }
            return;
        }

    }
    cout << "There is no " << itemName << " here.\n";
}

void Player::dropItem(string itemName) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getName() == itemName) {
            currentRoom->addItem(*it);
            inventory.erase(it);
            cout << "You drop the " << itemName << ".\n";
            return;
        }
    }
    cout << "You don't have " << itemName << ".\n";
}
void Player::checkItem(string itemName) {
    
    for (Item* item:inventory) {
        if (item->getName() == itemName) {
            if (itemName == "key") {
                cout << "\n\n - KEY -\nGolden key with two letters engraved, SR.\nYou can use it to open a door." << endl;
            }
            else if (itemName =="bottle of water") {
                cout << "\n\n - BOTTLE OF WATER -\nUnopened bottle of 500ml." << endl;
            }
            else if (itemName == "book") {
                cout << "\n - BOOK -\nWELKOME TO MY TEXT ADVENTURE GAME\n\nThis game haves a total of 5 room and 6 items. You can move around and take/drop/check items.\nIt's a very short game so I hope you enjoy it\nThis game was created by Meritxell Algueró Manrique" << endl;
                cout<< "\nMIT License\nCopyright(c)[2025][Meritxell Algueró Manrique]"
                    "Permission is hereby granted, free of charge, to any person obtaining a copy of this softwareand associated documentation files(the 'Software'), to deal "
                    "in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and /or sell "
                    "copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions :\n"
                    "The above copyright noticeand this permission notice shall be included in all copies or substantial portions of the Software.\n"
                    "THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, "
                    "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
                    "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE." << endl;
            }
            else if (itemName == "bandages") {
                cout << "\n - BANDAGED -\nOld but in great condition. Usually used to bandage wounds." << endl;
            }
            else if (itemName == "sandwich") {
                cout << "\n - SANDWICH -\nGreat grilled ham and cheese sandwich with butter made by your father." << endl;
            }
            else if (itemName == "money") {
                cout << "\n - MONEY -\nPlain old money with the face of someone important." << endl;
            }
            else{ cout << "\nYou don't have that item." << endl; }
            cout << "\n";
            break;
        }
        
    }
}
void Player::showInventory() const {
    if (inventory.empty()) {
        cout << "Your bag is empty.\n";
        return;
    }
    cout << "You are carrying:\n";
    for (Item* item : inventory) {
        cout << "- " << item->getName();
        if (item == bag) {
            cout << " (bag)";
        }
        cout << "\n";
    }
    cout << "\n";
    showBag();
}

bool Player::hasItem(string itemName) const {
    for (Item* item : inventory) {
        if (item->getName() == itemName) return true;
    }
    return false;
}


Player::~Player() {
    for (Item* item : inventory) {
        delete item;
    }
}

void Player::putInBag(const std::string& itemName) {
    if (itemName == "bag")
    {
        cout << "You can NOT put the bag inside itself!" << endl;
        return;
    }
    else {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if ((*it)->getName() == itemName)
            {
                bag->AddItem(*it);
                inventory.erase(it);
                return;
            }
        }
        cout << "You don't have " << itemName << " in your Inventory anymore.\n";
    }
}
void Player::removeFromBag(const std::string& itemName) {
    Item* item = bag->removeItem(itemName);
    if (item != nullptr) {
        inventory.push_back(item);
        cout << itemName << " has been taken out of the bag." << endl;
    }
    else {
        cout << "That item is not in your bag" << endl;
    }
}
void Player::showBag() const {
    bag->showContents();
}

void Player::showDictionary() const {
    cout << "\n\n - COMMAND DICTIONARY - \n\n";
    cout << "-------------------------------------\n";
    cout << "> go / walk / move [direction] - Move in a direction (north, south, east, west)\n";
    cout << "> take/get/grab [item] - Take an item in the room\n";
    cout << "> drop [item] - Drop an item from your inventory\n";
    cout << "> check/examine/inspect [item] - Check the item of your selection once in your inventory\n";
    cout << "> inventory - Show items in your inventory and your bag\n";
    cout << "> put [item] in bag - Put an item into your bag\n";
    cout << "> take [item] from bag - Take an item out of your bag\n";
    cout << "> open bag / check bag - Show what's in the bag\n";
    cout << "> dictionary / help  - Show this help message\n";
    cout << "> quit / exit  - Leave the game\n";
    cout << "-------------------------------------\n\n";
}
