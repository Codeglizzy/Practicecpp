#pragma once
#include "GameManager.h"
using namespace std;

class Item
{
private:
	bool consumable;

	double itemValue;

	int itemQuantity;
	int itemSpace;
	int itemID;

	string itemName;
public:
	Item()
	{
		consumable = false;
		itemValue = 0;
		itemQuantity = 1;
		itemSpace = 1;
		itemID = 00;
		itemName = "EMPTY_OBJECT";
	}

	Item(string n)
	{
		this->itemName = n;
	}

	void setConsumable(bool flag);
	bool getConsumable() { return consumable; }

	void setItemQuantity(int num);
	int getQuantity() { return itemQuantity; }

	void setItemValue(double val);
	double getItemValue() { return itemValue; }

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

void Item::setItemValue(double val)
{
	this->itemValue = val;
}