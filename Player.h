#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <cctype>
#include <vector>
#include "Util.h"
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

	void addItemToInventory(Item&, int);

	void setCurrInventorySize(int num);
	int getCurrInventorySize() { 
		int size = 0;
		for (int i = 0; i < this->inventoryList.size(); i++)
		{
			size += this->inventoryList[i].getQuantity();
		}
		return size; 
	
	}

	void setInventory(vector<Item> invList);
	vector<Item> getInventoryList() { return inventoryList; }
	Item getInventoryItem(int p) { return inventoryList[p]; }

	void setDamage(double num);
	double getDamage() { return damage; }

	void setIsAlive(bool);
	bool getIsAlive() { return isAlive; }

	void addHealth(double);
	void addSpecial(double);
	void subHealth(double);
	void subSpecial(double);

	Item getWeapon() { return inventoryList[0]; }

	void Attack(Enemy& e);

	void DisplayItemInventory();

	void UseItem(Item&);
	void RemoveItem(int i);
};

void Player::addSpecial(double n)
{
	if ((n + this->currentSp) <= this->baseSp)
		Player::currentSp += n;
	else
		this->setCurrentSpecial(this->baseSp);
}

void Player::subSpecial(double n)
{
	this->currentSp -= n;
}

void Player::UseItem(Item& i)
{
	if (i.getItemTag() == "weapon")
	{
		cout << "This item is already equipped..." << endl;
		return;
	}
	if(i.getItemTag() == "h_elixir"){
		addHealth(i.getNumericBoost());
		i.setQuantity(i.getQuantity() - 1);
		if(i.getQuantity() == 0)
			RemoveItem(Utility::getPrevIntInput());
		cout << endl << "Current HP: " << getCurrentHp() << endl;
	}else if (i.getItemTag() == "s_elixir") {
		addSpecial(i.getNumericBoost());
		i.setQuantity(i.getQuantity() - 1);
		if(i.getQuantity() == 0)
			RemoveItem(Utility::getPrevIntInput());
		cout << endl << "Current SP: " << getCurrentSpecial() << endl;
	}
}

void Player::addItemToInventory(Item& itemToAdd, int quantity)
{
	itemToAdd.setQuantity(quantity);
	this->inventoryList.push_back(itemToAdd);
}

void Player::RemoveItem(int i)
{
	this->inventoryList.erase(this->inventoryList.begin()+i-1);
}

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
	if ((n + this->currentHp) <= this->baseHp)
		Player::currentHp += n;
	else
		this->setCurrentHealth(this->baseHp);
}

void Player::subHealth(double n)
{
	this->currentHp -= n;
}

void Player::setIsAlive(bool flag)
{
	this->isAlive = flag;
}

void Player::Attack(Enemy& e)
{
	e.subHealth(this->getDamage() + this->getWeapon().getNumericBoost());
	this->subHealth(e.getDamage() + e.getCurrentItem().getNumericBoost());
}

void Player::DisplayItemInventory()
{
	while (Utility::getPrevIntInput() != 99)
	{
		cout << endl << "(" << this->getCurrInventorySize() << "/" << this->getMaxInventorySpace() << ") Items in inventory: " << endl;
		for (int i = 0; i < this->inventoryList.size(); i++)
		{
			if (this->getInventoryItem(i).getQuantity() <= 1)
				cout << setw(25) << right << (i + 1) << " - " << this->getInventoryItem(i).getItemName() << endl;
			else
				cout << setw(25) << right << (i + 1) << " - " << this->getInventoryItem(i).getItemName() << " x" << this->getInventoryItem(i).getQuantity() << endl;
		}

		cout << endl << "What item would you like to use (99 to close inventory): ";
		Utility::PromptInt();
		
		if ((Utility::getPrevIntInput() - 1) >= inventoryList.size() && Utility::getPrevIntInput() != 99)
		{
			cout << endl << endl << "Press any key to try again..." << endl;
			_getch();
		}
		else if ((Utility::getPrevIntInput() - 1) < inventoryList.size())
		{
			UseItem(this->inventoryList[Utility::getPrevIntInput() - 1]);
		}
			
	} 

}