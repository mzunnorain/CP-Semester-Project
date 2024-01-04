#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<iomanip>

using namespace std;

void Gamesetup();                                                                                                      //Ln 83
void Menu();                                                                                                           //Ln 129               //Functions Prototypes
void Showquestsandbattle();                                                                                            //Ln 142
void endingProgram(string difficulty);                                                                                 //Ln 175
void characterCreation();                                                                                              //Ln 216
bool isValidclass(string Class);                                                                                       //Ln 242
void displayCharacter();                                                                                               //Ln 252
string difficultyLevel();                                                                                              //Ln 270
bool isValiddifficulty(string difficulty);                                                                             //Ln 283
void WarriorQuests();                                                                                                  //Ln 293
void RogueQuests();                                                                                                    //Ln 421
void MageQuests();                                                                                                     //Ln 553
string getRandomWord();                                                                                                //Ln 686
void HardBattle(int questnumber);                                                                                      //Ln 697
void MediumBattle(int questnumber);                                                                                    //Ln 793                //Functions Prototypes
void EasyBattle(int questnumber);                                                                                      //Ln 899
int levelUp(int a);                                                                                                    //Ln 985
void Bosslevel(int x);                                                                                                 //Ln 997
void addRewardToInventory(const string& reward);                                                                       //Ln 1082
void displayInventory();                                                                                               //Ln 1097
void addtoStory1(const string& describe);                                                                              //Ln 1110
void addtoStory2(const string& describe);                                                                              //Ln 1115
void addtoStory3(const string& describe);                                                                              //Ln 1120
void Showstory();                                                                                                      //Ln 1126
int ReadHighScore();                                                                                                   //Ln 1148
void WriteHighScore(int score);                                                                                        //Ln 1166               //Functions   Prototypes
int ReadHighScore2();                                                                                                  //Ln 1178
void WriteHighScore2(int score);                                                                                       //Ln 1197 
int ReadHighScore3();                                                                                                  //Ln 1209
void WriteHighScore3(int score);                                                                                       //Ln 1228
void showHighscore();                                                                                                  //Ln 1241
void clearScreen();                                                                                                    //Ln 1250

string major_difficulty = "easy";     // setting up default difficulty easy

int maxscore = ReadHighScore();
int maxscore2 = ReadHighScore2();       //for storing highsores of easy medium and hard.
int maxscore3 = ReadHighScore3();

string inventory[6];            //array for inventory
int mission2[5] = { 0 };                  //for inventory check

string story1 = " ";
string story2 = " ";      //for different stories
string story3 = " ";



int main() {
	Gamesetup();            //main function
	return 0;
}


struct {
	string Name;
	string Class;            // Struture for character
	int  Health = 100;
	int EXP = 0;
	int level = 1;
	int score = 0000;
}character;


struct Quest {
	string name_description;
	int EXP;
	string reward;
	// Structure for Quest
};


//Main driver of the program
void Gamesetup() {
	char take;
	string difficulty = major_difficulty;

	do {
		Menu();
		cin >> take;
		cin.ignore(1000, '\n');
		switch (take) {
		case '1':
			clearScreen();
			Showquestsandbattle(); // Pass the selected difficulty
			break;
		case '2':
			clearScreen();
			showHighscore();

			break;
		case '3':
			clearScreen();
			difficulty = difficultyLevel(); // Set the difficulty
			major_difficulty = difficulty;
			cout << "\n\n";
			break;
		case '4':
			clearScreen();
			displayInventory();
			cout << "\n\n";
			break;
		case '5':
			clearScreen();
			Showstory();
			break;
		case '6':
			exit(0);
			break;
		default:
			cout << "Invalid Input\n\n";
			break;
		}

	} while (take != 6);
}


//Displaying Menu
void Menu() {
	cout << "\tMAIN MENU\n";
	cout << "1. Start Game.\n";
	cout << "2. High Scores.\n";
	cout << "3. Difficulty.\n";
	cout << "4. Inventory.\n";
	cout << "5. Storyline.\n";
	cout << "6. Exit.\n";
	cout << "Enter your choice (1-6): ";
}


//Showing Battles and Quests
void Showquestsandbattle() {
	char  c;
	cout << "\t\t\tWelcome! To The Mythical Land of Eldoria." << endl << endl;
	characterCreation();

	do {
		displayCharacter();

		if (character.Class == "Warrior") {
			WarriorQuests();
		}
		else if (character.Class == "Rogue") {
			RogueQuests();
		}
		else if (character.Class == "Mage") {
			MageQuests();
		}


		cout << "\n\nPress 0 to exit, any other key to continue: ";
		cin >> c;
		clearScreen();

	} while (c != '0');

	displayCharacter();
	endingProgram(major_difficulty);
	exit(0); // Exiting game if user wants
}



//After every battle end game end show this menu
void endingProgram(string difficulty) {

	char take2;
	do {
		cout << "\n\n1. Play Again.\n";
		cout << "2. High Scores.\n";
		cout << "3. Inventory.\n";
		cout << "4. Storyline.\n";
		cout << "5. Exit.\n";
		cout << "Enter your choice (1-5): ";
		cin >> take2;
		cin.ignore(1000, '\n');
		switch (take2) {
		case '1':
			clearScreen();
			character.score = 0;
			Showquestsandbattle();
			break;
		case '2':
			showHighscore();
			exit(0);                   //exit after showing
			break;
		case '3':
			displayInventory();
			exit(0);         //exit after showing
			break;
		case '4':
			Showstory();
			exit(0);
			break;
		case '5':
			exit(0);
			break;
		default:
			cout << "Invalid Input.";
		}
	} while (take2 != 5);

}


void characterCreation() {

	cout << "Enter name of your Character: ";
	cin >> character.Name;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Choose your class('Warrior','Rogue','Mage'): ";
	cin >> character.Class;
	cin.clear();
	cin.ignore();
	character.Health = 100;                                         //Function for Character Creation
	character.EXP = 0;
	character.level = 1;
	while (!isValidclass(character.Class)) {
		cout << "(Invalid Class. provide a Valid Class): ";
		cin >> character.Class;
	}
	if (isValidclass(character.Class)) {
		clearScreen();
	}
}


// Function for cheking valid class
bool isValidclass(string Class) {
	if (Class == "Warrior" || Class == "Rogue" || Class == "Mage") {
		return true;
	}
	else
		return false;
}


//Function for displaying Character
void displayCharacter() {

	cout << endl << endl;
	cout << "\t\t" << "|||||||||||||||||||||||||" << endl;
	cout << "\t\t" << "|" << "\t\t\t" << "|" << endl;
	cout << "\t\t" << "|" << "\tName:" << character.Name << "\t|" << endl;
	cout << "\t\t" << "|" << "\tClass:" << character.Class << "\t|" << endl;
	cout << "\t\t" << "|" << "\tHealth:" << character.Health << "\t|" << endl;
	cout << "\t\t" << "|" << "\tEXP:" << character.EXP << " \t\t|" << endl;
	cout << "\t\t" << "|" << "\tLevel:" << character.level << "\t\t|" << endl;
	cout << "\t\t" << "|" << "\tScore:" << character.score << "         |" << endl;
	cout << "\t\t" << "|" << "\t\t\t" << "|" << endl;
	cout << "\t\t" << "|||||||||||||||||||||||||" << endl << endl;
}



// Function for selecting difficulty level
string difficultyLevel() {
	string difficulty;
	cout << "Choose your difficulty Level (Easy, Medium, Hard):";
	getline(cin, difficulty);
	while (!isValiddifficulty(difficulty)) {              //not getting difficulty right
		cout << "Enter Valid Input: ";
		getline(cin, difficulty);
	}

	return difficulty;
}

// Funtion for checking diffiulty level
bool isValiddifficulty(string difficulty) {
	if (difficulty == "Easy" || difficulty == "Medium" || difficulty == "Hard" || difficulty == "easy" || difficulty == "medium" || difficulty == "hard") {
		return true;
	}
	else
		return false;
}


// Function for the quests of Warrior
void WarriorQuests() {

	int choice;
	Quest quest[5];

	quest[0].name_description = "Valor's Lost Blade: Retrieve legendary sword.";
	quest[1].name_description = "Kingdom's Defense: Battle invading monsters.";
	quest[2].name_description = "Ally Rescue Mission : Save captured friend";
	quest[3].name_description = "Coliseum Gladiator Trials : Win arena battles.";
	quest[4].name_description = "Sacred Temple Journey : Seek ancient wisdom.";

	quest[0].EXP = 5;
	quest[1].EXP = 10;
	quest[2].EXP = 15;
	quest[3].EXP = 20;
	quest[4].EXP = 25;

	quest[0].reward = "Legendary Sword";
	quest[1].reward = "Spear";
	quest[2].reward = "Magic Knife";
	quest[3].reward = "Crossbow";
	quest[4].reward = "Polearms";

	do {
		cout << "Choose a Quest you want to embark on:\n" << endl;
		cout << "Quest,\tEXP,\tReward\n";
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << ". " << quest[i].name_description << ", " << quest[i].EXP << ", " << quest[i].reward << endl;
		}
		cout << "Enter your Quest (1-5): ";
		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 5) {
			cout << "Invalid input. Please enter a number between 1 and 5." << endl;
			cin.clear();
			cin.ignore();
		}
		else {
			break;
		}
	} while (true);
	string randomWord = getRandomWord();

	switch (choice) {

	case 1:
		cout << endl << character.Name << " while embarking " << quest[0].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		character.EXP = character.EXP + quest[0].EXP;

		if (mission2[0] == 0) {
			addRewardToInventory(quest[0].reward);
			addtoStory1(quest[0].name_description);
			mission2[0] = 1;
		}
		levelUp(character.EXP);
		break;

	case 2:
		cout << endl << character.Name << " while embarking " << quest[1].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;


		character.EXP = character.EXP + quest[1].EXP;
		if (mission2[1] == 0) {
			addRewardToInventory(quest[1].reward);
			addtoStory1(quest[1].name_description);
			mission2[1] = 1;
		}
		levelUp(character.EXP);
		break;

	case 3:
		cout << endl << character.Name << " while embarking " << quest[2].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		character.EXP = character.EXP + quest[2].EXP;
		if (mission2[2] == 0) {
			addRewardToInventory(quest[2].reward);
			addtoStory1(quest[2].name_description);
			mission2[2] = 1;
		}
		levelUp(character.EXP);
		break;

	case 4:
		cout << endl << character.Name << " while embarking " << quest[3].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		character.EXP = character.EXP + quest[3].EXP;
		if (mission2[3] == 0) {
			addRewardToInventory(quest[3].reward);
			addtoStory1(quest[3].name_description);
			mission2[3] = 1;
		}
		levelUp(character.EXP);
		break;

	case 5:
		cout << endl << character.Name << " while embarking  " << quest[4].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		character.EXP = character.EXP + quest[4].EXP;
		if (mission2[4] == 0) {
			addRewardToInventory(quest[4].reward);
			addtoStory1(quest[4].name_description);
			mission2[4] = 1;
		}
		levelUp(character.EXP);
		break;
	}


	//Battles according to the diffiulties and passing the questnumber to inrease difficulties of eah quest
	if (major_difficulty == "easy" || major_difficulty == "Easy") {
		EasyBattle(choice);
	}
	else if (major_difficulty == "medium" || major_difficulty == "Medium") {
		MediumBattle(choice);
	}
	else if (major_difficulty == "hard" || major_difficulty == "Hard") {
		HardBattle(choice);
	}
}


// Function for the quests of Rogue
void RogueQuests() {

	int choice;
	Quest quest[5];

	quest[0].name_description = "Thieves' Heist: Execute daring theft.";
	quest[1].name_description = "Shadow Guild Espionage : Infiltrate rival guild.";
	quest[2].name_description = "Assassin's Mark: Eliminate high-profile targets.";
	quest[3].name_description = "Black Market Smuggling : Transport contraband discreetly.";
	quest[4].name_description = "Mystic Relic Retrieval : Secure mystical artifact.";

	quest[0].EXP = 5;
	quest[1].EXP = 10;
	quest[2].EXP = 15;
	quest[3].EXP = 20;
	quest[4].EXP = 25;

	quest[0].reward = "Whip";
	quest[1].reward = "Scimiter";
	quest[2].reward = "Garrote";
	quest[3].reward = "Hooksword";
	quest[4].reward = "Blowgun";

	do {
		cout << "Choose a Quest you want to embark on:\n" << endl;
		cout << "Quest,\tEXP,\tReward\n";
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << ". " << quest[i].name_description << ", " << quest[i].EXP << ", " << quest[i].reward << endl;
		}
		cout << "Enter your Quest (1-5): ";
		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 5) {
			cout << "Invalid input. Please enter a number between 1 and 5." << endl;
			cin.clear();
			cin.ignore();
		}

		else {
			break;
		}
	} while (true);
	string randomWord = getRandomWord();

	switch (choice) {
	case 1:
		cout << endl << character.Name << " while embarking " << quest[0].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		character.EXP = character.EXP + quest[0].EXP;
		if (mission2[0] == 0) {
			addRewardToInventory(quest[0].reward);
			addtoStory2(quest[0].name_description);
			mission2[0] = 1;

		}
		levelUp(character.EXP);
		break;

	case 2:
		cout << endl << character.Name << " while embarking " << quest[1].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		character.EXP = character.EXP + quest[1].EXP;
		if (mission2[1] == 0) {
			addRewardToInventory(quest[1].reward);
			addtoStory2(quest[1].name_description);
			mission2[1] = 1;

		}
		levelUp(character.EXP);
		break;

	case 3:
		cout << endl << character.Name << " while embarking " << quest[2].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		character.EXP = character.EXP + quest[2].EXP;
		if (mission2[2] == 0) {
			addRewardToInventory(quest[2].reward);
			addtoStory2(quest[2].name_description);
			mission2[2] = 1;

		}
		levelUp(character.EXP);
		break;

	case 4:
		cout << endl << character.Name << " while embarking " << quest[3].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;


		character.EXP = character.EXP + quest[3].EXP;
		if (mission2[3] == 0) {
			addRewardToInventory(quest[3].reward);
			addtoStory2(quest[3].name_description);
			mission2[3] = 1;

		}
		levelUp(character.EXP);
		break;

	case 5:
		cout << endl << character.Name << " while embarking  " << quest[4].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;


		character.EXP = character.EXP + quest[4].EXP;
		if (mission2[4] == 0) {
			addRewardToInventory(quest[4].reward);
			addtoStory2(quest[4].name_description);
			mission2[4] = 1;
		}
		levelUp(character.EXP);
		break;
	}


	//Battles according to the diffiulties and passing the questnumber to inrease difficulties of eah quest
	if (major_difficulty == "easy" || major_difficulty == "Easy") {
		EasyBattle(choice);
	}
	else if (major_difficulty == "medium" || major_difficulty == "Medium") {
		MediumBattle(choice);
	}
	else if (major_difficulty == "hard" || major_difficulty == "Hard") {
		HardBattle(choice);
	}

}

// Function for the quests of Mage
void MageQuests() {
	int choice;
	Quest quest[5];

	quest[0].name_description = "Arcane Library Restoration : Recover ancient knowledge.";
	quest[1].name_description = "Elemental Balance : Restore elemental harmony.";
	quest[2].name_description = "Astral Beacon Rekindling : Reignite celestial beacons.";
	quest[3].name_description = "Spellcaster's Trial: Master magical labyrinth.";
	quest[4].name_description = "Ethereal Nexus Connection : Forge ethereal alliances.";

	quest[0].EXP = 5;
	quest[1].EXP = 10;
	quest[2].EXP = 15;
	quest[3].EXP = 20;
	quest[4].EXP = 25;

	quest[0].reward = "Staff";
	quest[1].reward = "Wand";
	quest[2].reward = "Crystal Orb";
	quest[3].reward = "Grimoires";
	quest[4].reward = "Magical Sword";




	do {
		cout << "Choose a Quest you want to embark on:\n" << endl;
		cout << "Quest,\tEXP,\tReward\n";
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << ". " << quest[i].name_description << ", " << quest[i].EXP << ", " << quest[i].reward << endl;
		}
		cout << "Enter your Quest (1-5): ";
		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 5) {
			cout << "Invalid input. Please enter a number between 1 and 5." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			break;
		}
	} while (true);

	string randomWord = getRandomWord();
	switch (choice) {
	case 1:
		cout << endl << character.Name << " while embarking " << quest[0].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		if (mission2[0] == 0) {
			addRewardToInventory(quest[0].reward);
			addtoStory3(quest[0].name_description);
			mission2[0] = 1;
		}
		character.EXP += quest[0].EXP;
		levelUp(character.EXP);


		break;
	case 2:
		cout << endl << character.Name << " while embarking " << quest[1].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		if (mission2[1] == 0) {
			addRewardToInventory(quest[1].reward);
			addtoStory3(quest[1].name_description);
			mission2[1] = 1;
		}
		character.EXP += quest[1].EXP;
		levelUp(character.EXP);
		break;


	case 3:
		cout << endl << character.Name << " while embarking " << quest[2].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;


		if (mission2[2] == 0)
		{
			addRewardToInventory(quest[2].reward);
			addtoStory3(quest[2].name_description);
			mission2[2] = 1;
		}
		character.EXP += quest[2].EXP;
		levelUp(character.EXP);           //pass exp to level up
		break;

	case 4:
		cout << endl << character.Name << " while embarking " << quest[3].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		if (mission2[3] == 0)
		{
			addRewardToInventory(quest[3].reward);
			addtoStory3(quest[3].name_description);
			mission2[3] = 1;
		}
		character.EXP += quest[3].EXP;
		levelUp(character.EXP);
		break;

	case 5:
		cout << endl << character.Name << " while embarking  " << quest[4].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;

		if (mission2[4] == 0)
		{
			addRewardToInventory(quest[4].reward);
			addtoStory3(quest[4].name_description);
			mission2[4] = 1;
		}
		character.EXP += quest[4].EXP;
		levelUp(character.EXP);         //pass exp to levelup
		break;
	}

	//Battles according to the diffiulties and passing the questnumber to inrease difficulties of eah quest
	if (major_difficulty == "easy" || major_difficulty == "Easy") {
		EasyBattle(choice);
	}
	else if (major_difficulty == "medium" || major_difficulty == "Medium") {
		MediumBattle(choice);
	}
	else if (major_difficulty == "hard" || major_difficulty == "Hard") {
		HardBattle(choice);
	}


}

//Function for getting mythical creatures
string getRandomWord() {
	char words[][20] = { "DRAGON", "DRAKULLA", "ANACONDA", "SHADOW", "GODZILLA", "DARKFIRE", "NETHERWING", "GHOST", "TIGER" };

	int numWords = sizeof(words) / sizeof(words[0]);         //getting total words in the arrray

	srand((time(0)));
	int index = rand() % numWords;

	return words[index];
}


// Function if user chooses hard level
void HardBattle(int questnumber) {
	srand(time(0));             //random number simulation

	int randomWord_health = 0;
	string randomWord;

	if (character.level > 5) {
		cout << "\nPress 1 to play level or 0 to exit:"; // Boss level after 5
		int answer;
		cin >> answer;

		if (answer == 1) {
			Bosslevel(character.level);
			return; // Exit the function after calling Bosslevel
		}
		else {
			clearScreen();
			displayCharacter();
			return;
		}
	}
	else {
		int baseHealth = 100;
		randomWord_health = baseHealth + (character.level * 20) + (questnumber * 10); // Increasing difficulty for levels & questnumbers
		randomWord = getRandomWord();
	}

	string input;
	do {
		cout << "Press Enter to attack or 0 to exit...\n"; // Enter to attack and 0 to exit
		cin.ignore();
		getline(cin, input);


		if (input == "0") {
			clearScreen();
			displayCharacter();
			endingProgram(major_difficulty);
			break;
		}

		int attackByCharacter = rand() % (10 + 30);            //ur damage
		int attackByEnemy = rand() % 50;                   //enemy damage

		if (attackByCharacter == 0) {
			cout << randomWord << " survived " << character.Name << "'s attack." << endl << endl;
		}
		else {
			cout << character.Name << " attacked " << randomWord << " for " << attackByCharacter << " damage." << endl << endl;
		}
		randomWord_health -= attackByCharacter;
		character.score += attackByCharacter;

		if (randomWord_health <= 0) {
			cout << character.Name << " defeated " << randomWord;
			character.Health = 100;                                        // If won the battle
			character.EXP += 20;
			break;
		}

		cout << "Press Enter to see enemy's attack...\n";
		getline(cin, input);

		if (attackByEnemy == 0) {
			cout << character.Name << " survived " << randomWord << "'s attack." << endl << endl;
		}
		else {
			cout << randomWord << " attacked " << character.Name << " for " << attackByEnemy << " damage." << endl << endl;
		}
		character.Health -= attackByEnemy;
		character.score -= attackByEnemy;

		character.score = max(0, character.score);

		if (character.Health <= 0) {
			cout << randomWord << " defeated " << character.Name;
			character.Health = 0;
			character.EXP -= (questnumber * 5);
			clearScreen();                                            // If lost the battle
			cout << "\n\nYOU HAVE LOST\n\n";
			displayCharacter();
			endingProgram(major_difficulty);
			break;
		}


	} while (character.Health >= 0 && randomWord_health >= 0);


	if (maxscore3 <= character.score) {
		maxscore3 = character.score;                                          // Max score handling
		WriteHighScore3(maxscore3);
	}
}

// Function if the user chooses medium level
void MediumBattle(int questnumber) {
	srand(time(0));

	int randomWord_health = 0;
	string randomWord;

	if (character.level > 5) {
		cout << "\nPress 1 to play level or 0 to exit:"; // Boss level after 5
		int answer;
		cin >> answer;

		if (answer == 1) {
			Bosslevel(character.level);
			return; // Exit the function after calling Bosslevel
		}
		else {
			clearScreen();
			displayCharacter();
			return;
		}
	}
	else {
		int baseHealth = 100;
		randomWord_health = baseHealth + (character.level * 20) + (questnumber * 10); // Increasing difficulty for levels & questnumbers
		randomWord = getRandomWord();
	}

	string input;
	do {
		cout << "Press Enter to attack or 0 to exit...\n"; // Enter to attack and 0 to exit
		cin.ignore();
		getline(cin, input);


		if (input == "0") {
			clearScreen();
			displayCharacter();
			endingProgram(major_difficulty);
			break;
		}

		int attackByCharacter = rand() % 30;
		int attackByEnemy = rand() % 30;

		if (attackByCharacter == 0) {
			cout << randomWord << " survived " << character.Name << "'s attack." << endl << endl;
		}
		else {
			cout << character.Name << " attacked " << randomWord << " for " << attackByCharacter << " damage." << endl << endl;
		}
		randomWord_health -= attackByCharacter;
		character.score += attackByCharacter;

		if (randomWord_health <= 0) {
			cout << character.Name << " defeated " << randomWord;
			character.Health = 100;                                        // If won
			character.EXP += 10;
			break;
		}

		cout << "Press Enter to see enemy's attack...\n";
		getline(cin, input);

		if (attackByEnemy == 0) {
			cout << character.Name << " survived " << randomWord << "'s attack." << endl << endl;
		}
		else {
			cout << randomWord << " attacked " << character.Name << " for " << attackByEnemy << " damage." << endl << endl;
		}
		character.Health -= attackByEnemy;
		character.score -= attackByEnemy;

		character.score = max(0, character.score);

		if (character.Health <= 0) {
			cout << randomWord << " defeated " << character.Name;
			character.Health = 0;
			character.EXP -= (questnumber * 5);
			clearScreen();                                            // If lost
			cout << "\n\nYOU HAVE LOST\n\n";
			endingProgram(major_difficulty);
			break;
		}


	} while (character.Health >= 0 && randomWord_health >= 0);


	if (maxscore2 <= character.score) {
		maxscore2 = character.score;                                          // Max score
		WriteHighScore2(maxscore2);
	}
}


// Function if the user chooses easy level
void EasyBattle(int questnumber) {
	srand(time(0));

	int randomWord_health = 0;
	string randomWord;

	if (character.level > 5) {
		cout << "\nPress 1 to play level or 0 to exit:"; // Boss level after 5
		int answer;
		cin >> answer;

		if (answer == 1) {
			Bosslevel(character.level);
			return; // Exit the function after calling Bosslevel
		}
		else {
			clearScreen();
			displayCharacter();
			return;
		}
	}
	else {
		int baseHealth = 100;
		randomWord_health = baseHealth + (character.level * 20) + (questnumber * 10); // Increasing difficulty for levels & questnumbers
		randomWord = getRandomWord();
	}

	string input;
	do {
		cout << "Press Enter to attack or 0 to exit...\n"; // Enter to attack and 0 to exit
		cin.ignore();
		getline(cin, input);


		if (input == "0") {
			clearScreen();
			displayCharacter();
			endingProgram(major_difficulty);
			break;
		}

		int attackByCharacter = rand() % 100;
		int attackByEnemy = rand() % 10;

		if (attackByCharacter == 0) {
			cout << randomWord << " survived " << character.Name << "'s attack." << endl << endl;
		}
		else {
			cout << character.Name << " attacked " << randomWord << " for " << attackByCharacter << " damage." << endl << endl;
		}
		randomWord_health -= attackByCharacter;
		character.score += attackByCharacter;

		if (randomWord_health <= 0) {
			cout << character.Name << " defeated " << randomWord;
			character.Health = 100;                                        // If won
			character.EXP += 5;
			break;
		}

		cout << "Press Enter to see enemy's attack...\n";
		getline(cin, input);

		if (attackByEnemy == 0) {
			cout << character.Name << " survived " << randomWord << "'s attack." << endl << endl;
		}
		else {
			cout << randomWord << " attacked " << character.Name << " for " << attackByEnemy << " damage." << endl << endl;
		}
		character.Health -= attackByEnemy;
		character.score -= attackByEnemy;

		character.score = max(0, character.score);

		if (character.Health <= 0) {
			cout << randomWord << " defeated " << character.Name;
			character.Health = 0;
			character.EXP -= (questnumber * 5);
			clearScreen();                                            // If lost
			cout << "\n\nYOU HAVE LOST\n\n";
			endingProgram(major_difficulty);
			break;
		}


	} while (character.Health >= 0 && randomWord_health >= 0);


	if (maxscore <= character.score) {
		maxscore = character.score;                                          // Max score
		WriteHighScore(maxscore);
	}
}


//Function for levelling up
int levelUp(int a) {
	int increase = 100;
	int characterInitialhealth = 100;
	if (a >= increase) {
		character.level++;
		character.EXP = 0;
		increase *= 2;
	}
	return character.level;
}

//Function for bosslevel
void Bosslevel(int x) {
	srand(time(0)); //random number simulation
	int ur_attak = 0, boss_attack = 0;

	if (x > 1) {                                                   //if level > 5 boss level
		cout << "YOU HAVE REACHED BOSS LEVEL." << endl << endl;
		int randomWord_health = 500;
		do {
			int ur_attack = rand() % 30;
			int boss_attack = rand() % 10;
			if (ur_attack == 0) {
				cout << "BOSS" << " survived " << character.Name << "'s attack." << endl;
			}
			else {
				cout << character.Name << " attacked " << "BOSS" << " for " << ur_attack << " damage." << endl;
			}
			randomWord_health = randomWord_health - ur_attack;
			character.score = character.score + ur_attack;


			if (randomWord_health <= 0) {
				cout << character.Name << " defeated " << "BOSS" << endl << endl;
				cout << "You Won.";                    //VICTORY
				break;
			}

			if (boss_attack == 0) {
				cout << character.Name << " survived " << "BOSS" << "'s attack." << endl;
			}

			else {
				cout << "BOSS" << " attacked " << character.Name << " for " << boss_attack << " damage." << endl;
			}
			character.Health = character.Health - boss_attack;
			character.score = character.score - boss_attack;

			if (character.score < 0) {
				character.score = 0;
			}

			if (character.Health <= 0) {
				cout << "BOSS" << " defeated " << character.Name;
				character.Health = 0;
				displayCharacter();
				cout << "\n\n";
				endingProgram(major_difficulty);                //if lost game end
				if (character.Health < 0)
					character.Health = 0;

				if (character.EXP < 0) {
					character.EXP = 0;
				}
				break;
			}


		} while (character.Health >= 0 || randomWord_health >= 0);


		if (major_difficulty == "easy" || major_difficulty == "Easy") {
			if (maxscore <= character.score)
				maxscore = character.score;                         //highscore if u r playing easy
			WriteHighScore(maxscore);
		}


		if (major_difficulty == "medium" || major_difficulty == "Medium") {
			if (maxscore2 <= character.score)
				maxscore2 = character.score;                         //highscore if u r playing medium
			WriteHighScore2(maxscore2);
		}


		if (major_difficulty == "hard" || major_difficulty == "Hard") {
			if (maxscore3 <= character.score)
				maxscore3 = character.score;                         //highscore if u r playing  hard
			WriteHighScore3(maxscore3);
		}


	}
}


//Function for adding items to inventory
void addRewardToInventory(const string& reward) {
	for (int i = 0; i < 6; ++i) {
		if (inventory[i].empty()) {
			inventory[i] = reward;
			break;  // Exit the loop after adding the reward
		}
	}
}


//Function for displaying inventory
void displayInventory() {
	cout << "Inventory Contents:" << endl;
	bool isEmpty = true;

	for (int i = 0; i < 6; ++i) {
		if (!inventory[i].empty()) {
			cout << "Slot " << i + 1 << ": " << inventory[i] << endl;
			isEmpty = false;
		}
	}

	if (isEmpty) {
		cout << "Inventory is empty." << endl;
	}
}

//Story for class warrior
void addtoStory1(const string& describe) {
	story1 = story1 + "has cleared " + describe;
}

//Story  for  class rogue
void addtoStory2(const string& describe) {
	story2 = story2 + describe;
}

//Story for class mage
void addtoStory3(const string& describe) {
	story3 = story3 + describe;
}


//Showing stories function
void Showstory() {
	char take3;
	cout << "Enter class to view story:\n1.Warrior\n2.Rogue\n3.Mage\nChoose from (1-3):";
	cin >> take3;
	switch (take3) {
	case '1':
		cout << story1 << endl << endl;
		break;
	case '2':
		cout << story2 << endl << endl;
		break;
	case '3':
		cout << story3 << endl << endl;
		break;
	default:
		cout << "Invalid Input.";
	}
}



// Function for getting HighScore
int ReadHighScore() {
	int highScore = 0;
	ifstream inputFile("highscore.txt");

	if (inputFile.is_open()) {
		inputFile >> highScore;
		inputFile.close();
	}
	else {
		cout << "Unable to open highscore.txt file for reading." << endl;

	}

	return highScore;
}

//For  handling highscores of easy difficulty 

void WriteHighScore(int score) {
	ofstream outputFile("highscore.txt");
	if (outputFile.is_open()) {
		outputFile << score; // Overwrite the score in the file
		outputFile.close();
	}
	else {
		cout << "Unable to open or write to highscore.txt file!" << endl;

	}
}

int ReadHighScore2() {
	int highScore2 = 0;
	ifstream inputFile2("highscore2.txt");

	if (inputFile2.is_open()) {
		inputFile2 >> highScore2;
		inputFile2.close();
	}
	else {
		cout << "Unable to open highscore2.txt file for reading." << endl;

	}

	return highScore2;
}

//For handling highscores for medium diffiulty


void WriteHighScore2(int score) {
	ofstream outputFile2("highscore2.txt");
	if (outputFile2.is_open()) {
		outputFile2 << score; // Overwrite the score in the file
		outputFile2.close();
	}
	else {
		cout << "Unable to open or write to highscore2.txt file!" << endl;

	}
}

int ReadHighScore3() {
	int highScore3 = 0;
	ifstream inputFile3("highscore3.txt");

	if (inputFile3.is_open()) {
		inputFile3 >> highScore3;
		inputFile3.close();
	}
	else {
		cout << "Unable to open highscore3.txt file for reading." << endl;

	}

	return highScore3;
}


//For handling highscores for difficulty Hard

void WriteHighScore3(int score) {
	ofstream outputFile3("highscore3.txt");
	if (outputFile3.is_open()) {
		outputFile3 << score; // Overwrite the score in the file
		outputFile3.close();
	}
	else {
		cout << "Unable to open or write to highscore3.txt file!" << endl;
	}
}


//Funtion for displaying highscores
void showHighscore() {
	cout << "\nEASY: " << maxscore;
	cout << "\nMEDIUM: " << maxscore2;
	cout << "\nHARD: " << maxscore3;
	cout << "\n\n";
}


//Function for clearing Screen.
void clearScreen() {
	system("cls");
}