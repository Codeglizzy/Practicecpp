#pragma once
#include "GameManager.h"

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
	double getCurrentHealth() { return currentHp; }
	
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
	int getCurrInventorySize() { return curr_invSize; }

	void setDamage(double num);
	double getDamage() { return damage; }

	void setClassID(int id);
	int getClassID() { return classID; }

	void addHealth(double);
	void subHealth(double);

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

