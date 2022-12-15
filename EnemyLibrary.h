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
	Enemy orc;

	EnemyLibrary()
	{
		goblin.Initialize("Goblin", "Scout", 15, 2, this->itemLib.weapon_Rogue);
		ogre.Initialize("Ogre of the Swamp", "Brute", 3, 7, this->itemLib.weapon_Warrior);
		orc.Initialize("Orc King", "King Eater", 25, 1, this->itemLib.weapon_Priest);

		enemies.push_back(goblin);
		enemies.push_back(ogre);
		enemies.push_back(orc);
	}

	void CreateEnemy(string name, string cName, double hp, double dam, Item& weapon)
	{
		Enemy enem(name, cName, hp, dam, weapon);
		this->enemies.push_back(enem);
	}
};