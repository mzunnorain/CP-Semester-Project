#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


bool mission[5] = { false };
int mission2[5] = { 0 };



bool isValidclass(string Class);
void displayCharacter();                   //Functions Prototypes
void WarriorQuests();
void RogueQuests();
void MageQuests();
string getRandomWord();
string difficultyLevel();
bool isValiddifficulty(string difficulty);
void clearScreen();
void Hardbattle();                         //Functions Prototypes
void Mediumbattle();
void Easybattle();
void addRewardToInventory(const string& reward);
void displayInventory();
void Showquestsandbattle(string b);
void Bosslevel(int x);
int levelUp(int a);
int ReadHighScore();
void WriteHighScore(int score);
int ReadHighScore2();
void WriteHighScore2(int score);
int ReadHighScore3();
void WriteHighScore3(int score);
void showHighscore();
void Menu();
void Gamesetup();
void endingProgram(string difficulty);

string major_difficulty = "easy";
int maxscore = ReadHighScore();
int maxscore2 = ReadHighScore2();
int maxscore3 = ReadHighScore3();
int score;
bool flag;
string inventory[8];


struct {
	string Name;
	string Class;            // Struture for character
	int  Health = 100;
	int EXP = 0;
	int level = 1;
	int score = 0;
}character;


struct Quest {
	string name_description;
	int EXP;
	string reward;
	// Structure for Quest
};


//Function for clearing Screen.
void clearScreen() {
	system("cls");
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
		// Handle file open failure more explicitly if needed
	}

	return highScore;
}



void WriteHighScore(int score) {
	ofstream outputFile("highscore.txt");
	if (outputFile.is_open()) {
		outputFile << score; // Overwrite the score in the file
		outputFile.close();
	}
	else {
		cout << "Unable to open or write to highscore.txt file!" << endl;
		// Handle file open failure more explicitly
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
		// Handle file open failure more explicitly if needed
	}

	return highScore2;
}




void WriteHighScore2(int score) {
	ofstream outputFile2("highscore2.txt");
	if (outputFile2.is_open()) {
		outputFile2 << score; // Overwrite the score in the file
		outputFile2.close();
	}
	else {
		cout << "Unable to open or write to highscore2.txt file!" << endl;
		// Handle file open failure more explicitly
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
		// Handle file open failure more explicitly if needed
	}

	return highScore3;
}




void WriteHighScore3(int score) {
	ofstream outputFile3("highscore3.txt");
	if (outputFile3.is_open()) {
		outputFile3 << score; // Overwrite the score in the file
		outputFile3.close();
	}
	else {
		cout << "Unable to open or write to highscore3.txt file!" << endl;
		// Handle file open failure more explicitly
	}
}


//Funtion for displaying highscores
void showHighscore() {
	cout << "\nEASY: " << maxscore;
	cout << "\nMEDIUM: " << maxscore2;
	cout << "\nHARD: " << maxscore3;
	cout << "\n\n";
}

void characterCreation() {

	cout << "Enter name of your Character: ";

	cin >> character.Name;
	cin.ignore();
	cout << "Choose your class('Warrior','Rogue','Mage'): ";
	cin >> character.Class;
	cin.clear();
	cin.ignore();
	character.Health = 100;                                         //Function for Character Creation
	character.EXP = 0;
	character.level = 1;
	while (!isValidclass(character.Class)) {
		cout << "(Invalid Class. provide a Valid Class): ";
		getline(cin, character.Class);
	}
	if (isValidclass(character.Class)) {
		clearScreen();
		//displayCharacter();
	}
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
	cout << "\t\t" << "|" << "\tScore:" << character.score << "\t        |" << endl;
	cout << "\t\t" << "|" << "\t\t\t" << "|" << endl;
	cout << "\t\t" << "|||||||||||||||||||||||||" << endl << endl;
}



// Function for cheking valid class
bool isValidclass(string Class) {
	if (Class == "Warrior" || Class == "Rogue" || Class == "Mage") {
		return true;
	}
	else
		return false;
}


// Function for the quests of Warrior
void WarriorQuests() {

	int choice;
	Quest quest[5];

	quest[0].name_description = "1.Valor's Lost Blade: Retrieve legendary sword.";
	quest[1].name_description = "2.Kingdom's Defense: Battle invading monsters.";
	quest[2].name_description = "3.Ally Rescue Mission : Save captured friend";
	quest[3].name_description = "4.Coliseum Gladiator Trials : Win arena battles.";
	quest[4].name_description = "5.Sacred Temple Journey : Seek ancient wisdom.";

	quest[0].EXP = 5;
	quest[1].EXP = 10;
	quest[2].EXP = 15;
	quest[3].EXP = 20;
	quest[4].EXP = 25;

	quest[0].reward = "Axe";
	quest[1].reward = "Spear";
	quest[2].reward = "Magic Knife";
	quest[3].reward = "Crossbow";
	quest[4].reward = "Polearms";

	do {
		cout << "Choose a Quest you want to embark on:" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "{ " << quest[i].name_description << ", " << quest[i].EXP << ", " << quest[i].reward << " }" << endl;
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
		if (flag)
		{
			if (mission[0] == false && mission2[0] == 0) {
				addRewardToInventory(quest[0].reward);
				mission2[0] = 1;
			}
			character.EXP += 5;
			levelUp(character.EXP);
		}
		break;
	case 2:
		cout << endl << character.Name << " while embarking " << quest[1].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[1] == false && mission2[1] == 0) {
				addRewardToInventory(quest[1].reward);
				mission2[1] = 1;
			}
			character.EXP += 10;
			levelUp(character.EXP);

		}
		break;
	case 3:
		cout << endl << character.Name << " while embarking " << quest[2].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[2] == false && mission2[2] == 0) {
				addRewardToInventory(quest[2].reward);
				mission2[2] = 1;
			}
			character.EXP += 15;
			levelUp(character.EXP);
		}
		break;
	case 4:
		cout << endl << character.Name << " while embarking " << quest[3].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[3] == false && mission2[3] == 0) {
				addRewardToInventory(quest[3].reward);
				mission2[3] = 1;
			}
			character.EXP += 20;
			levelUp(character.EXP);
		}
		break;
	case 5:
		cout << endl << character.Name << " while embarking  " << quest[4].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[4] == false && mission2[4] == 0) {
				addRewardToInventory(quest[4].reward);
				mission2[4] = 1;
			}
			character.EXP += 25;
			levelUp(character.EXP);
		}
		break;
	}

}


// Function for the quests of Rogue
void RogueQuests() {

	int choice;
	Quest quest[5];

	quest[0].name_description = "1.Thieves' Heist: Execute daring theft.";
	quest[1].name_description = "2.Shadow Guild Espionage : Infiltrate rival guild.";
	quest[2].name_description = "3.Assassin's Mark: Eliminate high-profile targets.";
	quest[3].name_description = "4.Black Market Smuggling : Transport contraband discreetly.";
	quest[4].name_description = "5.Mystic Relic Retrieval : Secure mystical artifact.";

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
		cout << "Choose a Quest you want to embark on:" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "{" << quest[i].name_description << ", " << quest[i].EXP << ", " << quest[i].reward << "}" << endl;
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
		if (flag)
		{
			if (mission[0] == false && mission2[0] == 0) {
				addRewardToInventory(quest[0].reward);
				mission2[0] = 1;
			}
			character.EXP += 5;
			levelUp(character.EXP);
		}
		break;
	case 2:
		cout << endl << character.Name << " while embarking " << quest[1].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[1] == false && mission2[1] == 0) {
				addRewardToInventory(quest[1].reward);
				mission2[1] = 1;
			}
			character.EXP += 10;
			levelUp(character.EXP);
		}
		break;
	case 3:
		cout << endl << character.Name << " while embarking " << quest[2].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[2] == false && mission2[2] == 0) {
				addRewardToInventory(quest[2].reward);
				mission2[2] = 1;
			}
			character.EXP += 15;
			levelUp(character.EXP);
		}
		break;
	case 4:
		cout << endl << character.Name << " while embarking " << quest[3].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[3] == false && mission2[3] == 0) {
				addRewardToInventory(quest[3].reward);
				mission2[3] = 1;
			}
			character.EXP += 20;
			levelUp(character.EXP);
		}
		break;
	case 5:
		cout << endl << character.Name << " while embarking  " << quest[4].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[4] == false && mission2[4] == 0) {
				addRewardToInventory(quest[4].reward);
				mission2[4] = 1;
			}
			character.EXP += 25;
			levelUp(character.EXP);
		}
		break;
	}

}

// Function for the quests of Mage
void MageQuests() {
	int choice;
	Quest quest[5];

	quest[0].name_description = "1.Arcane Library Restoration : Recover ancient knowledge.";
	quest[1].name_description = "2.Elemental Balance : Restore elemental harmony.";
	quest[2].name_description = "3.Astral Beacon Rekindling : Reignite celestial beacons.";
	quest[3].name_description = "4.Spellcaster's Trial: Master magical labyrinth.";
	quest[4].name_description = "5.Ethereal Nexus Connection : Forge ethereal alliances.";

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
		cout << "Choose a Quest you want to embark on:" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "{" << quest[i].name_description << ", " << quest[i].EXP << ", " << quest[i].reward << "}" << endl;
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
		if (flag)
		{
			if (mission[0] == false && mission2[0] == 0) {
				addRewardToInventory(quest[0].reward);
				mission2[0] = 1;
			}
			character.EXP += 5;
			levelUp(character.EXP);

		}
		break;
	case 2:
		cout << endl << character.Name << " while embarking " << quest[1].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[1] == false && mission2[1] == 0) {
				addRewardToInventory(quest[1].reward);
				mission2[1] = 1;
			}
			character.EXP += 10;
			levelUp(character.EXP);

		}
		break;
	case 3:
		cout << endl << character.Name << " while embarking " << quest[2].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[2] == false && mission2[2] == 0)
			{
				addRewardToInventory(quest[2].reward);
				mission2[2] = 1;
			}
			character.EXP += 15;
			levelUp(character.EXP);
		}
		break;
	case 4:
		cout << endl << character.Name << " while embarking " << quest[3].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[3] == false && mission[3] == 0)
			{
				addRewardToInventory(quest[3].reward);
				mission[3] = 1;
			}
			character.EXP += 20;
			levelUp(character.EXP);
		}
		break;
	case 5:
		cout << endl << character.Name << " while embarking  " << quest[4].name_description << endl;
		cout << "\t   A wild " << randomWord << " appeared:" << endl;
		if (flag)
		{
			if (mission[4] == false && mission[4] == 0)
			{
				addRewardToInventory(quest[4].reward);
				mission[4] = 1;
			}
			character.EXP += 25;
			levelUp(character.EXP);
		}
		break;
	}
}

//Function for getting mythical creatures
string getRandomWord() {
	char words[][20] = { "DRAGON", "DRAKULLA", "ANACONDA", "SHADOW", "GODZILLA", "DARKFIRE", "NETHERWING", "GHOST", "TIGER" };

	int numWords = sizeof(words) / sizeof(words[0]);

	srand((time(0)));
	int index = rand() % numWords;

	return words[index];
}


// Function for selecting difficulty level
string difficultyLevel() {
	string difficulty;
	cout << "Choose your difficulty Level (Easy, Medium, Hard):";
	cin.clear();
	cin.ignore();
	getline(cin, difficulty);
	while (!isValiddifficulty(difficulty)) {
		cout << "Enter Valid Input: ";
		cin >> difficulty;
	}
	cin.ignore(1000, '\n');
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

// Function if user chooses hard level
void Hardbattle() {
	srand(time(0));
	int randomWord_health;
	string randomWord = getRandomWord();
	int answer;


	if (character.level > 5) {
		cout << "\nPress 1 to play Boss level and 0 to exit:";
		cin >> answer;
		if (answer == 1)
		{
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
		randomWord_health = baseHealth + (character.level * 10);
	}

	do {
		int a = rand() % 10;
		int b = rand() % 50;
		if (a == 0) {
			cout << randomWord << " survived " << character.Name << "'s attack." << endl;
		}
		else {
			cout << character.Name << " attacked " << randomWord << " for " << a << " damage." << endl;
		}
		randomWord_health = randomWord_health - a;
		character.score = character.score + a;

		if (randomWord_health <= 0) {
			cout << character.Name << " defeated " << randomWord;
			character.Health = 100;
			character.EXP += 20;
			flag = true;
			break;
		}

		if (b == 0) {
			cout << character.Name << " survived " << randomWord << "'s attack." << endl;
		}
		else {
			cout << randomWord << " attacked " << character.Name << " for " << b << " damage." << endl;
		}
		character.Health = character.Health - b;
		character.score = character.score - b;

		if (character.score < 0) {
			character.score = 0;
		}

		if (character.Health <= 0) {
			cout << randomWord << " defeated " << character.Name;
			flag = false;
			character.Health = 0;
			cout << "\n\nYOU HAVE LOST.\n\n";
			displayCharacter();
			cout << "\n\n";
			endingProgram(major_difficulty);

			if (character.EXP < 0) {
				character.EXP = 0;
			}
			break;
		}

	} while (character.Health > 0 || randomWord_health > 0);

	if (maxscore3 <= character.score)
		maxscore3 = character.score;
	WriteHighScore3(maxscore3);
}




// Function if the user chooses medium level
void Mediumbattle() {
	srand(time(0));
	int randomWord_health;
	string randomWord = getRandomWord();
	int answer;


	if (character.level > 5) {
		cout << "\nPress 1 to play boss level & 0 to exit:";
		cin >> answer;
		if (answer == 1)
		{
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
		randomWord_health = baseHealth + (character.level * 10);
	}

	do {
		int a = rand() % 10 + 20;
		int b = rand() % 30;
		if (a == 0) {
			cout << randomWord << " survived " << character.Name << "'s attack." << endl;
		}
		else {
			cout << character.Name << " attacked " << randomWord << " for " << a << " damage." << endl;
		}
		randomWord_health = randomWord_health - a;
		character.score = character.score + a;

		if (randomWord_health <= 0) {
			cout << character.Name << " defeated " << randomWord;
			character.Health = 100;
			character.EXP += 10;
			flag = true;
			break;
		}

		if (b == 0) {
			cout << character.Name << " survived " << randomWord << "'s attack." << endl;
		}
		else {
			cout << randomWord << " attacked " << character.Name << " for " << b << " damage." << endl;
		}
		character.Health = character.Health - b;
		character.score = character.score - b;

		if (character.score < 0) {
			character.score = 0;
		}

		if (character.Health <= 0) {
			cout << randomWord << " defeated " << character.Name;
			flag = false;
			character.Health = 0;
			cout << "\n\nYOU HAVE LOST.\n\n";
			displayCharacter();
			cout << "\n\n";
			endingProgram(major_difficulty);

			if (character.EXP < 0) {
				character.EXP = 0;
			}
			break;
		}

	} while (character.Health > 0 || randomWord_health > 0);

	if (maxscore2 <= character.score)
		maxscore2 = character.score;
	WriteHighScore2(maxscore2);
}


// Function if the user chooses easy level
void Easybattle() {
	srand(time(0));
	int randomWord_health;
	string randomWord = getRandomWord();
	int answer;


	if (character.level > 5) {
		cout << "\nPress 1 to play level & 0 to exit:";
		cin >> answer;
		if (answer == 1)
		{
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
		randomWord_health = baseHealth + (character.level * 10);
	}

	do {
		int a = rand() % 50;
		int b = rand() % 10;
		if (a == 0) {
			cout << randomWord << " survived " << character.Name << "'s attack." << endl;
		}
		else {
			cout << character.Name << " attacked " << randomWord << " for " << a << " damage." << endl;
		}
		randomWord_health = randomWord_health - a;
		character.score = character.score + a;

		if (randomWord_health <= 0) {
			cout << character.Name << " defeated " << randomWord;
			character.Health = 100;
			character.EXP += 5;
			flag = true;
			break;
		}

		if (b == 0) {
			cout << character.Name << " survived " << randomWord << "'s attack." << endl;
		}
		else {
			cout << randomWord << " attacked " << character.Name << " for " << b << " damage." << endl;
		}
		character.Health = character.Health - b;
		character.score = character.score - b;

		if (character.score < 0) {
			character.score = 0;
		}

		if (character.Health <= 0) {
			cout << randomWord << " defeated " << character.Name;
			flag = false;
			character.Health = 0;
			clearScreen();
			cout << "\n\nYOU HAVE LOST\n\n";
			displayCharacter();
			cout << "\n\n";
			endingProgram(major_difficulty);
			break;

			if (character.EXP < 0) {
				character.EXP = 0;
			}
			break;
		}

	} while (character.Health > 0 || randomWord_health > 0);

	if (maxscore <= character.score)
		maxscore = character.score;
	WriteHighScore(maxscore);
}


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

void Bosslevel(int x) {
	srand(time(0));
	int m, n;

	if (x > 5) {
		cout << "YOU HAVE REACHED BOSS LEVEL." << endl << endl;
		int randomWord_health = 500;
		do {
			int m = rand() % 30;
			int n = rand() % 10;
			if (m == 0) {
				cout << "BOSS" << " survived " << character.Name << "'s attack." << endl;
			}
			else {
				cout << character.Name << " attacked " << "BOSS" << " for " << m << " damage." << endl;
			}
			randomWord_health = randomWord_health - m;
			character.score = character.score + m;


			if (randomWord_health <= 0) {
				cout << character.Name << " defeated " << "BOSS" << endl << endl;
				cout << "You Won.";
				break;
			}

			if (n == 0) {
				cout << character.Name << " survived " << "BOSS" << "'s attack." << endl;
			}

			else {
				cout << "BOSS" << " attacked " << character.Name << " for " << n << " damage." << endl;
			}
			character.Health = character.Health - n;
			character.score = character.score - n;

			if (character.score < 0) {
				character.score = 0;
			}

			if (character.Health <= 0) {
				cout << "BOSS" << " defeated " << character.Name;
				flag = false;
				displayCharacter();
				cout << "\n\n";
				endingProgram(major_difficulty);
				if (character.Health < 0)
					character.Health = 0;

				if (character.EXP < 0) {
					character.EXP = 0;
				}
				break;
			}


		} while (character.Health > 0 || randomWord_health > 0);

		if (maxscore <= character.score)
			maxscore = character.score;
		WriteHighScore(maxscore);

	}
}

void addRewardToInventory(const string& reward) {
	for (int i = 0; i < 8; ++i) {
		if (inventory[i].empty()) {
			inventory[i] = reward;
			break;  // Exit the loop after adding the reward
		}
	}
}

void displayInventory() {
	cout << "Inventory Contents:" << endl;
	bool isEmpty = true;

	for (int i = 0; i < 8; ++i) {
		if (!inventory[i].empty()) {
			cout << "Slot " << i + 1 << ": " << inventory[i] << endl;
			isEmpty = false;
		}
	}

	if (isEmpty) {
		cout << "Inventory is empty." << endl;
	}
}


void Showquestsandbattle(string p) {
	int c;
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

		if (p == "Easy" || p == "easy") {
			Easybattle();
		}
		else if (p == "Medium" || p == "medium") {
			Mediumbattle();
		}
		else if (p == "Hard" || p == "hard") {
			Hardbattle();
		}

		cout << "\nPress 0 to Exit:";
		cin >> c;

		if (c == 0) {
			clearScreen();
			endingProgram(major_difficulty);
		}

	} while (c != 0);

	displayCharacter();
}

void Menu() {
	cout << "\tMAIN MENU\n";
	cout << "1. Start Game.\n";
	cout << "2. High Scores.\n";
	cout << "3. Difficulty.\n";
	cout << "4. Inventory.\n";
	cout << "4. Exit.\n";
	cout << "Enter your choice (1-4): ";
}

void endingProgram(string difficulty) {

	int take2;
	cout << "\n\n1. Play Again.\n";
	cout << "2. High Scores.\n";
	cout << "3. Inventory.\n";
	cout << "4. Exit.\n";
	cout << "Enter your choice (1-4): ";
	cin >> take2;
	switch (take2) {
	case 1:
		Showquestsandbattle(difficulty);
		break;
	case 2:
		showHighscore();
		break;
	case 3:
		displayInventory();
		break;
	case 4:
		exit(0);
		break;
	default:
		exit(0);
	}
}


void Gamesetup() {
	int take;
	string difficulty = "easy"; // Default difficulty
	Menu();
	do {
		cin >> take;

		switch (take) {
		case 1:
			clearScreen();
			Showquestsandbattle(difficulty); // Pass the selected difficulty
			break;
		case 2:
			showHighscore();
			endingProgram(difficulty);
			break;
		case 3:
			clearScreen();
			difficulty = difficultyLevel(); // Set the difficulty
			major_difficulty = difficulty;
			cout << "\n\n";
			break;
		case 4:
			clearScreen();
			displayInventory();
			cout << "\n\n";
			break;
		case 5:
			cout << "Game Over!";
			exit(0);
			break;
		default:
			cout << "Invalid Input";
			break;
		}
	} while (take != 4);
	endingProgram(difficulty);
}

int main() {
	Gamesetup();
	return 0;
}