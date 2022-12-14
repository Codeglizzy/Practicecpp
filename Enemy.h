#pragma once
#include "GameManager.h"

class Enemy
{
private:
	string enemyName;
	string className;
	double baseHp;
	double currentHp;
	double damage;

	ItemLibrary inv;
	Item weapon;
public:
	//Default enemy
	Enemy()
	{
		this->enemyName = "Nameless Footsoldier";
		this->baseHp = 15;
		this->currentHp = baseHp;
		this->damage = 2;
		this->weapon = inv.weapon_Warrior;
		this->className = "Warrior";
	}

	//Custom enemy
	Enemy(string name, string cName, double hp, double dam, Item& weaponOfChoice)
	{
		this->enemyName = name;
		this->className = cName;
		this->baseHp = hp;
		this->currentHp = baseHp;
		this->damage = dam;
		this->weapon = weaponOfChoice;
	}

	void setEnemyName(string);
	string getEnemyName() { return enemyName; }

	void setBaseHp(double);
	double getBaseHp() { return baseHp; }

	void setCurrentHp(double);
	double getCurrentHp() { return currentHp; }

	void setCurrentItem(Item&);
	Item getCurrentItem() { return weapon; }

	void setDamage(double);
	double getDamage() { return damage; }

	void setClassName(string);
	string getClassName() { return className; }

};

void Enemy::setEnemyName(string n)
{
	this->enemyName = n;
}

void Enemy::setBaseHp(double base)
{
	this->baseHp = base;
}

void Enemy::setCurrentHp(double d)
{
	this->currentHp = d;
}

void Enemy::setCurrentItem(Item& item)
{
	this->weapon = item;
}

void Enemy::setClassName(string n)
{
	this->className = n;
}

void Enemy::setDamage(double dam)
{
	this->damage = dam;
}