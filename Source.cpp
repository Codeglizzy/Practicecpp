#include "Player.h"
using namespace std;

string PromptString();

int main()
{
	cout << "Welcome.\n\n";
	PlaySound(TEXT("song.wav"), NULL, SND_ASYNC);
	_getch();
	system("cls");

	cout << "Turn-based combat simulator!" << endl;

	string summary = "\nSeasoned warrior in the art of making S@!# happen!\n";
	
	double hp, sp;
	hp = 7.8f, sp = 20.5f;

	//define item
	Item sword;
	sword.setInventorySpace(2);
	sword.setConsumable(false);
	sword.setItemQuantity(1);
	cout << endl;
	cout << "\nWhat will you call your trusty steel friend, your excalibur, your bleeding edge :> ";
	sword.setItemName(PromptString());
	sword.setItemID(12);

	//define myGuy (player)
	Player myGuy;
	myGuy.setItem(sword);
	myGuy.setSummary(summary);
	myGuy.setBaseHealth(hp);
	myGuy.setSpecial(sp);
	myGuy.setClassName("Warrior");
	myGuy.setCurrency(150.00);
	cout << "...and what will be the name of your adventurer? :> ";
	myGuy.setPlayerName(PromptString());
	cout << showpoint << setprecision(6);
	cout << endl << "Name: " << myGuy.getPlayerName() << endl;
	cout << "Class: " << myGuy.getClassName() << endl;
	cout << "Item Name: " << myGuy.getItem().getItemName() << endl;
	cout << "Item ID: " << myGuy.getItem().getItemID() << endl;
	cout << "Health: " << myGuy.getHealth() << endl;
	cout << "Special: " << myGuy.getSpecial() << endl;
	cout << "Currency: " << myGuy.getCurrency() << endl;
	cout << "\nSummary: " << myGuy.getSummary() << endl;
	cout << endl;

	cout << "Thank you for joining! Stay tuned for a challenge in the arena!\n" << endl;

	return 0;
}

string PromptString()
{
	string n; 
	cin >> n;
	return n;
}