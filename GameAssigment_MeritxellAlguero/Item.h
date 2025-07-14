#pragma once // Avoid double inclusion of this header
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string name;

public:
    Item(std::string name);
    virtual ~Item();

    virtual std::string getName() const;
    virtual std::string getDescription() const;
};

#endif
