#include "Item.h"
#include <iostream>

Item::Item(std::string name) : name(name) {}

Item::~Item() {}

std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return "It's a " + name + ".";
}