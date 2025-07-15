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
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::move(const string& direction) {

    const vector<string> validDirections = { "north", "south", "east", "west", "North", "South", "West", "East"};//Cheking valid directions
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
                system("cls");
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

void Player::showInventory() const {
    if (inventory.empty()) {
        cout << "Your bag is empty.\n";
        return;
    }
    cout << "You are carrying:\n";
    for (Item* item : inventory) {
        cout <<"- " << item->getName();
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

