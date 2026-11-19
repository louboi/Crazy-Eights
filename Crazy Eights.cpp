// Include any required libraries
#include <iostream> // Used for input/ouptut operations
#include <vector> // Used for lists
#include <map>

// Import the templates that will be used
#include "template/Card.h"
#include "template/Deck.h"
#include "template/Player.h"

using namespace std;

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

/*
Print the vector passed
\param vect Must be a string vector
*/
void Print_Vect(vector<string> vect) {
	for (auto i : vect) {
		cout << i << " ";
	}
}

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

/*
Create the player names vecotr and set the names
\param Player_Names A Predefined vector string filled with NULL
*/
void Player_Creation(vector<string>& Player_Names){
	// Initialise the variables used
	string Player_Name;
	int Player_Number;

	// Get the number of players
	cout << "How many players do you want? (1-10): ";
	cin >> Player_Number;
	
	// Loop for the number of players wanted, populating their names
	for (int i = 0; i < Player_Number; i++) {
		cout << "Player " << i + 1 << " name: ";
		cin >> Player_Name;
		Player_Names.insert(Player_Names.begin() + i, Player_Name);
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

/*
Deal 5 cards to each player
\param Draw The deck used only for the initial disribution of cards
*/
void deal(Deck& Draw, Player& Player) {
	Player.addCard(Draw.getTopCard());
}


bool Game_Loop(Player& Current_Player, Deck& Reserve, Deck& Discard) {
	bool Finished = false;
	bool Can_Play = false;
	bool winner = false;
	int choice;

	while (Finished == false) {
		system("cls");
		cout << "---------- " << Current_Player.getName() << " ----------" << endl;
		for (int i = 0; i < Current_Player.getHandSize(); i++) {
			cout << i << ": " << Current_Player.getHand()[i].toString() << endl;
		}
		cout << endl;
		cout << endl << "Current Card: " << Discard.peekTopCard().toString() << endl;

		for (int i = 0; i < Current_Player.getHandSize(); i++) {
			if (Current_Player.peekCard(i).getRank() == Discard.peekTopCard().getRank() || Current_Player.peekCard(i).getSuit().compare(Discard.peekTopCard().getSuit()) == 0) {
				Can_Play = true;
			}
		}

		if (Can_Play == true) {
			cout << "What card do you want to play? ";
			cin >> choice;
			if (Current_Player.peekCard(choice).getRank() == Discard.peekTopCard().getRank() || Current_Player.peekCard(choice).getSuit().compare(Discard.peekTopCard().getSuit()) == 0) {
				Discard.addCard(Current_Player.getCard(choice));
				Finished = true;
			}
			else {
				cout << "Invalid Card" << endl;
			}
		}
		else {
			while (Can_Play == false) {
				Current_Player.addCard(Reserve.getTopCard());
				for (int i = 0; i < Current_Player.getHandSize(); i++) {
					if (Current_Player.peekCard(i).getRank() == Discard.peekTopCard().getRank() || Current_Player.peekCard(i).getSuit().compare(Discard.peekTopCard().getSuit()) == 0) {
						Can_Play = true;
					}
				}
				if (Reserve.getSize() == 0) {
					Finished = true;
					winner = true;
				}
			}
		}
	}

	if (Current_Player.getHandSize() == 0) {
		winner = true;
	}

	return winner;
}

int main()
{
	// Print a Welcome Message
	Welcome_Message();

	// Create the 3 required decks
	Deck Reserve = Deck(); // Deck players will draw from
	Deck Discard = Deck(); // The deck with the current card
	Deck Draw = Deck(); // Deck player hands are drawn from

	// Shuffle the decks
	Reserve.shuffle(); Draw.shuffle();
	
	// Set up the discard pile
	Discard.shuffle(); // shuffle the deck to randomise the first card
	Card Start_Card = Card(Discard.peekTopCard().getRank(), Discard.peekTopCard().getSuit());
	Discard.clear();
	Discard.addCard(Start_Card);


	// Create a vector of the player names
	vector<string> Player_Names = { "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL" };

	// Get the player names from the user and set them to the player objects
	Player_Creation(Player_Names);
	
	// Map numbers to the player objects 
	map<int, Player> Player_Map;
	Player_Map[1] = Player1; Player_Map[2] = Player2; Player_Map[3] = Player3; Player_Map[4] = Player4; Player_Map[5] = Player5; // Map player 1 -> 5
	Player_Map[6] = Player6; Player_Map[7] = Player7; Player_Map[8] = Player8; Player_Map[9] = Player9; Player_Map[10] = Player10; // Map player 6 -> 10

	// Deal 5 cards to each player
	for (int j = 0; j < 5; j++) {
		for (int i = 1; i < 11; i++) {
			deal(Draw, Player_Map[i]);
		}
	}

	// Loop over each player and let them play if they are not NULL
	// TODO add more than one turn for each player
	bool won = false;
	string winner;

	while (won == false) {
		for (int i = 1; i < 11; i++) {
			if (Player_Map[i].getName() != "NULL") {
				won = Game_Loop(Player_Map[i], Reserve, Discard);
				if (won == true) {
					winner = Player_Names[i - 1];
				}
			}
		}
	}
	system("cls");
	cout << "The winner is " << winner;
}