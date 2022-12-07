#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "Items.h"
using namespace std;

class Player
{
private:
	double baseHp;
	double classBonus;
	double currentHp;
	double baseSp;
	double currentSp;
	double currency;
	double classCurrencyBonus;

	int inventorySpace;

	string summary;
	string className;
	string playerName;

	Item weapon;

public:
	Player()
	{
		this->baseHp = 0;
		this->classBonus = 0;
		this->currentHp = 0;
		this->baseSp = 0;
		this->currentSp = 0;
		this->currency = 0;
		this->classCurrencyBonus = 0;
		this->inventorySpace = 15;
	}


	void setBaseHealth(double setHp);
	double getBaseHealth() { return baseHp; } 

	void setBaseSpecial(double setSp);
	double getBaseSpecial() { return baseSp; }

	void setCurrentHealth(double);
	double getCurrentHealth() { return currentHp; }

	void addHealth(double);
	void subHealth(double);
	
	void setCurrentSpecial(double);

	void setCurrency(double curr);
	double getCurrency() { return currency; }

	void setItem(Item newItem);
	Item getItem() { return weapon; }

	void setSummary(string sum);
	string getSummary() { return summary; }

	void setClassName(string name);
	string getClassName() { return className; }

	void setPlayerName(string name);
	string getPlayerName() { return playerName; }

	void setInventorySpace(int num);
	int getInventorySpace() { return inventorySpace; }

	void DisplayStats();

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

void Player::setItem(Item newItem)
{
	Player::weapon = newItem;
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

void Player::setInventorySpace(int num)
{
	Player::inventorySpace = num;
}

void Player::setCurrentHealth(double n)
{
	Player::currentHp = n;
}

void Player::addHealth(double n)
{
	Player::currentHp += n;
}

void Player::subHealth(double n)
{
	Player::currentHp -= n;
}

