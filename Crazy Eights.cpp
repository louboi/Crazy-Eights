// Used for input/ouptut operations
#include <iostream>

// Import the templates that will be used
#include "template/Card.h"
#include "template/Deck.h"
#include "template/Player.h"

/*
Player creation loop:

1. Get player name
2. Create player object called the player name - Can't do that
	- Create objects for 10 players
	- Delete unused players/only play with the number of players they wanted
3. Set the player object name
4. Enter next player creation loop
4.1. Repeat steps 1,2,3
4.2. Ask if they want to add a new player
4.3. If yes, loop again
4.4. If no, exit loop
5. Print the list of players
*/

std::string Player_Creation()
{
	std::string Player_Name;
	//std::string Player; // Initialise the player variable

	//// Get the player name
	//std::cout << "What is your name? ";
	//std::cin >> Player;

	//// Ouput the player name
	//std::cout << "Player name is: " << Player << endl;

	// Create a player object with the player name

	// Create each individual player objects labelled Player1 to Player10
	// Edit the number of players that is passed when run
	// Set player name to null
	// Create the 10 player objects
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

	// Rename each player object
	std::cout << "What is your name? ";
	std::cin >> Player_Name;
	Player1.setName(Player_Name);

	return "Pass";
}

int main()
{
	Deck Deck1 = Deck(); // Create the deck object - Deck1 - will start orderd

	Deck1.shuffle(); // Shuffle the deck

	Player_Creation();
}