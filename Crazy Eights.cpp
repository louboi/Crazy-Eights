// Include any required libraries
#include <iostream> // Used for input/ouptut operations
#include <vector> // Used for lists

// Import the templates that will be used
#include "template/Card.h"
#include "template/Deck.h"
#include "template/Player.h"

using namespace std;

//Blocks used for testing only, copy-paste where needed
//
//Player Names:
//	cout << Player1.getName() << endl;
//	cout << Player2.getName() << endl;
//	cout << Player3.getName() << endl;
//	cout << Player4.getName() << endl;
//	cout << Player5.getName() << endl;
//	cout << Player6.getName() << endl;
//	cout << Player7.getName() << endl;
//	cout << Player8.getName() << endl;
//	cout << Player9.getName() << endl;
//	cout << Player10.getName() << endl;

void Welcome_Message() {
	system("cls");
	cout << "Welcome to Crazy Eights!" << endl;
	cout << endl;
	cout << "Rules:" << endl;
	cout << "1. Each player starts with 5 cards." << endl;
	cout << "2. A first card is placed at the start of the game." << endl;
	cout << "3. Players have to place a card matching the rank or suit of the card in play." << endl;
	cout << "4. If they cannot, they draw until they can place one, and then do so." << endl;
	cout << "5. A player wins when they run out of cards." << endl;
	cout << endl;
}

void Player_Creation(){
	// Create 10 player objects
	Player Player1;
	Player Player2;
	Player Player3;
	Player Player4;
	Player Player5;
	Player Player6;
	Player Player7;
	Player Player8;
	Player Player9;
	Player Player10;

	// Initialise the variables used
	string Player_Name;
	int Player_Number;

	// Get the number of players
	cout << "How many players do you want? (1-10): ";
	cin >> Player_Number;
	
	// Create a vector for storing names called Player_Names
	vector<string> Player_Names = {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"};

	// Loop for the number of players wanted, populating their names
	for (int i = 0; i < Player_Number; i++) {
		cout << "What is your name? ";
		cin >> Player_Name;
		Player_Names.insert(Player_Names.begin() + i, Player_Name);
	}

	// Print the names in the Player_Names vector 
	for (int i = 0; i < Player_Names.size(); i++) {
		cout << "Player " << i + 1 << ": " << Player_Names[i] << endl;
	}

	// Set the player names
	Player1.setName(Player_Names[0]);
	Player2.setName(Player_Names[1]);
	Player3.setName(Player_Names[2]);
	Player4.setName(Player_Names[3]);
	Player5.setName(Player_Names[4]);
	Player6.setName(Player_Names[5]);
	Player7.setName(Player_Names[6]);
	Player8.setName(Player_Names[7]);
	Player9.setName(Player_Names[8]);
	Player10.setName(Player_Names[9]);
}

int main()
{
	Deck Deck1 = Deck(); // Create the deck object - Deck1 - will start orderd

	Deck1.shuffle(); // Shuffle the deck

	Welcome_Message();
	Player_Creation();
}