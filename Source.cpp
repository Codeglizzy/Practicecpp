#include "Player.h"
using namespace std;

string PromptString();
void StartScreen();
void InitItem(Item& sword);
void InitPlayer(Player& myGuy);
void DisplayCharacterSheet(Player& myGuy);

int main()
{
	//Declare player 
	Player myGuy;

	//Introduce player
	StartScreen();

	//Initialize main_myGuy Player object
	InitPlayer(myGuy);

	//Display myGuy information
	DisplayCharacterSheet(myGuy);

	//End
	cout << "Thank you for joining! Stay tuned for a challenge in the arena!\n" << endl;

	return 0;
}

//Quick solution to grab input
string PromptString()
{
	string n; 
	cin >> n;
	return n;
}

//temporary for testing
void StartScreen()
{
	//Start
	cout << "Welcome.\n\n";
	//PlaySound(TEXT("song.wav"), NULL, SND_ASYNC);
	_getch();
	system("cls");

	cout << "Turn-based combat simulator!" << endl;
}

//temporary for testing
void InitItem(Item& sword)
{
	//define sword
	sword.setInventorySpace(2);
	sword.setConsumable(false);
	sword.setItemQuantity(1);
	cout << endl;
	cout << "\nWhat will you call your trusty steel friend, your excalibur, your bleeding edge :> ";
	sword.setItemName(PromptString());
	sword.setItemID(12);
}

//temporary for testing
void InitPlayer(Player& myGuy)
{
	//Define Player object myGuy
	Item sword;
	double hp, sp;
	hp = 7.8f, sp = 20.5f;
	string summary = "\nSeasoned warrior in the art of making S@!# happen!\n";

	InitItem(sword);
	myGuy.setItem(sword);
	myGuy.setSummary(summary);
	myGuy.setBaseHealth(hp);
	myGuy.setBaseSpecial(sp);
	myGuy.setClassName("Warrior");
	myGuy.setCurrency(150.4);
	cout << "...and what will be the name of your adventurer? :> ";
	myGuy.setPlayerName(PromptString());
	
}


void DisplayCharacterSheet(Player& myGuy)
{
	cout << showpoint << setprecision(4);
	cout << endl << "Name: " << myGuy.getPlayerName() << endl;
	cout << "Class: " << myGuy.getClassName() << endl;
	cout << "sword Name: " << myGuy.getItem().getItemName() << endl;
	cout << "sword ID: " << myGuy.getItem().getItemID() << endl;
	cout << "Health: " << myGuy.getBaseHealth() << endl;
	cout << "Special: " << myGuy.getBaseSpecial() << endl;
	cout << "Currency: " << myGuy.getCurrency() << endl;
	cout << "\nSummary: " << myGuy.getSummary() << endl;
	cout << endl;
}