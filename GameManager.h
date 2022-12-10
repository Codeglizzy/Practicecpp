#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <vector>
#include "Items.h"
#include "Util.h"
#include "Player.h"
#include "ItemLibrary.h"
using namespace std;

class GameManager
{
private:
	Utility util;
	bool gameRunning;


public:
	void setGameFlag(bool);
	bool getGameState() { return gameRunning; }

	void StartGame();
	void GameLoop();

	void InitializePlayer(Player& p, ItemLibrary& lb);

	void DisplayCharacterSheet(Player& p);
};

void GameManager::StartGame()
{
	GameManager::GameLoop();
}

void GameManager::setGameFlag(bool flag)
{
	GameManager::gameRunning = flag;
}


void GameManager::InitializePlayer(Player& p, ItemLibrary& lb)
{
	do
	{
		//Pick class
		system("cls");
		cout << "hello, pick your class:\n1 - Warrior, 2 - Wizard, 3 - Rogue, or 4 - Priest\n\n" << " >>: ";
		util.PromptInt();
		while (util.getPrevIntInput() < 1 || util.getPrevIntInput() > 4)
		{
			cout << "Try again >>: ";
			util.PromptInt();
		}

		if (util.getPrevIntInput() == 1)
		{
			//Set Warrior stats
			p.setBaseHealth(25);
			p.setBaseSpecial(10);
			p.setClassName("Warrior");
			p.setDamage(3);
			p.setSummary("A battle-hardened master of the battlefield.");
			p.setCurrency(100);
			p.setClassID(1);
			p.setMaxInventorySize(5);

			//Set Warrior starting inventory
			p.inventoryList.push_back(lb.weapon_Warrior);
			p.inventoryList.push_back(lb.health_Potion);
			p.inventoryList.push_back(lb.special_Potion);

		}
		else if (util.getPrevIntInput() == 2)
		{
			//Set Wizard stats
			p.setBaseHealth(15);
			p.setBaseSpecial(30);
			p.setClassName("Wizard");
			p.setDamage(6);
			p.setSummary("Whimsical wizard skilled in the art of spellcasting.");
			p.setCurrency(90);
			p.setClassID(2);
			p.setMaxInventorySize(5);

			//Set Wizard starting inventory
			p.inventoryList.push_back(lb.weapon_Wizard);
			p.inventoryList.push_back(lb.health_Potion);
			p.inventoryList.push_back(lb.special_Potion);

		}
		else if (util.getPrevIntInput() == 3)
		{
			//Set Rogue stats
			p.setBaseHealth(10);
			p.setBaseSpecial(20);
			p.setClassName("Rogue");
			p.setDamage(7);
			p.setSummary("Stealthy rogue that can slip past most undetected, others face their deadly daggers.");
			p.setCurrency(105);
			p.setClassID(3);
			p.setMaxInventorySize(5);

			//Set Rogue starting inventory
			p.inventoryList.push_back(lb.weapon_Rogue);
			p.inventoryList.push_back(lb.health_Potion);
			p.inventoryList.push_back(lb.special_Potion);

		}
		else if (util.getPrevIntInput() == 4)
		{
			//Set Priest stats
			p.setBaseHealth(20);
			p.setBaseSpecial(25);
			p.setClassName("Priest");
			p.setDamage(5);
			p.setSummary("Devout scholar of religion. Derives healing properties from the deity 'Big Chungus'.");
			p.setCurrency(55);
			p.setClassID(4);

			//Set Priest starting inventory
			p.setMaxInventorySize(5);
			p.inventoryList.push_back(lb.weapon_Priest);
			p.inventoryList.push_back(lb.health_Potion);
			p.inventoryList.push_back(lb.special_Potion);

		}

		cout << "Have you decided a name for your " << p.getClassName() << "?\n >>: ";
		p.setPlayerName(util.PromptString());

		cout << endl << util.getPrevStringInput() << "? \nSounds great! Take one last looky-loo at your character";
		cout << " and make sure everything is square:\n" << endl;
		DisplayCharacterSheet(p);
		cout << endl << "Look good? (y/Y or n/N) >>: ";
		util.PromptChar();
		if (util.getCharInput() == 'n' || util.getCharInput() == 'N')
			p.inventoryList.clear();
	}
	while (util.getCharInput() == 'n' || util.getCharInput() == 'N');
}


//Where the action starts
void GameManager::GameLoop()
{
	//Start
	cout << "Welcome.\n\nPress any key...";
	setGameFlag(true);
	//PlaySound(TEXT("song.wav"), NULL, SND_ASYNC);
	_getch();
	system("cls");

	//Init player object
	Player main_Character;
	ItemLibrary item_Database;

	//Build Player
	InitializePlayer(main_Character, item_Database);

	//Display information 
	//DisplayCharacterSheet(main_Character);

	//end
	cout << endl << "See you next time! Combat coming soon!" << endl;
	setGameFlag(false);
	return;
}


void GameManager::DisplayCharacterSheet(Player& p)
{
	cout << showpoint << setprecision(4);
	cout << "Here is a print-out of your character sheet!" << endl;
	cout << "\n********************************************************************************" << endl;
	cout << "Name: " << p.getPlayerName() << endl;
	cout << "Class: " << p.getClassName() << endl;
	cout << "Health: " << p.getBaseHealth() << endl;
	cout << "Special: " << p.getBaseSpecial() << endl;
	cout << "Currency: " << p.getCurrency() << endl;
	cout << "Damage Output: " << p.getDamage() << endl;
	cout << "ID: " << p.getClassID() << endl;
	cout << "\nStarting Items: \n";
	for (int i = 0; i < p.inventoryList.size(); i++)
	{
		cout << " - " << p.inventoryList[i].getItemName() << endl;
	}
	cout << "\nSummary: " << p.getSummary() << endl;
	cout << "\n********************************************************************************" << endl;
}
