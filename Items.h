#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

class Item
{
private:
	bool consumable;

	int itemQuantity;
	int itemValue;
	int itemSpace;
	int itemID;

	string itemName;
public:
	void setConsumable(bool flag);
	bool getConsumable() { return consumable; }

	void setItemQuantity(int num);
	int getQuantity() { return itemQuantity; }

	void setInventorySpace(int num);
	int getInventoryRealEstate() { return itemSpace; }

	void setItemID(int id);
	int getItemID() { return itemID; }

	void setItemName(string name);
	string getItemName() { return itemName; }
};

void Item::setConsumable(bool flag)
{
	Item::consumable = flag;
}

void Item::setItemQuantity(int num)
{
	Item::itemQuantity = num;
}

void Item::setInventorySpace(int num)
{
	Item::itemSpace = num;
}

void Item::setItemID(int id)
{
	Item::itemID = id;
}

void Item::setItemName(string name)
{
	Item::itemName = name;
}