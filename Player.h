#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <cctype>
#include <vector>
using namespace std;

using namespace std;

class Player
{
private:
	//Player Stats
	double baseHp;
	double currentHp;
	double baseSp;
	double currentSp;
	double currency;
	double damage;
	bool isAlive;

	//Inventory
	int max_invSize;
	int curr_invSize;
	int classID;

	//Personality
	string summary;
	string className;
	string playerName;


	

public:
	//Inventory list
	vector<Item> inventoryList;

	//Prototype functions
	void setBaseHealth(double setHp);
	double getBaseHealth() { return baseHp; } 

	void setBaseSpecial(double setSp);
	double getBaseSpecial() { return baseSp; }

	void setCurrentHealth(double);
	double getCurrentHp() { return currentHp; }
	
	void setCurrentSpecial(double);
	double getCurrentSpecial() { return currentSp; }

	void setCurrency(double curr);
	double getCurrency() { return currency; }

	void setSummary(string sum);
	string getSummary() { return summary; }

	void setClassName(string name);
	string getClassName() { return className; }

	void setPlayerName(string name);
	string getPlayerName() { return playerName; }

	void setMaxInventorySize(int num);
	int getMaxInventorySpace() { return max_invSize; }

	void setCurrInventorySize(int num);
	int getCurrInventorySize() { return inventoryList.size(); }

	void setInventory(vector<Item> invList);
	vector<Item> getInventoryList() { return inventoryList; }
	Item getInventoryItem(int p) { return inventoryList[p]; }

	void setDamage(double num);
	double getDamage() { return damage; }

	void setClassID(int id);
	int getClassID() { return classID; }

	void setIsAlive(bool);
	bool getIsAlive() { return isAlive; }

	void addHealth(double);
	void subHealth(double);

	Item getWeapon() { return inventoryList[0]; }

	void Attack(Enemy& e);

	void DisplayItemInventory();

};

void Player::setBaseHealth(double setHp)
{
	Player::baseHp = setHp;
}

void Player::setBaseSpecial(double setSp)
{
	Player::baseSp = setSp;
}

void Player::setCurrency(double curr)
{
	Player::currency = curr;
}

void Player::setInventory(vector<Item> invList)
{
	this->inventoryList = invList;
}

void Player::setSummary(string sum)
{
	Player::summary = sum;
}

void Player::setClassName(string name)
{
	Player::className = name;
}

void Player::setPlayerName(string name)
{
	Player::playerName = name;
}

void Player::setMaxInventorySize(int num)
{
	Player::max_invSize = num;
}

void Player::setCurrInventorySize(int num)
{
	Player::curr_invSize = num;
}

void Player::setCurrentHealth(double n)
{
	Player::currentHp = n;
}

void Player::setCurrentSpecial(double p)
{
	Player::currentSp = p; 
}

void Player::setDamage(double num)
{
	Player::damage = num;
}

void Player::addHealth(double n)
{
	if ((n + currentHp) <= baseHp)
		Player::currentHp += n;
	else
		this->setCurrentHealth(baseHp);
}

void Player::subHealth(double n)
{
	if((currentHp - n) > 0)
		this->currentHp -= n;
}

void Player::setClassID(int id)
{
	Player::classID = id;
}

void Player::setIsAlive(bool flag)
{
	this->isAlive = flag;
}

void Player::Attack(Enemy& e)
{
	e.setCurrentHp(e.getCurrentHp() - (this->getDamage() + this->getWeapon().getNumericBoost()));
	this->setCurrentHealth(this->getCurrentHp() - (e.getDamage() + e.getCurrentItem().getNumericBoost()));
}

void Player::DisplayItemInventory()
{
	cout << "(" << this->getCurrInventorySize() << "/" << this->getMaxInventorySpace() << ") Items in inventory: " << endl;
	for (int i = 0; i < this->getCurrInventorySize(); i++)
	{
		cout << right << " - " << this->getInventoryItem(i).getItemName() << endl;
	}
}