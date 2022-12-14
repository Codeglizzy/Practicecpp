#pragma once
#include "GameManager.h"
using namespace std;

class Item
{
private:
	bool consumable;
	
	double itemValue;
	double numericBoost;

	int itemID;

	string itemName;
public:
	Item()
	{
		consumable = false;
		numericBoost = 0;
		itemValue = 0;
		itemID = 00;
		itemName = "EMPTY_OBJECT";
	}

	Item(string n, bool con, double val, double numBoost, int id )
	{
		this->itemName = n;
		this->consumable = con;
		this->itemValue = val;
		this->numericBoost = numBoost;
		this->itemID = id;
	}

	void setConsumable(bool flag);
	bool getConsumable() { return consumable; }


	void setItemValue(double val);
	double getItemValue() { return itemValue; }

	void initItem(string, bool, double, double, int);

	void setItemID(int id);
	int getItemID() { return itemID; }

	void setItemName(string name);
	string getItemName() { return itemName; }

	void setNumericBoost(double v);
	double getNumericBoost() { return numericBoost; }
};

void Item::initItem(string n, bool c,double p, double v, int h)
{
	this->itemName = n;
	this->consumable = c;
	this->itemValue = p;
	this->numericBoost = v;
	this->itemID = h;
}

void Item::setConsumable(bool flag)
{
	Item::consumable = flag;
}

void Item::setNumericBoost(double v)
{
	Item::numericBoost = v;
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