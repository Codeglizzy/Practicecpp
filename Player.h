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

	Player(double hp, double sp, double wealth, string txt)
	{
		this->baseHp = hp;
		this->classBonus = 0;
		this->currentHp = hp;
		this->baseSp = sp;
		this->currentSp = sp;
		this->currency = wealth;
		this->classCurrencyBonus = 0;
		this->inventorySpace = 15;

		this->summary = txt;
	}

	void setHealth(double setHp);
	double getHealth() { return currentHp; }

	void setSpecial(double setSp);
	double getSpecial() { return currentSp; }

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

void Player::setHealth(double setHp)
{
	Player::baseHp = setHp;
}

void Player::setSpecial(double setSp)
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

void Player::DisplayStats()
{
	cout << this->baseHp << endl;
	cout << this->baseSp << endl;
}

