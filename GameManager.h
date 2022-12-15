#pragma once
#include "Util.h"
#include "ItemLibrary.h"
#include "Enemy.h"
#include "EnemyLibrary.h"
#include "Player.h"
using namespace std;

class GameManager
{
private:
	bool gameRunning;


public:
	void setGameFlag(bool);
	bool getGameState() { return gameRunning; }

	void StartGame();
	void GameLoop();

	void InitializePlayer(Player&);
	void DisplayCharacterSheet(Player&);
	void DisplayCombatMenu(Player&);
	void CheckDeath(Player&, Enemy&);
	void DisplayCombatStats(Player&, Enemy&);
};
void GameManager::CheckDeath(Player& p, Enemy& e)
{
	p.setIsAlive((p.getCurrentHp() <= 0) ? false : true);
	e.setIsAlive((e.getCurrentHp() <= 0) ? false : true);

	if (!p.getIsAlive())
	{
		cout << "\nGame Over!" << endl;
		return;
	}
	else
	{
		cout << "You: " << p.getPlayerName() << endl;
		cout << "Your HP: " << p.getCurrentHp() << endl;
		cout << "Your Weapon: " << p.getWeapon().getItemName() << endl;
		cout << "Enemy: " << e.getEnemyName() << endl;
		cout << "Enemy HP: " << e.getCurrentHp() << endl;
		cout << "Enemy Weapon: " << e.getCurrentItem().getItemName() << endl;
	}

	if (!e.getIsAlive())
	{
		cout << endl << e.getEnemyName() << " has been slain." << endl;
	}
}

void GameManager::StartGame()
{
	GameManager::GameLoop();
}

void GameManager::setGameFlag(bool flag)
{
	GameManager::gameRunning = flag;
}


void GameManager::InitializePlayer(Player& p)
{
	do
	{
		//Pick class
		system("cls");
		cout << "hello, pick your class:\n1 - Warrior, 2 - Wizard, 3 - Rogue, or 4 - Priest\n\n" << " >>: ";
		Utility::PromptInt();
		p.inventoryList.clear();
		while (Utility::getPrevIntInput() < 1 || Utility::getPrevIntInput() > 4)
		{
			cout << "Try again >>: ";
			Utility::PromptInt();
		}

		if (Utility::getPrevIntInput() == 1)
		{
			ItemLibrary lb;

			//Set Warrior stats
			p.setBaseHealth(45);
			p.setCurrentHealth(p.getBaseHealth());
			p.setBaseSpecial(10);
			p.setCurrentSpecial(p.getBaseSpecial());
			p.setClassName("Warrior");
			p.setDamage(2);
			p.setSummary("A battle-hardened master of the battlefield.");
			p.setCurrency(100);
			p.setMaxInventorySize(10);
			p.setIsAlive(true);

			//Set Warrior starting inventory
			p.addItemToInventory(lb.weapon_Warrior, 1);
			p.addItemToInventory(lb.health_Potion, 2);
			p.addItemToInventory(lb.special_Potion, 2);

		}
		else if (Utility::getPrevIntInput() == 2)
		{
			ItemLibrary lb;

			//Set Wizard stats
			p.setBaseHealth(35);
			p.setCurrentHealth(p.getBaseHealth());
			p.setBaseSpecial(30);
			p.setCurrentSpecial(p.getBaseSpecial());
			p.setClassName("Wizard");
			p.setDamage(5);
			p.setSummary("Whimsical wizard skilled in the art of spellcasting.");
			p.setCurrency(90);
			p.setMaxInventorySize(10);
			p.setIsAlive(true);

			//Set Wizard starting inventory
			p.addItemToInventory(lb.weapon_Wizard, 1);
			p.addItemToInventory(lb.health_Potion, 2);
			p.addItemToInventory(lb.special_Potion, 2);

		}
		else if (Utility::getPrevIntInput() == 3)
		{
			ItemLibrary lb;

			//Set Rogue stats
			p.setBaseHealth(30);
			p.setCurrentHealth(p.getBaseHealth());
			p.setBaseSpecial(20);
			p.setCurrentSpecial(p.getBaseSpecial());
			p.setClassName("Rogue");
			p.setDamage(6);
			p.setSummary("Stealthy rogue that can slip past most undetected, others face their deadly daggers.");
			p.setCurrency(105);
			p.setMaxInventorySize(10);
			p.setIsAlive(true);

			//Set Rogue starting inventory
			p.addItemToInventory(lb.weapon_Rogue, 1);
			p.addItemToInventory(lb.health_Potion, 2);
			p.addItemToInventory(lb.special_Potion, 2);

		}
		else if (Utility::getPrevIntInput() == 4)
		{
			ItemLibrary lb;

			//Set Priest stats
			p.setBaseHealth(40);
			p.setCurrentHealth(p.getBaseHealth());
			p.setBaseSpecial(25);
			p.setCurrentSpecial(p.getBaseSpecial());
			p.setClassName("Priest");
			p.setDamage(5);
			p.setSummary("Devout scholar of religion. Derives healing properties from the deity 'Big Chungus'.");
			p.setCurrency(55);
			p.setMaxInventorySize(10);
			p.setIsAlive(true);

			//Set Priest starting inventory
			p.addItemToInventory(lb.weapon_Priest, 1);
			p.addItemToInventory(lb.health_Potion, 2);
			p.addItemToInventory(lb.special_Potion, 2);

		}

		cout << "Have you decided a name for your " << p.getClassName() << "?\n >>: ";
		p.setPlayerName(Utility::PromptString());

		cout << endl << Utility::getPrevStringInput() << "? \nSounds great! Take one last looky-loo at your character";
		cout << " and make sure everything is square:\n" << endl;
		DisplayCharacterSheet(p);
		cout << endl << "Look good? (y/Y or n/N) >>: ";
		Utility::PromptChar();
		cout << endl;
	}
	while (tolower(Utility::getPrevCharInput()) != 'y');
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

	//Declare necessary libraries
	ItemLibrary item_Library;
	EnemyLibrary enemy_Library;

	//Init player object
	Player main_Character;

	//Build Player
	InitializePlayer(main_Character);

	//Loop Begin
	int index = 0;
	cout << "Enemy #" << (index + 1) << ": " << enemy_Library.enemies[index].getEnemyName() << endl;
	DisplayCombatStats(main_Character, enemy_Library.enemies[index]);
	while (getGameState() && (index < enemy_Library.enemies.size()))
	{
		while (enemy_Library.enemies[index].getIsAlive())
		{
			DisplayCombatMenu(main_Character);
			if (Utility::getPrevIntInput() == 1)
			{
				main_Character.Attack(enemy_Library.enemies[index]);
				CheckDeath(main_Character, enemy_Library.enemies[index]);
				
			}
			else if (Utility::getPrevIntInput() == 2)
			{
				main_Character.DisplayItemInventory();
				DisplayCombatStats(main_Character, enemy_Library.enemies[index]);
			}
			else if (Utility::getPrevIntInput() == 3)
			{
				cout << "\nSee you next time!" << endl;
				return;
			}
			else {
				cout << endl << "Incorrect selection...Try again." << endl << endl;
			}
		}

		//Continue the fight?
		if (main_Character.getIsAlive())
		{
			cout << "\nContinue? y/n >>: "; Utility::PromptChar();
			if (tolower(Utility::getPrevCharInput()) == 'n')
			{
				setGameFlag(false);
			}
			else if(tolower(Utility::getPrevCharInput()) == 'y'){
				cout << endl;
				index++;
				cout << "Enemy #" << (index + 1) << ": " << enemy_Library.enemies[index].getEnemyName() << endl;
				DisplayCombatStats(main_Character, enemy_Library.enemies[index]);
			}
			else {
				cout << endl << "Incorrect selection...Try again." << endl << endl;
			}
		}
		else {
			cout << "Try again next time!" << endl;
			return;
		}
	}

	//end
	cout << endl << "That's all for now! See you again!" << endl;
	setGameFlag(getGameState() ? false : true);
	return;
}

void GameManager::DisplayCombatStats(Player& p, Enemy& e)
{
	cout << "You: " << p.getPlayerName() << endl;
	cout << "Your HP: " << p.getCurrentHp() << endl;
	cout << "Your Weapon: " << p.getWeapon().getItemName() << endl;
	cout << "Enemy: " << e.getEnemyName() << endl;
	cout << "Enemy HP: " << e.getCurrentHp() << endl;
	cout << "Enemy Weapon: " << e.getCurrentItem().getItemName();
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
	cout << "Damage Output: " << (p.getDamage() + p.inventoryList[0].getNumericBoost()) << endl;
	cout << "\nStarting Items: \n";
	for (int i = 0; i < p.inventoryList.size(); i++)
	{
		if (p.getInventoryItem(i).getQuantity() <= 1)
			cout << setw(25) << right << (i + 1) << " - " << p.getInventoryItem(i).getItemName() << endl;
		else
			cout << setw(25) << right << (i + 1) << " - " << p.getInventoryItem(i).getItemName() << " x" << p.getInventoryItem(i).getQuantity() << endl;
	}
	cout << "\nSummary: " << p.getSummary() << endl;
	cout << "\n********************************************************************************" << endl;
}

void GameManager::DisplayCombatMenu(Player& p)
{
	cout << endl << endl << p.getPlayerName() << ", what would you like to do?\nPress 1 to attack; 2 to access a list of items; 3 to exit.\n"
		<< "\n >>: ";
	Utility::PromptInt();
}