#pragma once
#include "Player.h"
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
	void InitItem(Item& item);
	void InitItem(Item& item, string itemName, double itemVal, bool isConsumable, int invSpace, int quantity, int ID);
	void InitPlayer(Player& main_Character);
	void DisplayCharacterSheet(Player& main_Character);

};

void GameManager::StartGame()
{
	GameManager::GameLoop();
}

void GameManager::setGameFlag(bool flag)
{
	GameManager::gameRunning = flag;
}


void GameManager::GameLoop()
{
	//intro
	Player main_Character("Randal");

	//Start
	cout << "Welcome.\n\n";
	PlaySound(TEXT("song.wav"), NULL, SND_ASYNC);
	_getch();
	system("cls");

	cout << "Turn-based combat simulator!" << endl;

	//init player
	InitPlayer(main_Character);

	//Display information (temporary)
	DisplayCharacterSheet(main_Character);

	//loop

	//end
	cout << endl << "We'll see you next time!" << endl;
	return;
}

void GameManager::InitPlayer(Player& main_Character)
{
	//Define Player object main_Character
	Item item;
	double hp, sp;
	hp = 10.0f, sp = 10.0f;
	string summary = "\nThis is a lot of character text that is supposed to display more information about the background of the character. Here you include the ambitions and achievements of the character in a lore-friendly manner.\n";

	InitItem(item);
	main_Character.setItem(item);
	main_Character.setSummary(summary);
	main_Character.setBaseHealth(hp);
	main_Character.setBaseSpecial(sp);
	main_Character.setClassName("Warrior");
	main_Character.setCurrency(150.0);
	cout << "...and what will be the name of your adventurer? :> ";
	main_Character.setPlayerName(util.PromptString());

}

//temporary for testing
void GameManager::InitItem(Item& item)
{
	//define sword
	item.setInventorySpace(2);
	item.setConsumable(false);
	item.setItemQuantity(1);
	cout << endl;
	item.setItemName("Sword");
	item.setItemID(1);
}

//temporary for testing
void GameManager::InitItem(Item& item, string itemName, double itemVal, bool isConsumable, int invSpace, int quantity, int ID)
{
	//define sword
	item.setItemValue(itemVal);
	item.setInventorySpace(invSpace);
	item.setConsumable(isConsumable);
	item.setItemQuantity(quantity);
	item.setItemName(itemName);
	item.setItemID(ID);
}

void GameManager::DisplayCharacterSheet(Player& main_Character)
{
	system("cls");
	cout << showpoint << setprecision(4);
	cout << "Here is a print-out of your character sheet!\n\n" << endl;
	cout << "***************************************" << endl;
	cout << "Name: " << main_Character.getPlayerName() << endl;
	cout << "Class: " << main_Character.getClassName() << endl;
	cout << "Item Name: " << main_Character.getItem().getItemName() << endl;
	cout << "Item ID: " << main_Character.getItem().getItemID() << endl;
	cout << "Health: " << main_Character.getBaseHealth() << endl;
	cout << "Special: " << main_Character.getBaseSpecial() << endl;
	cout << "Currency: " << main_Character.getCurrency() << endl;
	cout << "***************************************" << endl;
	cout << "\nSummary: " << main_Character.getSummary() << endl;
	cout << endl;
}
