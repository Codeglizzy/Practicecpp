#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <cctype>
#include <vector>
#include "Items.h"
using namespace std;

class ItemLibrary
{
public:
	vector<Item> item_Database;

	//Declare items
	Item weapon_Warrior; 
	Item health_Potion; 
	Item special_Potion; 
	Item weapon_Wizard; 
	Item weapon_Rogue; 
	Item weapon_Priest; 

	ItemLibrary()
	{
		//Define items
		weapon_Warrior.Initialize("Mighty Blade", false, 150, 7, 115);
		health_Potion.Initialize("Health Elixir", true, 15, 5, 1);
		special_Potion.Initialize("Special Elixir", true, 20, 5, 2);
		weapon_Wizard.Initialize("Staff of Rage", false, 100, 4, 3);
		weapon_Rogue.Initialize("Deadly Daggers", false, 100, 3, 4);
		weapon_Priest.Initialize("Talisman of Light", false, 90, 5, 5);

		//Add items
		this->item_Database.push_back(weapon_Warrior);
		this->item_Database.push_back(weapon_Rogue);
		this->item_Database.push_back(weapon_Wizard);
		this->item_Database.push_back(weapon_Priest);
		this->item_Database.push_back(health_Potion);
		this->item_Database.push_back(special_Potion);
	}
};