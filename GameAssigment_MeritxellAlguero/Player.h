#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Item.h"
#include "Room.h"

class Player {
private:
    
    Room* currentRoom = nullptr;
    std::vector<Item*> inventory;

public:
    Player();
    void setCurrentRoom(Room* room);
    Room* getCurrentRoom() const;

    void move(const std::string& direction);
    void takeItem(std::string itemName);
    void dropItem(std::string itemName);
    void startGame();
    void showInventory() const;
    bool hasItem(std::string itemName) const;
};

#endif