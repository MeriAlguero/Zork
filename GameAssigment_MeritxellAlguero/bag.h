#pragma once
#include "Item.h"
#include <vector>
#include <string>

class Bag : public Item{
private:
	std::vector<Item*> contents;
public:
	Bag(const std::string& name = "bag");
	~Bag();

	void AddItem(Item* item);
	Item* removeItem(const std::string& itemsName);
	bool hasItem(const std::string& itemName) const;
	void showContents() const;

	std::vector<Item*>& getItem();
};
