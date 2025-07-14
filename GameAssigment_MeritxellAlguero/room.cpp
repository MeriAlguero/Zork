#include "Room.h"
#include <iostream>
using namespace std;

Room::Room(string desc, bool isLocked) : description(desc), locked(isLocked) {}

Room::~Room() {
    for (Item* item : items) delete item;
}

void Room::setExit(string direction, Room* neighbor) {
    exits[direction] = neighbor;
}

Room* Room::getExit(string direction) {
    return exits.count(direction) ? exits[direction] : nullptr;
}

void Room::addItem(Item* item) {
    items.push_back(item);
}

void Room::removeItem(Item* item) {
    items.erase(remove(items.begin(), items.end(), item), items.end());
}

vector<Item*>& Room::getItems() {
    return items;
}

bool Room::isLocked() const {
    return locked;
}

void Room::unlock() {
    locked = false;
}

string Room::getDescription() const {
    return description;
}


