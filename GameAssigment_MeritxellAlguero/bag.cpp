#include "bag.h"
#include <iostream>
using namespace std;

Bag::Bag(const string& name) : Item(name) {}

Bag::~Bag() {
	for (Item* item : contents) {
		delete item;
	}
	contents.clear();
}
void Bag::AddItem(Item* item) {
	contents.push_back(item);
	cout << item->getName() << " has been added to the bag." << endl;

}
Item* Bag::removeItem(const string& itemsName) {
	for (auto it = contents.begin(); it != contents.end(); it++) {
		if ((*it)->getName() == itemsName) {
			Item* item = *it;
			contents.erase(it);
			return item;
		}
	}
	return nullptr;

}
bool Bag::hasItem(const string& itemName) const {
	for (Item* item : contents) {
		if (item->getName() == itemName) { return true; }
	}
	return false;
}
void Bag::showContents() const {
	if (contents.empty()) {
		cout << "You do not have anything in the bag." << endl;
	}
	else {
		cout << "You have in your bag:" << endl;
		for (Item* item : contents) {
			cout << "- " << item->getName() << endl;
		}
	}
}

vector<Item*>& Bag::getItem() {
	return contents;
}