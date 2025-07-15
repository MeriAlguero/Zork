#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include <vector>
#include "Item.h"

class Room {
private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item*> items;
    bool locked;

public:
    Room(std::string desc, bool isLocked = false);
    ~Room();

    void setExit(std::string direction, Room* neighbor);
    Room* getExit(std::string direction);
    void addItem(Item* item);
    void removeItem(Item* item);
    std::vector<Item*>& getItems();
    bool isLocked() const;
    void unlock();

    std::string getDescription() const;
};

#endif