#include "Player.h"
#include <Windows.h>
#include <iostream>

using namespace std;

Player::Player() : currentRoom(nullptr) {}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::move(const string& direction) {

    const vector<string> validDirections = { "north", "south", "east", "west" };//Cheking valid directions
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
    std::cout << "You have: ";
    for (Item* item : inventory) {
        cout << item->getName() << " ";
    }
    cout << "\n";
}

bool Player::hasItem(string itemName) const {
    for (Item* item : inventory) {
        if (item->getName() == itemName) return true;
    }
    return false;
}

void Player::startGame()
{
    cout << "\nEntering World.\n";
    Sleep(600);
    system("cls");
    cout << "Entering World..\n";
    Sleep(600);
    system("cls");
    cout << "Entering World...\n";
    Sleep(600);
    system("cls");
}
