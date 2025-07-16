#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Item.h"
#include "bag.h"
#include "Room.h"

class Player {
private:
    
    Room* currentRoom = nullptr;
    Bag* bag;
    std::vector<Item*> inventory;
    
public:
    Player();
    ~Player();
    void setCurrentRoom(Room* room);
    Room* getCurrentRoom() const;

    void move(const std::string& direction);
    void takeItem(std::string itemName);
    void dropItem(std::string itemName);
    void checkItem(std::string itemName);
    void startGame();
    void showInventory() const;
    bool hasItem(std::string itemName) const;

    void putInBag(const std::string& itemName);
    void removeFromBag(const std::string& itemName);
    void showBag() const;

    void showDictionary() const;
};


#endif