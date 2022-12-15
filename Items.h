#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <cctype>
#include <vector>
using namespace std;

class Item
{
private:
	bool consumable;
	
	double itemValue;
	double numericBoost;

	int quantity;

	string itemTag;

	string itemName;
public:
	Item()
	{
		consumable = false;
		numericBoost = 0;
		itemValue = 0;
		itemTag = "Null Item";
		itemName = "EMPTY_OBJECT";
		quantity = 0;
	}

	Item(string n, bool con, double val, double numBoost, string tag )
	{
		this->itemName = n;
		this->consumable = con;
		this->itemValue = val;
		this->numericBoost = numBoost;
		this->itemTag = tag;
		this->quantity = 1;
	}

	void setConsumable(bool flag);
	bool getConsumable() { return consumable; }


	void setItemValue(double val);
	double getItemValue() { return itemValue; }

	void Initialize(string, bool, double, double, string);

	void setItemTag(string tag);
	string getItemTag() { return itemTag; }

	void setItemName(string name);
	string getItemName() { return itemName; }

	void setNumericBoost(double v);
	double getNumericBoost() { return numericBoost; }

	void setQuantity(int);
	int getQuantity() { return quantity; }

};

void Item::setQuantity(int p)
{
	this->quantity = p;
}

void Item::Initialize(string name, bool consume,double price, double numBoost, string tag)
{
	this->itemName = name;
	this->consumable = consume;
	this->itemValue = price;
	this->numericBoost = numBoost;
	this->itemTag = tag;
	this->quantity = 1;
}

void Item::setConsumable(bool flag)
{
	Item::consumable = flag;
}

void Item::setNumericBoost(double v)
{
	Item::numericBoost = v;
}

void Item::setItemTag(string tag)
{
	Item::itemTag = tag;
}

void Item::setItemName(string name)
{
	Item::itemName = name;
}

void Item::setItemValue(double val)
{
	this->itemValue = val;
}