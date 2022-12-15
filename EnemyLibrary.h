#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <cctype>
#include <vector>
#include "Enemy.h"
using namespace std;

class EnemyLibrary
{
private:
	ItemLibrary itemLib;
public:
	vector<Enemy> enemies;

	Enemy goblin;
	Enemy ogre;
	Enemy myDad;

	EnemyLibrary()
	{
		goblin.Initialize("Goblin", "Scout", 15, 2, this->itemLib.weapon_Warrior);
		ogre.Initialize("Ogre of the Swamp", "Brute", 3, 7, this->itemLib.weapon_Warrior);
		myDad.Initialize("My Dad", "Beater of Women & Children", 25, 1, this->itemLib.weapon_Priest);

		enemies.push_back(goblin);
		enemies.push_back(ogre);
		enemies.push_back(myDad);
	}

	void CreateEnemy(string name, string cName, double hp, double dam, Item& weapon)
	{
		Enemy enem(name, cName, hp, dam, weapon);
		this->enemies.push_back(enem);
	}
};