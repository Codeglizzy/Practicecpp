# Turn-Based Combat Simulator
This is a side project I decided to create to practice my C++ skills.

# How to use
- Clone the repository
- Navigate to /TurnBasedCombat/Release/
- Locate and run the TurnBasedCombat.exe file
- Enjoy

# Customization

If you have a C++ compiler and an editor, you can easily modify the code how you see fit.

### Adding an Enemy
You can easily create your own enemies to encounter by utilizing the `Enemy` class.

In order to use the `Enemy` class, navigate to `EnemyLibrary.h` and declare an `Enemy` named 
`myEnemy` or whatever enemy you plan to define

**Example:**

```
EnemyLibrary.h

class EnemyLibrary
{
private:
	ItemLibrary itemLib;
public:
	vector<Enemy> enemies;

	Enemy goblin;
	Enemy ogre;
	Enemy orc;
	Enemy myEnemy;
  
```

Now just initialize the enemy in the constructor and place the enemy in the battle queue.
The `Enemy.Initialize()` member function takes in a total of 5 arguments:
- Name (`string`)
- Class Name (`string`)
- Health Points (`double`)
- Damage Points (`double`)
- Starting Item (`Item`)


**Example:**

```
	Enemy goblin;
	Enemy ogre;
	Enemy orc;
	Enemy myEnemy;
  EnemyLibrary()
	{
		goblin.Initialize("Goblin", "Scout", 15, 2, this->itemLib.weapon_Rogue);
		ogre.Initialize("Ogre of the Swamp", "Brute", 3, 7, this->itemLib.weapon_Warrior);
		orc.Initialize("Orc King", "King Eater", 25, 1, this->itemLib.weapon_Priest);

		//Initialize 'myEnemy' 
		myEnemy.Initialize("Hello World", "Greeter of Many", 15, 5, this->itemLib.weapon_Wizard);

		enemies.push_back(goblin);  //1st enemy
		enemies.push_back(ogre);    //2nd enemy
		enemies.push_back(orc);     //3rd enemy
		enemies.push_back(myEnemy); //4th enemy (newly created and Initialized)
	}
  
```

That is all. You have successfully created an enemy!


### Adding an Item
The process for adding an item is the exact same as adding an enemy, only with different arguments
when initializing in the constructor.

The `Item.Initialize()` member function contains 5 arguments, similar to `Enemy` but slightly different:
- Name (`string`)
- Consumable (`boolean`)
- Price (`double`)
- Damage/Restore Boost (`double`)
- Item Tag (`string`)

The process of implementation is similar to adding an enemy, only you will be in `ItemLibrary.h` 
for the initialization and adding to the queue.

**Example (I am creating the `weapon_holyStickOfDeath`):**
```
	//Declare items
	Item weapon_Warrior; 
	Item health_Potion; 
	Item special_Potion; 
	Item weapon_Wizard; 
	Item weapon_Rogue; 
	Item weapon_Priest; 
	Item weapon_holyStickOfDeath;

	ItemLibrary()
	{
		//Define items
		weapon_Warrior.Initialize("Mighty Blade", false, 150, 7, "weapon");
		health_Potion.Initialize("Health Elixir", true, 15, 15, "h_elixir");
		special_Potion.Initialize("Special Elixir", true, 20, 15, "s_elixir");
		weapon_Wizard.Initialize("Staff of Rage", false, 100, 4, "weapon");
		weapon_Rogue.Initialize("Deadly Daggers", false, 100, 3, "weapon");
		weapon_Priest.Initialize("Talisman of Light", false, 90, 4, "weapon");
		weapon_holyStickOfDeath.Initialize("Stick of Death", false, 50, 3, "gobbler");

		//Add items
		this->item_Database.push_back(weapon_Warrior);
		this->item_Database.push_back(weapon_Rogue);
		this->item_Database.push_back(weapon_Wizard);
		this->item_Database.push_back(weapon_Priest);
		this->item_Database.push_back(health_Potion);
		this->item_Database.push_back(special_Potion);
		this->item_Database.push_back(weapon_holyStickOfDeath);
		
	}
  
```

That is all for the item, although the game will not automatically assign the item to
the newly created enemy. You will need to do that manually during the creation of the 
enemy as I did earlier, but with the new item. Here's an example of how you could initialize 
an enemy with the newly created item:

```
CHANGE

myEnemy.Initialize("Hello World", "Greeter of Many", 15, 5, this->itemLib.weapon_Wizard);

TO

myEnemy.Initialize("Hello World", "Greeter of Many", 15, 5, this->itemLib.weapon_holyStickOfDeath);
```

That's pretty much the gist. Thanks for coming to my TED talk.
